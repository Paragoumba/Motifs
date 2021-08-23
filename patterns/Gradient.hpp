#ifndef MOTIFS_GRADIENT_HPP
#define MOTIFS_GRADIENT_HPP

#include "Pattern.hpp"

class Gradient : public Pattern {
public:
    void compute(const SDL_Rect& clip, SDL_Renderer *renderer, double frame) override;
};

#endif //MOTIFS_GRADIENT_HPP
