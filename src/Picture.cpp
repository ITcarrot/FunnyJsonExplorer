#include "Drawer.hpp"
#include "Picture.hpp"

void Picture::IterateJson(const json &JsonObj, int IndentSize)
{
    if(JsonObj.is_object())
        for(auto it = JsonObj.begin(); it != JsonObj.end(); ++it){
            PictureLine PictureLineObj;
            PictureLineObj.IndentSize = IndentSize;
            PictureLineObj.content = it.key();
            if(it->is_object() || it->is_array()){
                PictureLineObj.type = InternalIcon;
                PictureLines.push_back(PictureLineObj);
                IterateJson(*it, IndentSize + 1);
            }else{
                PictureLineObj.type = LeafIcon;
                if(!it->is_null())
                    PictureLineObj.content += ": " + it->dump();
                PictureLines.push_back(PictureLineObj);
            }
        }

    else if(JsonObj.is_array())
        for(const auto &element: JsonObj)
            if(element.is_object() || element.is_array())
                IterateJson(element, IndentSize + 1);
            else
                IterateJson(element, IndentSize);

    else{
        PictureLine PictureLineObj;
        PictureLineObj.LeftIndent = IndentSize;
        PictureLineObj.content = JsonObj.dump();
        PictureLineObj.type = LeafIcon;
        PictureLines.push_back(PictureLineObj);
    }
}

Picture::Picture(const json &JsonObj)
{
    IterateJson(JsonObj);
}

void Picture::draw(Drawer *DrawerObj)
{
    for(auto &PictureLineObj: PictureLines)
        DrawerObj->DrawForward(PictureLineObj);
    for(auto it = PictureLines.rbegin(); it != PictureLines.rend(); it++)
        DrawerObj->DrawBackward(*it);
}

void Picture::print(const IconFamily &icon) const
{
    for(auto &PictureLineObj: PictureLines)
        printf("%s%s%s%s\n", PictureLineObj.LeftIndent.c_str(), icon[PictureLineObj.type].c_str(),
            PictureLineObj.content.c_str(), PictureLineObj.RightIndent.c_str());
}
