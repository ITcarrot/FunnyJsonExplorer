#include "RectDrawer.hpp"
#include "RectPicture.hpp"

RectDrawer RectDrawerObj;

RectDrawer::RectDrawer()
{
    AvailableDrawer["rectangle"] = this;
}

void RectDrawer::Draw(const json &JsonObj)
{
    PictureObj = std::make_unique<RectPicture>();
    DrawLine(JsonObj);
    DrawRight();
    DrawUp();
    DrawDown();
}

std::unique_ptr<Picture> RectDrawer::GetPicture()
{
    return std::move(PictureObj);
}

void RectDrawer::DrawLine(const json& JsonObj, const std::string& LeftIndent)
{
    if(JsonObj.is_object())
        for(auto it = JsonObj.begin(); it != JsonObj.end(); ++it){
            auto RectLineObj = std::make_unique<RectPicture::RectLine>();
            RectLineObj->LeftIndent = LeftIndent + "├─";
            RectLineObj->content = it.key();
            if(it->is_object() || it->is_array()){
                RectLineObj->type = InternalIcon;
                PictureObj->PictureLines.push_back(std::move(RectLineObj));
                DrawLine(*it, LeftIndent + "│  ");
            }else{
                RectLineObj->type = LeafIcon;
                if(!it->is_null())
                    RectLineObj->content += ": " + it->dump();
                PictureObj->PictureLines.push_back(std::move(RectLineObj));
            }
        }

    else if(JsonObj.is_array())
        for(const auto &element: JsonObj)
            if(element.is_object() || element.is_array())
                DrawLine(element, LeftIndent + "│  ");
            else
                DrawLine(element, LeftIndent);

    else{
        auto RectLineObj = std::make_unique<RectPicture::RectLine>();
        RectLineObj->LeftIndent = LeftIndent + "├─";
        RectLineObj->content = JsonObj.dump();
        RectLineObj->type = LeafIcon;
        PictureObj->PictureLines.push_back(std::move(RectLineObj));
    }
}

void RectDrawer::DrawRight()
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

void RectDrawer::DrawUp()
{
    auto &FirstLine = *PictureObj->PictureLines.begin();
    FirstLine->LeftIndent = "┌" + FirstLine->LeftIndent.substr(3);
    FirstLine->RightIndent = FirstLine->RightIndent.substr(0, FirstLine->RightIndent.size() - 3) + "┐";
}

void RectDrawer::DrawDown()
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
