#pragma once
#include "Picture.hpp"
#include "3rd_party/json.hpp"
using json = nlohmann::json;

class Drawer{
    protected:
    static std::unordered_map<std::string, Drawer*> AvailableDrawer;
    public:
    static Drawer* GetAvailableDrawer(std::string DrawerName);
    static std::vector<std::string> GetAvailableDrawerName();

    virtual void Draw(const json &JsonObj) = 0;
    virtual std::unique_ptr<Picture> GetPicture() = 0;
};
