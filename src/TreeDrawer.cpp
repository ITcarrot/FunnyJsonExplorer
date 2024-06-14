#include "TreeDrawer.hpp"

TreeDrawer TreeDrawerObj(true);

TreeDrawer::TreeDrawer(bool RegisterDrawer)
{
    if(RegisterDrawer)
        AvailableDrawer["tree"] = this;
}

std::unique_ptr<Drawer> TreeDrawer::clone() const
{
    return std::make_unique<TreeDrawer>();
}

void TreeDrawer::DrawForward(PictureLine &PictureLineObj){}

void TreeDrawer::DrawBackward(PictureLine &PictureLineObj)
{
    HasParent.resize(PictureLineObj.IndentSize + 1, false);
    for(int i = 1; i < PictureLineObj.IndentSize; i++)
        PictureLineObj.LeftIndent += HasParent[i] ? "│  " : "   ";
    PictureLineObj.LeftIndent += HasParent[PictureLineObj.IndentSize] ? "├─" : "└─";
    HasParent[PictureLineObj.IndentSize] = true;
}
