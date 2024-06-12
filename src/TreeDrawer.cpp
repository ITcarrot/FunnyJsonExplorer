#include "TreeDrawer.hpp"
#include "TreePicture.hpp"

TreeDrawer TreeDrawerObj;

TreeDrawer::TreeDrawer()
{
    AvailableDrawer["tree"] = this;
}

void TreeDrawer::Draw(const json &JsonObj)
{
    PictureObj = std::make_unique<TreePicture>();
    DrawLine(JsonObj);
}

std::unique_ptr<Picture> TreeDrawer::GetPicture()
{
    return std::move(PictureObj);
}

void TreeDrawer::DrawLine(const json& JsonObj, const std::string& LeftIndent)
{
    if(JsonObj.is_object()){
        auto LastElement = JsonObj.end();
        LastElement--;
        for(auto it = JsonObj.begin(); it != JsonObj.end(); ++it){
            auto TreeLineObj = std::make_unique<TreePicture::TreeLine>();
            TreeLineObj->LeftIndent = LeftIndent + (it != LastElement ? "├─" : "└─");
            TreeLineObj->content = it.key();
            if(it->is_object() || it->is_array()){
                TreeLineObj->type = InternalIcon;
                PictureObj->PictureLines.push_back(std::move(TreeLineObj));
                DrawLine(*it, LeftIndent + (it != LastElement ? "│  " : "   "));
            }else{
                TreeLineObj->type = LeafIcon;
                if(!it->is_null())
                    TreeLineObj->content += ": " + it->dump();
                PictureObj->PictureLines.push_back(std::move(TreeLineObj));
            }
        }

    }else if(JsonObj.is_array()){
        auto LastElement = JsonObj.end();
        LastElement--;
        for(auto it = JsonObj.begin(); it != JsonObj.end(); ++it)
            if(it->is_object() || it->is_array())
                DrawLine(*it, LeftIndent + (it != LastElement ? "│  " : "   "));
            else
                DrawLine(*it, LeftIndent);

    }else{
        auto TreeLineObj = std::make_unique<TreePicture::TreeLine>();
        TreeLineObj->LeftIndent = LeftIndent + "├─";
        TreeLineObj->content = JsonObj.dump();
        TreeLineObj->type = LeafIcon;
        PictureObj->PictureLines.push_back(std::move(TreeLineObj));
    }
}
