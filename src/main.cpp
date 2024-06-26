#include "Argument.hpp"
#include "Drawer.hpp"
#include "IconFamily.hpp"
#include "Picture.hpp"
#include <fstream>

int main(int argc, char **argv)
{
    Argument arg(argc, argv);

    json JsonObj;
    try{
        std::fstream JsonFileStream(arg.JsonFile);
        JsonFileStream >> JsonObj;
    }catch(const std::exception &e){
        printf("Error when parsing json file %s:\n", arg.JsonFile.c_str());
        puts(e.what());
        exit(1);
    }

    auto DrawerObj = Drawer::GetAvailableDrawer(arg.style);
    DrawerObj->Draw(JsonObj);
    auto PictureObj = DrawerObj->GetPicture();
    IconFamily icon(arg.IconFamilyConfFile);
    PictureObj->print(icon);
    return 0;
}