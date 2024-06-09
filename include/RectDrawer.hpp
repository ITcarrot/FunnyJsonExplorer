#pragma once
#include "Drawer.hpp"

class RectDrawer: public Drawer{
    private:
    void DrawLine(std::unique_ptr<Picture> &PictureObj, const json& JsonObj, const std::string& LeftIndent = "") const;
    public:
    RectDrawer();
    std::unique_ptr<Picture> Draw(const json &JsonObj) const override;
};