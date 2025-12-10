// ===============================================================================================================================================






// ===============================================================================================================================================
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#define _Memory_String_Size 30000

using namespace std;


// initialization of _Data_pointer and _Memory_String
int _Data_Pointer = 0;
vector<char> _Memory_String;


// for the execution / compilation of the loops
int __Compile_BF_Loop(string _Input_String, int _Input_String_Pointer)
{
    // _temp_Input_String_Pointer stores the value of _Input_String_Pointer before entering the loop i.e. location of '[' (or start of loop)
    int _temp_Input_String_Pointer = _Input_String_Pointer;
    _Input_String_Pointer++;
    // _temp_Data_Pointer stores the value of _Data_Pointer before entering the loop
    int _temp_Data_Pointer = _Data_Pointer;
    // _Last_Iteration variable is used to ensure that we run full loop before exiting it
    // there is 3 values of _Last_Iteration variable
    // _Last_Iteration == 1 -> means we are currently on not on last iteration of the loop and shall run as normal
    // _Last_Iteration == 2 -> means we are currently on last iteration of the loop
    // _Last_Iteration == 0 -> means last iteration has been ended and we should stop the loop
    int _Last_Iteration = 1;
    while((_Memory_String[_temp_Data_Pointer] != 0 && _Memory_String[_Data_Pointer] != 0) || _Last_Iteration != 0)
    {
        // end of loop if input string have ']'
        if(_Input_String[_Input_String_Pointer] == ']')
        {
            if(_Last_Iteration == 2)
            {
                // last iteration has ended so changing the _Last_Iteration to 0
                _Memory_String[_Data_Pointer] = 0;
                _Last_Iteration = 0;
            }
            // if memory block at _Data_Pointer become become 0 at last part of loop it immediately breaks the loop
            if(_Memory_String[_Data_Pointer] == 0)
            {
                break;
            }
            // sends _Input_String_Pointer back to '['
            _Input_String_Pointer = _temp_Input_String_Pointer;
        }
        // incrementing current memory block by 1 if input string have '+'
        else if(_Input_String[_Input_String_Pointer] == '+')
        {
            _Memory_String[_Data_Pointer]++;
        }
        // decrementing current memory block by 1 if input string have '-'
        else if(_Input_String[_Input_String_Pointer] == '-')
        {
            _Memory_String[_Data_Pointer]--;
        }
        // incrementing _Data_Pointer by 1 if input string have '>'
        else if(_Input_String[_Input_String_Pointer] == '>')
        {
            _Data_Pointer++;
        }
        // decrementing _Data_Pointer by 1 if input string have '<'
        else if(_Input_String[_Input_String_Pointer] == '<')
        {
            _Data_Pointer--;
        }
        // print out current memory block
        else if(_Input_String[_Input_String_Pointer] == '.')
        {
            cout<<_Memory_String[_Data_Pointer];
        }
        // take input and store at current memory block
        else if(_Input_String[_Input_String_Pointer] == ',')
        {
            cin>>_Memory_String[_Data_Pointer];
        }
        // starting of a loop
        // calling __Compile_BF_Loop
        else if(_Input_String[_Input_String_Pointer] == '[')
        {
            _Input_String_Pointer = __Compile_BF_Loop(_Input_String, _Input_String_Pointer);
        }

        if ((_Memory_String[_temp_Data_Pointer] == 0 && _Memory_String[_Data_Pointer] != 0) && _Last_Iteration != 0)
        {
            // _Memory_String at _Data_Pointer or at _temp_Data_Pointer has become 0
            // so changing the _Last_Iteration to 2 to so that program should complete the last iteration of loop
            _Last_Iteration = 2;                    
        }
        // incrementing _Input_String_Pointer every time we complete one symbol
        _Input_String_Pointer++;
    }

    // if the mid way execution of loop stops
    // then this while loop help us to reach end of the loop i.e. ']'
    while (_Input_String[_Input_String_Pointer] != ']')
    {
        _Input_String_Pointer++;
    }

    return _Input_String_Pointer;
}


// function for execution / compiling the BF code
void __Compile_BF(string _Input_String)
{
    int _Input_String_Pointer = 0;
    while (_Input_String_Pointer < _Input_String.size())
    {
        // incrementing current memory block by 1 if input string have '+'
        if (_Input_String[_Input_String_Pointer] == '+')
        {
            _Memory_String[_Data_Pointer]++;
        }
        // decrementing current memory block by 1 if input string have '-'
        else if (_Input_String[_Input_String_Pointer] == '-')
        {
            _Memory_String[_Data_Pointer]--;
        }
        // incrementing _Data_Pointer by 1 if input string have '>'
        else if (_Input_String[_Input_String_Pointer] == '>')
        {
            _Data_Pointer++;
        }
        // decrementing _Data_Pointer by 1 if input string have '<'
        else if (_Input_String[_Input_String_Pointer] == '<')
        {
            _Data_Pointer--;
        }
        // print out current memory block
        else if (_Input_String[_Input_String_Pointer] == '.')
        {
            cout << _Memory_String[_Data_Pointer];
        }
        // take input and store at current memory block
        else if (_Input_String[_Input_String_Pointer] == ',')
        {
            cin >> _Memory_String[_Data_Pointer];
        }
        // starting of a loop
        // calling __Compile_BF_Loop
        else if (_Input_String[_Input_String_Pointer] == '[')
        {
            _Input_String_Pointer = __Compile_BF_Loop(_Input_String, _Input_String_Pointer);
        }
        // incrementing _Input_String_Pointer every time we complete one symbol
        _Input_String_Pointer++;
    }
}

int main(int argc, char* argv[])
{
    ifstream  _FIN(argv[1]);
    string _Input_String;
    int _Additional_Memory_String_Size;


    if (argc == 1)
    {
        cerr << "too few arguments" << endl;
        cerr << "give .bf file as input" << endl;
        exit(1);
    }
    else if(argc > 2)
    {
        // adding extra space as per user input
        _Additional_Memory_String_Size = max(_Memory_String_Size,(int)argv[2]-_Memory_String_Size);
        vector<char> _Extra_Memory_String(_Additional_Memory_String_Size);
        _Memory_String.insert(_Memory_String.end(), _Extra_Memory_String.begin(), _Extra_Memory_String.end());
    }
    
    // reading input .bf file and converting it into string
    if (_FIN.is_open())
    {
        string _temp_Input_String;
        while(getline(_FIN, _temp_Input_String))
        {
            _Input_String += _temp_Input_String;
        }
        _FIN.close();
    }
    else
    {
        cerr << argv[1] << " - file not found!!" << endl;
        exit(1);
    }

    // calling __Compile_BF function for execution
    __Compile_BF(_Input_String);
    return 0;
}
