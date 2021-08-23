#include <iostream>
#include "RainbowRectangle.hpp"

void RainbowRectangle::compute(const SDL_Rect& clip, SDL_Renderer* renderer, double frame){

    SDL_Rect rect;

    int maxX = std::min(clip.w, clip.h) / 2;

    for (int x = 0; x <= maxX; ++x){

        rect.x = clip.x + x;
        rect.y = clip.y + x;
        rect.w = clip.w - x * 2 - 1;
        rect.h = clip.h - x * 2 - 1;

        if (rect.w == 0 || rect.h == 0){

            std::cerr << "Rect not rendered." << std::endl;

        }

        int r = (int) std::round(std::sin(0.01 * x + frame) * 127 + 128);
        int g = (int) std::round(std::sin(0.01 * x + 2 + frame) * 127 + 128);
        int b = (int) std::round(std::sin(0.01 * x + 4 + frame) * 127 + 128);

        SDL_SetRenderDrawColor(renderer, r, g, b, 255);

        //SDL_RenderDrawRect(renderer, &rect);
        renderRectangle(renderer, rect);

    }
}
