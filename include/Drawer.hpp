#pragma once
#include "Picture.hpp"

class Drawer{
    protected:
    static std::unordered_map<std::string, Drawer*> AvailableDrawer;
    public:
    static std::unique_ptr<Drawer> GetAvailableDrawer(std::string DrawerName);
    static std::vector<std::string> GetAvailableDrawerName();

    virtual std::unique_ptr<Drawer> clone() const = 0;
    virtual void DrawForward(PictureLine &PictureLineObj) = 0;
    virtual void DrawBackward(PictureLine &PictureLineObj) = 0;
};
