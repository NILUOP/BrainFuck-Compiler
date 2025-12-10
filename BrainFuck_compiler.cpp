#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int _Data_Pointer = 0;
vector<char> _Memory_String(30000);

int compilebf_loop(string _Input_String, int _Input_String_Pointer)
{
    int _temp_Input_String_Pointer = _Input_String_Pointer;
    _Input_String_Pointer++;
    int _temp_Data_Pointer = _Data_Pointer;
    int _Last_Iteration = 1;
    while((_Memory_String[_temp_Data_Pointer] != 0 && _Memory_String[_Data_Pointer] != 0) || _Last_Iteration != 0)
    {
        if(_Input_String[_Input_String_Pointer] == ']')
        {
            if(_Last_Iteration == 2)
            {
                _Memory_String[_Data_Pointer] = 0;
                _Last_Iteration = 0;
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
        }
        else if(_Input_String[_Input_String_Pointer] == '-')
        {
            _Memory_String[_Data_Pointer]--;
        }
        else if(_Input_String[_Input_String_Pointer] == '>')
        {
            _Data_Pointer++;
        }
        else if(_Input_String[_Input_String_Pointer] == '<')
        {
            _Data_Pointer--;
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
            _Input_String_Pointer = compilebf_loop(_Input_String, _Input_String_Pointer);
        }

        if ((_Memory_String[_temp_Data_Pointer] == 0 && _Memory_String[_Data_Pointer] != 0) && _Last_Iteration != 0)
        {
            _Last_Iteration = 2;                    
        }
        _Input_String_Pointer++;
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
        }
        else if (_Input_String[_Input_String_Pointer] == '-')
        {
            _Memory_String[_Data_Pointer]--;
        }
        else if (_Input_String[_Input_String_Pointer] == '>')
        {
            _Data_Pointer++;
        }
        else if (_Input_String[_Input_String_Pointer] == '<')
        {
            _Data_Pointer--;
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
        }
        _Input_String_Pointer++;
    }
}

int main(int argc, char* argv[])
{
    ifstream  _FIN(argv[1]);
    string _Input_String;
    
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
        cerr << argv[1] << " - file not found!!" << std::endl;
    }

    // cout<<_Input_String;

    compilebf(_Input_String);
    return 0;
}
