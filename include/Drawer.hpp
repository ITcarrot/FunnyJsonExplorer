#pragma once
#include "Picture.hpp"

class Drawer{
    protected:
    static std::unordered_map<std::string, Drawer*> AvailableDrawer;
    public:
    static Drawer* GetAvailableDrawer(std::string DrawerName);
    static std::vector<std::string> GetAvailableDrawerName();

    virtual void DrawForward(PictureLine &PictureLineObj) = 0;
    virtual void DrawBackward(PictureLine &PictureLineObj) = 0;
};
