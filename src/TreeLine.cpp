#include "TreeLine.hpp"

void TreeLine::print(const IconFamily &icon) const
{
    printf("%s%s%s\n", LeftIndent.c_str(), icon[type].c_str(), content.c_str());
}
