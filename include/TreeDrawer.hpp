#pragma once
#include "Drawer.hpp"

class TreeDrawer: public Drawer{
    public:
    TreeDrawer();
    std::unique_ptr<Picture> Draw(const std::string json_file) const override;
};