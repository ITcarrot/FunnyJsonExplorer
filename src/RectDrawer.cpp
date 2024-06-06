#include "RectDrawer.hpp"

RectDrawer RectDrawerObj;

RectDrawer::RectDrawer()
{
    AvailableDrawer["rectangle"] = this;
}

std::unique_ptr<Picture> RectDrawer::Draw(const std::string json_file) const
{

}
