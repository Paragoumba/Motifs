#ifndef MOTIFS_PATTERN_HPP
#define MOTIFS_PATTERN_HPP

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>

class Pattern {
public:
    virtual void setup(const SDL_Rect& clip);
    virtual void compute(const SDL_Rect& clip, SDL_Renderer* renderer, double frame);
    static void renderRectangle(SDL_Renderer* renderer, const SDL_Rect& rect);
    static void drawCircle(SDL_Renderer* renderer, int n_cx, int n_cy, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
};

#endif //MOTIFS_PATTERN_HPP
