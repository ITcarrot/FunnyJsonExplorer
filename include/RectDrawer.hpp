#pragma once
#include "Drawer.hpp"

class RectDrawer: public Drawer{
    public:
    RectDrawer();
    std::unique_ptr<Picture> Draw(const std::string json_file) const override;
};