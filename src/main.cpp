#include "Argument.hpp"
#include "Drawer.hpp"
#include "IconFamily.hpp"
#include "Picture.hpp"
#include <memory>

int main(int argc, char **argv)
{
    Argument arg(argc, argv);
    Drawer *DrawerObj = Drawer::GetAvailableDrawer(arg.style);
    std::unique_ptr<Picture> PictureObj = DrawerObj->Draw(arg.json_file);
    IconFamily icon(arg.icon_family);
    PictureObj->Print(icon);
    return 0;
}