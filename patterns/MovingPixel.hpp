#ifndef MOTIFS_MOVINGPIXEL_HPP
#define MOTIFS_MOVINGPIXEL_HPP

#include "Pattern.hpp"

class MovingPixel : public Pattern {
protected:
    SDL_Rect rect{0, 0};

public:
    void compute(const SDL_Rect& clip, SDL_Renderer *renderer, double frame) override;
};

#endif //MOTIFS_MOVINGPIXEL_HPP
