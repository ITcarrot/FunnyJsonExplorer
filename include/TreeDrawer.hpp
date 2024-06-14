#pragma once
#include "Drawer.hpp"

class TreeDrawer: public Drawer{
    private:
    std::vector<bool> HasParent;
    public:
    TreeDrawer(bool RegisterDrawer = false);
    std::unique_ptr<Drawer> clone() const override;
    void DrawForward(PictureLine &PictureLineObj) override;
    void DrawBackward(PictureLine &PictureLineObj) override;
};
