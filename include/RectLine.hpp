#pragma once
#include "IconFamily.hpp"
#include "Picture.hpp"
#include "RectDrawer.hpp"
#include <string>
#include <memory>

class RectLine: public PictureLine{
    private:
    std::string LeftIndent, content, RightIndent;
    IconType type;
    public:
    friend RectDrawer;
    void print(const IconFamily &icon) const override;
};
