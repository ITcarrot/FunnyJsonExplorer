#include "TreePicture.hpp"

void TreePicture::print(const IconFamily &icon) const
{
    for(auto &TreeLineObj: PictureLines)
        printf("%s%s%s\n", TreeLineObj->LeftIndent.c_str(), icon[TreeLineObj->type].c_str(),
            TreeLineObj->content.c_str());
}
