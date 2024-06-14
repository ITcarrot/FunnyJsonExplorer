#pragma once
#include "Drawer.hpp"

class TreeDrawer: public Drawer{
    private:
    std::vector<bool> HasParent;
    public:
    TreeDrawer();
    void DrawForward(PictureLine &PictureLineObj) override;
    void DrawBackward(PictureLine &PictureLineObj) override;
};
