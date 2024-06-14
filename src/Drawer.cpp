#include "Drawer.hpp"

std::unordered_map<std::string, Drawer*> Drawer::AvailableDrawer = std::unordered_map<std::string, Drawer*>();

Drawer* Drawer::GetAvailableDrawer(std::string DrawerName)
{
    if(AvailableDrawer.count(DrawerName) == 0){
        puts("ERROR: Unrecognize output style!");
        exit(1);
    }
    return AvailableDrawer[DrawerName];
}

std::vector<std::string> Drawer::GetAvailableDrawerName()
{
    std::vector<std::string> result;
    for(auto i: AvailableDrawer)
        result.push_back(i.first);
    return result;
}
