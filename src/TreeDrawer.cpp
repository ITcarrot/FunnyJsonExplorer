#include "TreeDrawer.hpp"
#include "TreePicture.hpp"

TreeDrawer TreeDrawerObj;

TreeDrawer::TreeDrawer()
{
    AvailableDrawer["tree"] = this;
}

std::unique_ptr<Picture> TreeDrawer::Draw(const json &JsonObj) const
{
    auto PictureObj = std::make_unique<TreePicture>();
    DrawLine(PictureObj, JsonObj);
    return PictureObj;
}

void TreeDrawer::DrawLine(std::unique_ptr<TreePicture> &PictureObj, const json& JsonObj, const std::string& LeftIndent) const
{
    for(auto it = JsonObj.begin(); it != JsonObj.end(); ++it){
        auto TreeLineObj = std::make_unique<TreePicture::TreeLine>();
        TreeLineObj->LeftIndent = LeftIndent;
        TreeLineObj->content = it.key();
        if(it->is_object()){
            PictureObj->PictureLines.push_back(std::move(TreeLineObj));
            DrawLine(PictureObj, *it, LeftIndent + "  ");
        }else if(it->is_array()){
            PictureObj->PictureLines.push_back(std::move(TreeLineObj));
            for(const auto& element : *it){
                if(element.is_object() || element.is_array()){
                    DrawLine(PictureObj, element, LeftIndent + "  ");
                } else{
                    TreeLineObj = std::make_unique<TreePicture::TreeLine>();
                    TreeLineObj->LeftIndent = LeftIndent + " ";
                    TreeLineObj->content = element.dump();
                    PictureObj->PictureLines.push_back(std::move(TreeLineObj));
                }
            }
        }else{
            if(it->dump() != "null")
                TreeLineObj->content += ": " + it->dump();
            PictureObj->PictureLines.push_back(std::move(TreeLineObj));
        }
    }
}
