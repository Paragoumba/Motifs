#include "MovingPixel.hpp"

void MovingPixel::compute(const SDL_Rect& clip, SDL_Renderer* renderer, double frame){

//    rect.x = clip.x;
//    rect.y = clip.y;
    rect.w = clip.w / 10;
    rect.h = clip.h / 10;

    int r = (int) std::round(std::sin(0.01 * rect.x + frame) * 127 + 128);
    int g = (int) std::round(std::sin(0.01 * rect.x + 2 + frame) * 127 + 128);
    int b = (int) std::round(std::sin(0.01 * rect.x + 4 + frame) * 127 + 128);

    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    //SDL_RenderDrawPoint(renderer, clip.x + point.x, clip.y + point.y);
//    renderRectangle(renderer, rect);
    SDL_RenderFillRect(renderer, &rect);

    rect.x++;

    if (rect.x >= clip.w - rect.w){

        rect.x = clip.x;
        rect.y++;

        if (rect.y >= clip.h - rect.h){

            rect.y = clip.y;

        }
    }
}
