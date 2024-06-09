#include "RectDrawer.hpp"
#include "RectLine.hpp"

RectDrawer RectDrawerObj;

RectDrawer::RectDrawer()
{
    AvailableDrawer["rectangle"] = this;
}

std::unique_ptr<Picture> RectDrawer::Draw(const json &JsonObj) const
{
    std::unique_ptr<Picture> PictureObj = std::make_unique<Picture>();
    DrawLine(PictureObj, JsonObj);
    return PictureObj;
}

void RectDrawer::DrawLine(std::unique_ptr<Picture> &PictureObj, const json& JsonObj, const std::string& LeftIndent) const
{
    for(auto it = JsonObj.begin(); it != JsonObj.end(); ++it){
        std::unique_ptr<RectLine> RectLineObj = std::make_unique<RectLine>();
        RectLineObj->LeftIndent = LeftIndent;
        RectLineObj->content = it.key();
        if(it->is_object()){
            PictureObj->PictureLineObj.push_back(std::move(RectLineObj));
            DrawLine(PictureObj, *it, LeftIndent + "  ");
        }else if(it->is_array()){
            PictureObj->PictureLineObj.push_back(std::move(RectLineObj));
            for(const auto& element : *it){
                if(element.is_object() || element.is_array()){
                    DrawLine(PictureObj, element, LeftIndent + "  ");
                } else{
                    RectLineObj = std::make_unique<RectLine>();
                    RectLineObj->LeftIndent = LeftIndent + " ";
                    RectLineObj->content = element.dump();
                    PictureObj->PictureLineObj.push_back(std::move(RectLineObj));
                }
            }
        }else{
            if(it->dump() != "null")
                RectLineObj->content += ": " + it->dump();
            PictureObj->PictureLineObj.push_back(std::move(RectLineObj));
        }
    }
}
