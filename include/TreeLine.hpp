#pragma once
#include "PictureLine.hpp"
#include "TreeDrawer.hpp"

class TreeLine: public PictureLine{
    private:
    std::string LeftIndent, content;
    IconType type;
    public:
    friend TreeDrawer;
    void print(const IconFamily &icon) const override;
};
