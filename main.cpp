#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <chrono>

#include "patterns/Pattern.hpp"
#include "patterns/RainbowRectangle.hpp"
#include "patterns/MovingPixel.hpp"
#include "patterns/RainbowCircle.hpp"
#include "patterns/Gradient.hpp"
#include "Grid.hpp"

void setColor(SDL_Renderer* renderer, SDL_Color color){

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

}

void computeClip(SDL_Renderer* renderer, SDL_Rect& clip, int width, int height){

    clip.x = width / 4;
    clip.y = height / 4;
    clip.w = width / 2;
    clip.h = height / 2;

    clip.x = 0;
    clip.y = 0;
    clip.w = width;
    clip.h = height;

    clip.x = 10;
    clip.y = 10;
    clip.w = width - 20;
    clip.h = height - 20;

    SDL_RenderSetClipRect(renderer, &clip);

}

int main(){

    if (SDL_Init(SDL_INIT_VIDEO) != 0){

        printf("Error while initializing SDL2:\n%s", SDL_GetError());
        return EXIT_FAILURE;

    }

    int width = 640, height = 480;
    SDL_Window* window = SDL_CreateWindow("Motifs", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    bool running = true;
    SDL_Event event;

    if (window == nullptr){

        printf("Could not create a window.");
        return EXIT_FAILURE;

    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Color clearColor{0, 0, 0, 255};
    SDL_Rect clip{0, 0, width, height};

    computeClip(renderer, clip, width, height);
    setColor(renderer, clearColor);

    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    std::vector<Pattern*> patterns{new Gradient, new RainbowRectangle, new RainbowCircle, new MovingPixel};
    Grid grid(2, 2);

    int fps = 60;
    int frameCount = 0;
    int loopFrameCount = 0;
    timespec waitingTime{0, 0};
    long waitingTimeNano = (long) (1.0 / fps * 1'000'000'000.0);
    double lastLoopTime = SDL_GetTicks();
    std::chrono::time_point startTime = std::chrono::system_clock::now();

    while (running){

        auto loopStart = std::chrono::high_resolution_clock::now();

        while (SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_QUIT:
                    running = false;
                    break;

                case SDL_WINDOWEVENT:
                    if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED){

                        computeClip(renderer, clip, event.window.data1, event.window.data2);

                    }

                    break;

                case SDL_KEYUP:
                    switch (event.key.keysym.sym){
                        case SDLK_ESCAPE:
                            running = false;
                            break;

                        case SDLK_F11:
                            if((SDL_GetWindowFlags(window) & SDL_WINDOW_MAXIMIZED) != 0){

                                SDL_RestoreWindow(window);
                                SDL_SetWindowBordered(window, SDL_TRUE);

                            } else {

                                SDL_MaximizeWindow(window);
                                SDL_SetWindowBordered(window, SDL_FALSE);

                            }

                            break;

                    }

                    break;

            }
        }

        setColor(renderer, clearColor);
        SDL_RenderClear(renderer);

        // Render here
//        SDL_RenderSetClipRect(renderer, &clip);
//        SDL_RenderSetViewport(renderer, &clip);

        clip.w = width / 2;
        clip.h = height / 2;

        for (int i = 0; i < patterns.size(); ++i){

            clip.x = i % 2 * clip.w;
            clip.y = i / 2 * clip.h;

            SDL_RenderSetClipRect(renderer, &clip);
            patterns[i]->compute(clip, renderer, (double) frameCount / 10);

        }

        SDL_RenderPresent(renderer);

        waitingTime.tv_nsec = waitingTimeNano -
                duration_cast<std::chrono::nanoseconds>(
                        std::chrono::high_resolution_clock::now() - loopStart
                        ).count();

        nanosleep(&waitingTime, nullptr);

        if (SDL_GetTicks() - lastLoopTime >= 1000){

            lastLoopTime = SDL_GetTicks();
            SDL_SetWindowTitle(window, (std::string() + std::to_string(loopFrameCount) + "FPS").c_str());
            loopFrameCount = 0;

        }

        ++frameCount;
        ++loopFrameCount;

    }

    patterns.erase(patterns.begin(), patterns.end());

    SDL_DestroyWindow(window);

    SDL_Quit();

    return EXIT_SUCCESS;

}
