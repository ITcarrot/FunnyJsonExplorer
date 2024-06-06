#pragma once
#include <string>
#include <vector>

class Argument{
    public:
    std::string json_file;
    std::string style;
    std::string icon_family;

    Argument(const int &argc, char **argv);
};