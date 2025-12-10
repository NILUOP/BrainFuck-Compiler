// ===============================================================================================================================================
// Brainfuck Compiler
// Author            : Nisarg Chaudhary
// GitHub Username   : NILUOP
// Email             : nisargkumar2005@gmail.com
// Date              : 2025-12-10
//
// Description : A simple Brainfuck interpreter written in C++.
//               - Uses a linear tape of bytes (default size: 30000).
//               - Supports an optional second argument to extend memory size.
//               - Reads Brainfuck source code from a .bf file.
// 
// Usage       : ./BrainFuck_compiler program.bf [memory_size]
// 
// ===============================================================================================================================================
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>

#define Default_Memory_Size 30000

using namespace std;


// initialization of Data_pointer and Memory_String
int Data_Pointer = 0;
vector<char> Memory_String(Default_Memory_Size, 0);


// for the execution / compilation of the loops
int Compile_BF_Loop(string Input_String, int Input_String_Pointer)
{
    // Temp_Input_String_Pointer stores the value of Input_String_Pointer before entering the loop i.e. location of '[' (or start of loop)
    int Temp_Input_String_Pointer = Input_String_Pointer;
    Input_String_Pointer++;
    // Temp_Data_Pointer stores the value of Data_Pointer before entering the loop
    int Temp_Data_Pointer = Data_Pointer;
    // Last_Iteration variable is used to ensure that we run full loop before exiting it
    // there is 3 values of Last_Iteration variable
    // Last_Iteration == 1 -> means we are currently on not on last iteration of the loop and shall run as normal
    // Last_Iteration == 2 -> means we are currently on last iteration of the loop
    // Last_Iteration == 0 -> means last iteration has been ended and we should stop the loop
    int Last_Iteration = 1;
    while((Memory_String[Temp_Data_Pointer] != 0 && Memory_String[Data_Pointer] != 0) || Last_Iteration != 0)
    {

        if(Data_Pointer < 0 || Data_Pointer >= Memory_String.size())
        {
            cerr << "Error: Memory pointer out of bounds!" << endl;
            exit(1);
        }
        // end of loop if input string have ']'
        if(Input_String[Input_String_Pointer] == ']')
        {
            if(Last_Iteration == 2)
            {
                // last iteration has ended so changing the Last_Iteration to 0
                Memory_String[Data_Pointer] = 0;
                Last_Iteration = 0;
            }
            // if memory block at Data_Pointer become become 0 at last part of loop it immediately breaks the loop
            if(Memory_String[Data_Pointer] == 0)
            {
                break;
            }
            // sends Input_String_Pointer back to '['
            Input_String_Pointer = Temp_Input_String_Pointer;
        }
        // incrementing current memory block by 1 if input string have '+'
        else if(Input_String[Input_String_Pointer] == '+')
        {
            Memory_String[Data_Pointer]++;
        }
        // decrementing current memory block by 1 if input string have '-'
        else if(Input_String[Input_String_Pointer] == '-')
        {
            Memory_String[Data_Pointer]--;
        }
        // incrementing Data_Pointer by 1 if input string have '>'
        else if(Input_String[Input_String_Pointer] == '>')
        {
            Data_Pointer++;
        }
        // decrementing Data_Pointer by 1 if input string have '<'
        else if(Input_String[Input_String_Pointer] == '<')
        {
            Data_Pointer--;
        }
        // print out current memory block
        else if(Input_String[Input_String_Pointer] == '.')
        {
            cout<<Memory_String[Data_Pointer];
        }
        // take input and store at current memory block
        else if(Input_String[Input_String_Pointer] == ',')
        {
            cin.get(Memory_String[Data_Pointer]);
        }
        // starting of a loop
        // calling Compile_BF_Loop
        else if(Input_String[Input_String_Pointer] == '[')
        {
            Input_String_Pointer = Compile_BF_Loop(Input_String, Input_String_Pointer);
        }

        if ((Memory_String[Temp_Data_Pointer] == 0 && Memory_String[Data_Pointer] != 0) && Last_Iteration != 0)
        {
            // Memory_String at Data_Pointer or at Temp_Data_Pointer has become 0
            // so changing the Last_Iteration to 2 to so that program should complete the last iteration of loop
            Last_Iteration = 2;                    
        }
        // incrementing Input_String_Pointer every time we complete one symbol
        Input_String_Pointer++;
    }

    // if the mid way execution of loop stops
    // then this while loop help us to reach end of the loop i.e. ']'
    while (Input_String[Input_String_Pointer] != ']')
    {
        Input_String_Pointer++;
    }

    return Input_String_Pointer;
}


// function for execution / compiling the BF code
void Compile_BF(string Input_String)
{
    int Input_String_Pointer = 0;
    while (Input_String_Pointer < Input_String.size())
    {
        if(Data_Pointer < 0 || Data_Pointer >= Memory_String.size())
        {
            cerr << "Error: Memory pointer out of bounds!" << endl;
            exit(1);
        }
        // incrementing current memory block by 1 if input string have '+'
        if (Input_String[Input_String_Pointer] == '+')
        {
            Memory_String[Data_Pointer]++;
        }
        // decrementing current memory block by 1 if input string have '-'
        else if (Input_String[Input_String_Pointer] == '-')
        {
            Memory_String[Data_Pointer]--;
        }
        // incrementing Data_Pointer by 1 if input string have '>'
        else if (Input_String[Input_String_Pointer] == '>')
        {
            Data_Pointer++;
        }
        // decrementing Data_Pointer by 1 if input string have '<'
        else if (Input_String[Input_String_Pointer] == '<')
        {
            Data_Pointer--;
        }
        // print out current memory block
        else if (Input_String[Input_String_Pointer] == '.')
        {
            cout << Memory_String[Data_Pointer];
        }
        // take input and store at current memory block
        else if (Input_String[Input_String_Pointer] == ',')
        {
            cin.get(Memory_String[Data_Pointer]);
        }
        // starting of a loop
        // calling Compile_BF_Loop
        else if (Input_String[Input_String_Pointer] == '[')
        {
            Input_String_Pointer = Compile_BF_Loop(Input_String, Input_String_Pointer);
        }
        // incrementing Input_String_Pointer every time we complete one symbol
        Input_String_Pointer++;
    }
}

int main(int argc, char* argv[])
{
    
    
    int Additional_Memory_String_Size;
    if (argc == 1)
    {
        cerr << "too few arguments" << endl;
        cerr << "give .bf file as input" << endl;
        exit(1);
    }
    else if(argc > 2)
    {
        // adding extra space as per user input
        Additional_Memory_String_Size = max(0, atoi(argv[2]) - Default_Memory_Size);
        vector<char> Extra_Memory_String(Additional_Memory_String_Size);
        Memory_String.insert(Memory_String.end(), Extra_Memory_String.begin(), Extra_Memory_String.end());
    }
    
    ifstream  FIN(argv[1]);
    string Input_String;
    // reading input .bf file and converting it into string
    if (FIN.is_open())
    {
        string Temp_Input_String;
        while(getline(FIN, Temp_Input_String))
        {
            Input_String += Temp_Input_String;
        }
        FIN.close();
    }
    else
    {
        cerr << argv[1] << " - file not found!!" << endl;
        exit(1);
    }

    // calling Compile_BF function for execution
    Compile_BF(Input_String);
    return 0;
}
