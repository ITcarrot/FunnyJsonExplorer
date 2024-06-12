#pragma once
#include "Drawer.hpp"

class RectPicture;
class RectDrawer: public Drawer{
    private:
    std::unique_ptr<RectPicture> PictureObj;
    void DrawLine(const json& JsonObj, const std::string& LeftIndent = "");
    void DrawRight();
    void DrawUp();
    void DrawDown();
    public:
    RectDrawer();
    void Draw(const json &JsonObj) override;
    std::unique_ptr<Picture> GetPicture() override;
};