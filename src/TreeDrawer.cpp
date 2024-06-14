#include "TreeDrawer.hpp"

TreeDrawer TreeDrawerObj;

TreeDrawer::TreeDrawer()
{
    AvailableDrawer["tree"] = this;
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
