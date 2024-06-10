#pragma once
#include "Picture.hpp"
#include "RectDrawer.hpp"

class RectPicture: public Picture{
    private:
    struct RectLine{
        std::string LeftIndent, content, RightIndent;
        IconType type;
    };
    std::vector<std::unique_ptr<RectLine>> PictureLines;
    public:
    friend RectDrawer;
    void print(const IconFamily &icon) const override;
};
