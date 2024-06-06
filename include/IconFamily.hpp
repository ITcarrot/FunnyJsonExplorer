#pragma once
#include <string>

enum IconType{InternalIcon, LeafIcon, IconTypeCount};

class IconFamily{
    private:
    std::string icon[int(IconTypeCount)];
    public:
    IconFamily(const std::string &ConfFile);
    std::string operator[](const IconType &type) const;
};
