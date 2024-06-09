#include "Picture.hpp"

void Picture::Print(const IconFamily &icon) const
{
    for(const auto &line: PictureLineObj)
        line->print(icon);
}
