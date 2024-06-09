#include "TreeDrawer.hpp"

TreeDrawer TreeDrawerObj;

TreeDrawer::TreeDrawer()
{
    AvailableDrawer["tree"] = this;
}

std::unique_ptr<Picture> TreeDrawer::Draw(const json &JsonObj) const
{

}
