#pragma once
#include "IconFamily.hpp"

class Picture{
    public:
    virtual void print(const IconFamily &icon) const = 0;
};
