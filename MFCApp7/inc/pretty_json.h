#pragma once
#include <iostream>
#include <string>
using namespace std;

/*pretty json format
@chenxin
@2024年3月12日
*/

void pretty_json(std::string &str);

::std::string &operator<<(std::string &str, const char sub_str);

::std::string &operator<<(std::string &str, std::string const &sub_str);

void pretty_json_string(std::string &str, std::string &cout);
