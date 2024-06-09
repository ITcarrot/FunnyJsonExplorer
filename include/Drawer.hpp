#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include "Picture.hpp"
#include "3rd_party/json.hpp"
using json = nlohmann::json;

class Drawer{
    protected:
    static std::unordered_map<std::string, Drawer*> AvailableDrawer;
    public:
    static Drawer* GetAvailableDrawer(std::string DrawerName);
    static std::vector<std::string> GetAvailableDrawerName();

    virtual std::unique_ptr<Picture> Draw(const json &JsonObj) const = 0;
};