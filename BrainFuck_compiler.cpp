#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int _Data_Pointer = 0;
vector<char> _Memory_String(30000);

void compilebf(string _Input_String)
{
    int _Input_String_Pointer = 0;
    while(_Input_String_Pointer < _Input_String.size())
    {
        if(_Input_String[_Input_String_Pointer] == '+')
        {
            _Memory_String[_Data_Pointer]++;
            cout<<_Memory_String[_Data_Pointer];
        }
        else if(_Input_String[_Input_String_Pointer] == '-')
        {
            _Memory_String[_Data_Pointer]--;
            cout<<_Memory_String[_Data_Pointer];
        }
        else if(_Input_String[_Input_String_Pointer] == '>')
        {
            _Data_Pointer++;
            cout<<_Data_Pointer;
        }
        else if(_Input_String[_Input_String_Pointer] == '<')
        {
            _Data_Pointer--;
            cout<<_Data_Pointer;
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
            while(_Memory_String[_Data_Pointer] != 0)
            {
                int _Number_of_brackets_remaining = 1;
                int _temp_pointer = _Input_String_Pointer;
                while(_Number_of_brackets_remaining > 0)
                {
                    _temp_pointer++;
                    cout<<_temp_pointer;
                    if (_Input_String[_temp_pointer] == ']')
                    {
                        _Number_of_brackets_remaining--;
                    }
                    else if (_Input_String[_temp_pointer] == '[')
                    {
                        _Number_of_brackets_remaining++;
                    }
                }
                string _Sub_Input_String = _Input_String.substr(_Input_String_Pointer+1,_Input_String_Pointer-_temp_pointer-1);
                cout<<_Sub_Input_String;
                compilebf(_Sub_Input_String);
                _Input_String_Pointer = _temp_pointer;
            }
        }
        _Input_String_Pointer++;
    }
}

int main()
{
    string _Input_String = "-[----->++<]>++.+.";
    compilebf(_Input_String);
    return 0;
}
