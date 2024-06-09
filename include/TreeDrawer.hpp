#pragma once
#include "Drawer.hpp"

class TreeDrawer: public Drawer{
    public:
    TreeDrawer();
    std::unique_ptr<Picture> Draw(const json &JsonObj) const override;
};