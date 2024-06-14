#include "Argument.hpp"
#include "IconFamily.hpp"

int main(int argc, char **argv)
{
    Argument arg(argc, argv);

    IconFamily icon(arg.IconFamilyConfFile);

    return 0;
}