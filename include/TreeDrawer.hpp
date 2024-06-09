#pragma once
#include "Drawer.hpp"

class TreeDrawer: public Drawer{
    private:
    void DrawLine(std::unique_ptr<Picture> &PictureObj, const json& JsonObj, const std::string& LeftIndent = "") const;
    public:
    TreeDrawer();
    std::unique_ptr<Picture> Draw(const json &JsonObj) const override;
};