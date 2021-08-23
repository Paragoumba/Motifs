#ifndef MOTIFS_RAINBOWRECTANGLE_HPP
#define MOTIFS_RAINBOWRECTANGLE_HPP

#include "Pattern.hpp"

class RainbowRectangle : public Pattern {
public:
    void compute(const SDL_Rect& clip, SDL_Renderer* renderer, double frame) override;
};

#endif //MOTIFS_RAINBOWRECTANGLE_HPP
