#pragma once
#include "Drawer.hpp"

class TreePicture;
class TreeDrawer: public Drawer{
    private:
    std::unique_ptr<TreePicture> PictureObj;
    void DrawLine(const json& JsonObj, const std::string& LeftIndent = "");
    public:
    TreeDrawer();
    void Draw(const json &JsonObj) override;
    std::unique_ptr<Picture> GetPicture() override;
};