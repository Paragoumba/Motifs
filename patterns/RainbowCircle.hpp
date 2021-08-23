#ifndef MOTIFS_RAINBOWCIRCLE_HPP
#define MOTIFS_RAINBOWCIRCLE_HPP

#include "Pattern.hpp"

class RainbowCircle : public Pattern {
public:
    void compute(const SDL_Rect& clip, SDL_Renderer *renderer, double frame) override;
};

#endif //MOTIFS_RAINBOWCIRCLE_HPP
