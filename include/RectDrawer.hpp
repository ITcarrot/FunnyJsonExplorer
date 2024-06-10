#pragma once
#include "Drawer.hpp"

class RectPicture;
class RectDrawer: public Drawer{
    private:
    void DrawLine(std::unique_ptr<RectPicture> &PictureObj, const json& JsonObj, const std::string& LeftIndent = "") const;
    void DrawRight(std::unique_ptr<RectPicture> &PictureObj) const;
    void DrawUp(std::unique_ptr<RectPicture> &PictureObj) const;
    void DrawDown(std::unique_ptr<RectPicture> &PictureObj) const;
    public:
    RectDrawer();
    std::unique_ptr<Picture> Draw(const json &JsonObj) const override;
};