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
    std::vector<PictureLine> PictureLines;
    void IterateJson(const json &JsonObj, int IndentSize = 1);
    public:
    Picture(const json &JsonObj);
    void draw(std::unique_ptr<Drawer> &DrawerObj);
    void print(const IconFamily &icon) const;
};
