#pragma once
#include "IconFamily.hpp"
#include "PictureLine.hpp"
#include <memory>
#include <vector>

class Picture{
    public:
    std::vector<std::unique_ptr<PictureLine>> PictureLineObj;
    void Print(const IconFamily &icon) const;
};
