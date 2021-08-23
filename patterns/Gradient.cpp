#include "Gradient.hpp"

void Gradient::compute(const SDL_Rect& clip, SDL_Renderer* renderer, double frame){

    //renderRectangle(renderer, clip);
    //SDL_RenderFillRect(renderer, &clip);

    for (int x = 0; x < clip.w; ++x){

        int r = (int) std::round(std::sin(0.01 * x + frame) * 127 + 128);
        int g = (int) std::round(std::sin(0.01 * x + 2 + frame) * 127 + 128);
        int b = (int) std::round(std::sin(0.01 * x + 4 + frame) * 127 + 128);

        SDL_SetRenderDrawColor(renderer, r, g, b, 255);

        SDL_RenderDrawLine(renderer, x, 0, x, clip.h);

    }
}
