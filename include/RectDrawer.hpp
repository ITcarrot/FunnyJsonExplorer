#pragma once
#include "Drawer.hpp"

class RectDrawer: public Drawer{
    private:
    size_t MaxLength = 0;
    bool IsFirstLine = true, IsLastLine = true;
    void ReplaceSubstring(std::string &str, const std::string &from, const std::string &to) const;
    public:
    RectDrawer(bool RegisterDrawer = false);
    std::unique_ptr<Drawer> clone() const override;
    void DrawForward(PictureLine &PictureLineObj) override;
    void DrawBackward(PictureLine &PictureLineObj) override;
};
