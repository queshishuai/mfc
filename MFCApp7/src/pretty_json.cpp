#include "../inc/pretty_json.h"
#include "../inc/reflection.h"
using namespace std;

/*pretty json format
@chenxin
@2024年3月12日
*/

void pretty_json(std::string &str)
{
    int indentation_length = 2;
    int offset = 0;
    std::string indent;
    for (size_t i = 0; i < str.size() - 1; ++i)
    {
        cout << str[i];
        switch (str[i])
        {
        case '{':
        case '[':
            offset = indentation_length;
            cout << '\n';
            indent.append(offset, ' ');
            cout << indent;
            break;
        case '}':
        case ']':
            if (',' == str[i + 1])
            {
            }
            else
            {
                offset = indentation_length;
                cout << '\n';
                indent.resize(indent.size() - offset);
                cout << indent;
            }
            break;
        case ',':
            cout << '\n';
            cout << indent;
            break;
        default:
            if ((']' == str[i + 1]) || ('}' == str[i + 1]))
            {
                offset = indentation_length;
                cout << '\n';
                indent.resize(indent.size() - offset);
                cout << indent;
            }
            break;
        }
    }
    cout << '}';
    return;
}
::std::string &operator<<(std::string &str, const char sub_str)
{
    str.push_back(sub_str);
    return str;
}
::std::string &operator<<(std::string &str, std::string const &sub_str)
{
    str.append(sub_str);
    return str;
}
void pretty_json_string(std::string &str, std::string &cout)
{
    int indentation_length = 2;
    int offset = 0;
    std::string indent;
    bool flag = 0;//左括号中是数字，不回车，[0,不回车;1,回车]
    for (size_t i = 0; i < str.size() - 1; ++i)
    {
        cout << str[i];
        switch (str[i])
        {
        case '{':
            offset = indentation_length;
            cout << '\n';
            indent.append(offset, ' ');
            cout << indent;
            break;
        case '[':
            if (('0' <= str[i+1]) && (str[i+1] <= '9'))
            {
                flag = 1;
            }
            else
            {
                offset = indentation_length;
                cout << '\n';
                indent.append(offset, ' ');
                cout << indent;
            }
            break;
        case '}':
            if (',' == str[i + 1])
            {
            }
            else
            {
                offset = indentation_length;
                cout << '\n';
                indent.resize(indent.size() - offset);
                cout << indent;
            }
            break;
        case ']':
            if(('0' <= str[i-1]) && (str[i-1] <= '9'))
            {
                flag = 0;
            }
            if (',' == str[i + 1])
            {
            }
            else
            {
                offset = indentation_length;
                cout << '\n';
                indent.resize(indent.size() - offset);
                cout << indent;
            }
            break;
        case ',':
            if (0 == flag)
            {
                cout << '\n';
                cout << indent;
            }
            else
            {
            }
            break;
        default:
            if (((']' == str[i + 1])&&(('0'>str[i]) || (str[i]>'9'))) || ('}' == str[i + 1]))
            {
                offset = indentation_length;
                cout << '\n';
                indent.resize(indent.size() - offset);
                cout << indent;
            }
            break;
        }
    }
    cout << '}';
    cout << '\n';
    return;
}

