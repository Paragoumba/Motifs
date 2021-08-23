#include "RainbowCircle.hpp"

void RainbowCircle::compute(const SDL_Rect& clip, SDL_Renderer* renderer, double frame){

    int halfW = clip.w / 2;
    int halfH = clip.h / 2;
    double frequency = 0.01;

    double diagonal = std::sqrt(halfW * halfW + halfH * halfH) / std::max(halfW, halfH);

    for (int radius = 0; radius < std::max(halfW, halfH) * diagonal; ++radius){

        double freqRadius = frequency * radius;

        int r = (int) std::round(std::sin(freqRadius + frame) * 127 + 128);
        int g = (int) std::round(std::sin(freqRadius + 2 + frame) * 127 + 128);
        int b = (int) std::round(std::sin(freqRadius + 4 + frame) * 127 + 128);

        drawCircle(renderer, clip.x + halfW, clip.y + halfH, radius, r, g, b, 255);

    }
}
