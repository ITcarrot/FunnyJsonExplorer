#pragma once
#include "IconFamily.hpp"

class PictureLine{
    public:
    virtual void print(const IconFamily &icon) const = 0;
};