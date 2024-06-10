#include "RectPicture.hpp"

void RectPicture::print(const IconFamily &icon) const
{
    for(auto &RectLineObj: PictureLines)
        printf("%s%s%s%s\n", RectLineObj->LeftIndent.c_str(), icon[RectLineObj->type].c_str(),
            RectLineObj->content.c_str(), RectLineObj->RightIndent.c_str());
}
