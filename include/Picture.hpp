#pragma once
#include "IconFamily.hpp"
#include "3rd_party/json.hpp"
using json = nlohmann::json;

class Drawer;

struct PictureLine{
    std::string LeftIndent, content, RightIndent;
    int IndentSize;
    IconType type;  
};

class Picture{
    private:
    std::vector<PictureLine> PictureLineObj;
    public:
    Picture(const json &JsonObj);
    void draw(const Drawer* DrawerObj);
    void print(const IconFamily &icon) const;
};
