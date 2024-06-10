#include "RectDrawer.hpp"
#include "RectPicture.hpp"

RectDrawer RectDrawerObj;

RectDrawer::RectDrawer()
{
    AvailableDrawer["rectangle"] = this;
}

std::unique_ptr<Picture> RectDrawer::Draw(const json &JsonObj) const
{
    auto PictureObj = std::make_unique<RectPicture>();
    DrawLine(PictureObj, JsonObj);
    DrawRight(PictureObj);
    DrawUp(PictureObj);
    DrawDown(PictureObj);
    return PictureObj;
}

void RectDrawer::DrawLine(std::unique_ptr<RectPicture> &PictureObj, const json& JsonObj, const std::string& LeftIndent) const
{
    if(JsonObj.is_object())
        for(auto it = JsonObj.begin(); it != JsonObj.end(); ++it){
            auto RectLineObj = std::make_unique<RectPicture::RectLine>();
            RectLineObj->LeftIndent = LeftIndent + "├─";
            RectLineObj->content = it.key();
            if(it->is_object() || it->is_array()){
                PictureObj->PictureLines.push_back(std::move(RectLineObj));
                DrawLine(PictureObj, *it, LeftIndent + "│  ");
            }else{
                if(!it->is_null())
                    RectLineObj->content += ": " + it->dump();
                PictureObj->PictureLines.push_back(std::move(RectLineObj));
            }
        }

    else if(JsonObj.is_array())
        for(const auto &element: JsonObj)
            if(element.is_object() || element.is_array())
                DrawLine(PictureObj, element, LeftIndent + "│  ");
            else
                DrawLine(PictureObj, element, LeftIndent);

    else{
        auto RectLineObj = std::make_unique<RectPicture::RectLine>();
        RectLineObj->LeftIndent = LeftIndent + "├─";
        RectLineObj->content = JsonObj.dump();
        PictureObj->PictureLines.push_back(std::move(RectLineObj));
    }
}

void RectDrawer::DrawRight(std::unique_ptr<RectPicture> &PictureObj) const
{
    std::string::size_type MaxLength = 0;
    for(auto &RectLineObj: PictureObj->PictureLines)
        MaxLength = std::max(MaxLength, RectLineObj->LeftIndent.length() / 5 * 3 + RectLineObj->content.length());
    for(auto &RectLineObj: PictureObj->PictureLines){
        RectLineObj->RightIndent = " ";
        for(int i = RectLineObj->LeftIndent.length() / 5 * 3 + RectLineObj->content.length(); i < MaxLength; i++)
            RectLineObj->RightIndent += "─";
        RectLineObj->RightIndent += "─┤";
    }
}

void RectDrawer::DrawUp(std::unique_ptr<RectPicture> &PictureObj) const
{
    auto &FirstLine = *PictureObj->PictureLines.begin();
    FirstLine->LeftIndent = "┌" + FirstLine->LeftIndent.substr(3);
    FirstLine->RightIndent = FirstLine->RightIndent.substr(0, FirstLine->RightIndent.size() - 3) + "┐";
}

void RectDrawer::DrawDown(std::unique_ptr<RectPicture> &PictureObj) const
{
    auto ReplaceSubstring = [](std::string &str, const std::string &from, const std::string &to){
        std::string::size_type pos = 0;
        while((pos = str.find(from, pos)) != std::string::npos)
            str.replace(pos, from.length(), to);
    };

    auto &LastLine = *PictureObj->PictureLines.rbegin();
    ReplaceSubstring(LastLine->LeftIndent, " ", "─");
    ReplaceSubstring(LastLine->LeftIndent, "│", "┴");
    ReplaceSubstring(LastLine->LeftIndent, "├", "┴");
    LastLine->LeftIndent = "└" + LastLine->LeftIndent.substr(3);
    LastLine->RightIndent = LastLine->RightIndent.substr(0, LastLine->RightIndent.size() - 3) + "┘";
}
