#pragma once
#include "Picture.hpp"
#include "TreeDrawer.hpp"

class TreePicture: public Picture{
    private:
    struct TreeLine{
        std::string LeftIndent, content;
        IconType type;
    };
    std::vector<std::unique_ptr<TreeLine>> PictureLines;
    public:
    friend TreeDrawer;
    void print(const IconFamily &icon) const override;
};
