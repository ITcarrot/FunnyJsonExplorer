#pragma once
#include <string>

class Argument{
    public:
    std::string JsonFile;
    std::string style;
    std::string IconFamilyConfFile;

    Argument(const int &argc, char **argv);
};