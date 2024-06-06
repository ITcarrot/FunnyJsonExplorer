#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include "Picture.hpp"

class Drawer{
    protected:
    static std::unordered_map<std::string, Drawer*> AvailableDrawer;
    public:
    static Drawer* GetAvailableDrawer(std::string DrawerName);
    static std::vector<std::string> GetAvailableDrawerName();

    virtual std::unique_ptr<Picture> Draw(const std::string json_file) const = 0;
};