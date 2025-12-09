#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int _Data_Pointer = 0;
vector<char> _Memory_String(30000);
// string _Memory_String(10,'\0');
// char _Memory_String[10] = {'\0'};

int compilebf_loop(string _Input_String, int _Input_String_Pointer)
{
    int _temp_Input_String_Pointer = _Input_String_Pointer;
    _Input_String_Pointer++;
    int _temp_Data_Pointer = _Data_Pointer;
    // int i = 0;
    int last = 1;
    // while(last != 0)
    while((_Memory_String[_temp_Data_Pointer] != 0 && _Memory_String[_Data_Pointer] != 0) || last != 0)
    {
        // cout<<"here";
        if(_Input_String[_Input_String_Pointer] == ']')
        {
            if(last == 2)
            {
                _Memory_String[_Data_Pointer] = 0;
                last = 0;
            }
            if(_Memory_String[_Data_Pointer] == 0)
            {
                break;
            }
            _Input_String_Pointer = _temp_Input_String_Pointer;
        }
        else if(_Input_String[_Input_String_Pointer] == '+')
        {
            _Memory_String[_Data_Pointer]++;
            // cout<<_Memory_String[_Data_Pointer];
        }
        else if(_Input_String[_Input_String_Pointer] == '-')
        {
            _Memory_String[_Data_Pointer]--;
            // cout<<_Memory_String[_Data_Pointer];
        }
        else if(_Input_String[_Input_String_Pointer] == '>')
        {
            _Data_Pointer++;
            // cout<<_Data_Pointer;
            // i++;
            // cout<<i;
        }
        else if(_Input_String[_Input_String_Pointer] == '<')
        {
            _Data_Pointer--;
            // cout<<_Data_Pointer;
            // i++;
            // cout<<i;
        }
        else if(_Input_String[_Input_String_Pointer] == '.')
        {
            cout<<_Memory_String[_Data_Pointer];
        }
        else if(_Input_String[_Input_String_Pointer] == ',')
        {
            cin>>_Memory_String[_Data_Pointer];
        }
        else if(_Input_String[_Input_String_Pointer] == '[')
        {
            // cin>>_Memory_String[_Data_Pointer];
            // cout<<"it was here once ";
            _Input_String_Pointer = compilebf_loop(_Input_String, _Input_String_Pointer);
        }
        // else if(_Input_String[_Input_String_Pointer] == ']')
        // {
        //     // cin>>_Memory_String[_Data_Pointer];
        //     if (last == 2)
        //     {
        //         // _Memory_String[_temp_Data_Pointer] = 0;
        //         last = 0;
        //     }
        // }

        if ((_Memory_String[_temp_Data_Pointer] == 0 && _Memory_String[_Data_Pointer] != 0) && last != 0)
        {
            last = 2;                    
        }
        _Input_String_Pointer++;
        // i++;
        // cout<<i;
        // cout<<_Input_String_Pointer;
    }
    while (_Input_String[_Input_String_Pointer] != ']')
    {
        _Input_String_Pointer++;
    }

    return _Input_String_Pointer;
}

void compilebf(string _Input_String)
{
    int _Input_String_Pointer = 0;
    while (_Input_String_Pointer < _Input_String.size())
    {
        if (_Input_String[_Input_String_Pointer] == '+')
        {
            _Memory_String[_Data_Pointer]++;
            // cout<<_Memory_String[_Data_Pointer];
        }
        else if (_Input_String[_Input_String_Pointer] == '-')
        {
            _Memory_String[_Data_Pointer]--;
            // cout<<_Memory_String[_Data_Pointer];
        }
        else if (_Input_String[_Input_String_Pointer] == '>')
        {
            _Data_Pointer++;
            // cout<<_Data_Pointer;
        }
        else if (_Input_String[_Input_String_Pointer] == '<')
        {
            _Data_Pointer--;
            // cout<<_Data_Pointer;
        }
        else if (_Input_String[_Input_String_Pointer] == '.')
        {
            cout << _Memory_String[_Data_Pointer];
        }
        else if (_Input_String[_Input_String_Pointer] == ',')
        {
            cin >> _Memory_String[_Data_Pointer];
        }
        else if (_Input_String[_Input_String_Pointer] == '[')
        {
            _Input_String_Pointer = compilebf_loop(_Input_String, _Input_String_Pointer);
            // cout<<"here";
            // int _temp_Input_String_Pointer = _Input_String_Pointer;
            // int _temp_Data_Pointer = _Data_Pointer;
            // // int i = 0;
            // int last = 1;
            // // while(last != 0)
            // while(_Memory_String[_temp_Data_Pointer] != 0 || last != 0)
            // {
            //     // cout<<"here";
            //     if(_Input_String[_Input_String_Pointer] == ']')
            //     {
            //         _Input_String_Pointer = _temp_Input_String_Pointer;
            //         if (last == 2)
            //         {
            //             _Memory_String[_temp_Data_Pointer] = 0;
            //             last = 0;
            //             // _Memory_String[_temp_Data_Pointer] = 0;
            //         }
            //     }
            //     else if(_Input_String[_Input_String_Pointer] == '+')
            //     {
            //         _Memory_String[_Data_Pointer]++;
            //         // cout<<_Memory_String[_Data_Pointer];
            //     }
            //     else if(_Input_String[_Input_String_Pointer] == '-')
            //     {
            //         _Memory_String[_Data_Pointer]--;
            //         // cout<<_Memory_String[_Data_Pointer];
            //     }
            //     else if(_Input_String[_Input_String_Pointer] == '>')
            //     {
            //         _Data_Pointer++;
            //         // cout<<_Data_Pointer;
            //         // i++;
            //         // cout<<i;
            //     }
            //     else if(_Input_String[_Input_String_Pointer] == '<')
            //     {
            //         _Data_Pointer--;
            //         // cout<<_Data_Pointer;
            //         // i++;
            //         // cout<<i;
            //     }
            //     else if(_Input_String[_Input_String_Pointer] == '.')
            //     {
            //         cout<<_Memory_String[_Data_Pointer];
            //     }
            //     else if(_Input_String[_Input_String_Pointer] == ',')
            //     {
            //         cin>>_Memory_String[_Data_Pointer];
            //     }
            //     // else if(_Input_String[_Input_String_Pointer] == ']')
            //     // {
            //     //     // cin>>_Memory_String[_Data_Pointer];
            //     //     if (last == 2)
            //     //     {
            //     //         // _Memory_String[_temp_Data_Pointer] = 0;
            //     //         last = 0;
            //     //     }
            //     // }

            //     if (_Memory_String[_temp_Data_Pointer] == 0 && last != 0)
            //     {
            //         last = 2;                    
            //     }
            //     _Input_String_Pointer++;
            //     // i++;
            //     // cout<<i;
            //     // cout<<_Input_String_Pointer;
            // }
            // while (_Input_String[_Input_String_Pointer] != ']')
            // {
            //     _Input_String_Pointer++;
            // }

            // while(_Memory_String[_Data_Pointer] != 0)
            // {
            //     int _Number_of_brackets_remaining = 1;
            //     int _temp_Input_String_Pointer = _Input_String_Pointer;
            //     while(_Number_of_brackets_remaining > 0)
            //     {
            //         _temp_Input_String_Pointer++;
            //         // cout<<_temp_Input_String_Pointer;
            //         if (_Input_String[_temp_Input_String_Pointer] == ']')
            //         {
            //             _Number_of_brackets_remaining--;
            //         }
            //         else if (_Input_String[_temp_Input_String_Pointer] == '[')
            //         {
            //             _Number_of_brackets_remaining++;
            //         }
            //     }
            //     string _Sub_Input_String = _Input_String.substr(_Input_String_Pointer+1,_Input_String_Pointer-_temp_Input_String_Pointer-1);
            //     // cout<<_Sub_Input_String;
            //     compilebf(_Sub_Input_String);
            //     _Input_String_Pointer = _temp_Input_String_Pointer;
            // }
        }
        _Input_String_Pointer++;
        // for(auto it : _Memory_String)
        // {
        //     cout<<it;
        // }
        // cout<<_Input_String_Pointer;
    }

    // for(auto it : _Memory_String)
    // {
    //     cout<<(int)it;
    // }
    // cout<<_Memory_String[0]<<endl;
    // cout<<_Memory_String[1]<<endl;
}

int main()
{
    // string _Input_String = "++++++++++[>+>+++>+++++++>++++++++++<<<<-]>>>++.>+.+++++++..+++.<<++.>+++++++++++++++.>.+++.------.--------.<<+.<.";
    // string _Input_String = "-[----->++<]>++.+.";
    // string _Input_String = ">+++++++++[<++++++++>-]<.>+++++++[<++++>-]<+.+++++++..+++.[-]>++++++++[<++++>-] <.>+++++++++++[<++++++++>-]<-.--------.+++.------.--------.[-]>++++++++[<++++>- ]<+.[-]++++++++++.";
    // string _Input_String = ">+++++++++[<++++++++>-]<.>+++++++[<++++>-]<+.+++++++..+++.[-]>++++++++[<++++>-] <.>+++++++++++[<++++++++>-]<-.--------.+++.------.--------.";
    // string _Input_String = ">+++++++++++[<++++++++>-]<-.--------.+++.------.--------.";
    // string _Input_String = ">,[>,]<[<]>[.>]";
    // string _Input_String = ">,>,>,>,>,>,[<]>[.>]";
    // string _Input_String = ">+++++++++[<++++++++>-]<.>+++++++[<++++>-]<+.+++++++..+++.>>>++++++++[<++++>-]<.>>>++++++++++[<+++++++++>-]<---.<<<<.+++.------.--------.>>+.>++++++++++.";
    // string _Input_String = ",>,>,>,>,>,<<<<<.>.>.>.>.>.";
    // string _Memory_String(10,'\0');
    // string _Input_String = "++++++++++[>+++++++>++++++++++<<-]>++.>+++++.";
    // string _Input_String = "++++++++++[>+++++++>++++++++++<<-]>++++.>+.";
    // string _Input_String = ">+++++++++[<++++++++>-]<.>+++++++[<++++>-]<+.+++++++..+++.[-]>++++++++[<++++>-]<.>+++++++++++[<++++++++>-]<-.--------.+++.------.--------.[-]>++++++++[<++++>- ]<+.[-]++++++++++.";
    // string _Input_String = ">+++++++++[<++++++++>-]<.>+++++++[<++++>-]<+.+++++++..+++.>>>++++++++[<++++>-]<.>>>++++++++++[<+++++++++>-]<---.<<<<.+++.------.--------.>>+.>++++++++++.";
    // string _Input_String = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
    // string _Input_String = "++++++>+++++++[<[>+>+<<-]>>[<<+>>-]>[<<+>>-]<->-<<-]>+.";
    // string _Input_String = "+++[>+++++<-]>>+<[>>++++>++>+++++>+++++>+>>+<++[++<]>---]>++++.>>>.+++++.>------.<--.+++++++++.>+.+.<<<<---.[>]<<.<<<.-------.>++++.<+++++.+.>-----.>+.<++++.>>++.>-----.<<<-----.+++++.-------.<--.<<<.>>>.<<+.>------.-..--.+++.-----<++.<--[>+<-]>>>>>--.--.<++++.>>-.<<<.>>>--.>.<<<<-----.>----.++++++++.----<+.+++++++++>>--.+.++<<<<.[>]<.>>,[>>+++[<+++++++>-]<[<[-[-<]]>>[>]<-]<[<+++++>-[<+++>-[<-->-[<+++>-[<++++[>[->>]<[>>]<<-]>[<+++>-[<--->-[<++++>-[<+++[>[-[-[-[->>]]]]<[>>]<<-]>[<+>-[<->-[<++>-[<[-]>-]]]]]]]]]]]]]<[    -[-[>+<-]>]    <[<<<<.>+++.+.+++.-------.>---.++.<.>-.++<<<<.[>]>>>>>>>>>]    <[[<]>++.--[>]>>>>>>>>]    <[<<++..-->>>>>>]    <[<<..>>>>>]    <[<<..-.+>>>>]    <[<<++..---.+>>>]    <[<<<.>>.>>>>>]    <[<<<<-----.+++++>.----.+++.+>---.<<<-.[>]>]    <[<<<<.-----.>++++.<++.+++>----.>---.<<<.-[>]]    <[<<<<<----.>>.<<.+++++.>>>+.++>.>>]    <.>]>,]<<<<<.<+.>++++.<----.>>---.<<<-.>>>+.>.>.[<]>++.[>]<.>";

    
    // string _Input_String = ">+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.>++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.>+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.>++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.>+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.>++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++.[<]>[.>]";

    compilebf(_Input_String);
    return 0;
}
// -[----->++<]>++++.+.
// ++++++++++[>+>+++>+++++++>++++++++++<<<<-]>>>++.>+.+++++++..+++.<<++.>+++++++++++++++.>.+++.------.--------.<<+.<.
// Hello world!
// >>+++++++[<++++>-]<.<
