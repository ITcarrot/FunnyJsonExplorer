#include "RectDrawer.hpp"

RectDrawer RectDrawerObj(true);

void RectDrawer::ReplaceSubstring(std::string &str, const std::string &from, const std::string &to) const
{
    std::string::size_type pos = 0;
    while((pos = str.find(from, pos)) != std::string::npos)
        str.replace(pos, from.length(), to);
}

RectDrawer::RectDrawer(bool RegisterDrawer)
{
    if(RegisterDrawer)
        AvailableDrawer["rectangle"] = this;
}

std::unique_ptr<Drawer> RectDrawer::clone() const
{
    return std::make_unique<RectDrawer>();
}

void RectDrawer::DrawForward(PictureLine &PictureLineObj)
{
    for(int i = 1; i < PictureLineObj.IndentSize; i++)
        PictureLineObj.LeftIndent += "│  ";
    PictureLineObj.LeftIndent += "├─";
    MaxLength = std::max(MaxLength, PictureLineObj.IndentSize * 3 + PictureLineObj.content.length());
    if(IsFirstLine){
        PictureLineObj.RightIndent = "<first line>";
        ReplaceSubstring(PictureLineObj.LeftIndent, " ", "─");
        ReplaceSubstring(PictureLineObj.LeftIndent, "│", "┬");
        ReplaceSubstring(PictureLineObj.LeftIndent, "├", "┬");
        PictureLineObj.LeftIndent = "┌" + PictureLineObj.LeftIndent.substr(3);
        IsFirstLine = false;
    }
}

void RectDrawer::DrawBackward(PictureLine &PictureLineObj)
{
    IsFirstLine = (PictureLineObj.RightIndent == "<first line>");
    PictureLineObj.RightIndent = " ";
    for(int i = PictureLineObj.IndentSize * 3 + PictureLineObj.content.length(); i < MaxLength; i++)
        PictureLineObj.RightIndent += "─";
    PictureLineObj.RightIndent += IsFirstLine ? "─┐" : "─┤";
    if(IsLastLine){
        ReplaceSubstring(PictureLineObj.LeftIndent, " ", "─");
        ReplaceSubstring(PictureLineObj.LeftIndent, "│", "┴");
        ReplaceSubstring(PictureLineObj.LeftIndent, "├", "┴");
        PictureLineObj.LeftIndent = "└" + PictureLineObj.LeftIndent.substr(3);
        PictureLineObj.RightIndent = PictureLineObj.RightIndent.substr(0, PictureLineObj.RightIndent.size() - 3) + "┘";
        IsLastLine = false;
    }
}
