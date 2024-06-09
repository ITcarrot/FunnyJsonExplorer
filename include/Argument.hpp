#pragma once
#include <string>
#include <vector>

class Argument{
    public:
    std::string JsonFile;
    std::string style;
    std::string IconFamilyConfFile;

    Argument(const int &argc, char **argv);
};