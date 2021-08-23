#include "Pattern.hpp"

void Pattern::setup(const SDL_Rect& clip){}
void Pattern::compute(const SDL_Rect& clip, SDL_Renderer* renderer, double frame){}

#define POINT_NB 5

// The purpose of this function is to render a rectangle.
// We could use SDL_RenderDrawRect to achieve the same goal but there is a regression
// that renders rectangles wrongly (top right angle's x value is 1 too low,
// bottom right angle's x and y values are 1 too low) and it is not fixed as of now (2.0.16).
// TODO Remove when the regression is fixed.
void Pattern::renderRectangle(SDL_Renderer* renderer, const SDL_Rect& rect) {

    SDL_Point points[POINT_NB];

    points[0].x = rect.x;
    points[0].y = rect.y;
    points[1].x = rect.x + rect.w;
    points[1].y = rect.y;
    points[2].x = rect.x + rect.w;
    points[2].y = rect.y + rect.h;
    points[3].x = rect.x;
    points[3].y = rect.y + rect.h - 1;
    points[4].x = rect.x;
    points[4].y = rect.y;

    SDL_RenderDrawLines(renderer, points, POINT_NB);

}

void Pattern::drawCircle(SDL_Renderer* renderer, int n_cx, int n_cy, int radius, Uint8 r, Uint8 g, Uint8 b, Uint8 a){

    // if the first pixel in the screen is represented by (0,0) (which is in sdl)
    // remember that the beginning of the circle is not in the middle of the pixel
    // but to the left-top from it:

    double error = (double) -radius;
    double x = (double) radius - 0.5;
    double y = (double) 0.5;
    double cx = n_cx - 0.5;
    double cy = n_cy - 0.5;

    SDL_SetRenderDrawColor(renderer, r, g, b, a);

    while (x >= y){

        SDL_RenderDrawPoint(renderer, (int)(cx + x), (int)(cy + y));
        SDL_RenderDrawPoint(renderer, (int)(cx + y), (int)(cy + x));

        if (x != 0){

            SDL_RenderDrawPoint(renderer, (int)(cx - x), (int)(cy + y));
            SDL_RenderDrawPoint(renderer, (int)(cx + y), (int)(cy - x));
            
        }

        if (y != 0){

            SDL_RenderDrawPoint(renderer, (int)(cx + x), (int)(cy - y));
            SDL_RenderDrawPoint(renderer, (int)(cx - y), (int)(cy + x));
        
        }

        if (x != 0 && y != 0){

            SDL_RenderDrawPoint(renderer, (int)(cx - x), (int)(cy - y));
            SDL_RenderDrawPoint(renderer, (int)(cx - y), (int)(cy - x));
        
        }

        error += y;
        ++y;
        error += y;

        if (error >= 0){
            
            --x;
            error -= x;
            error -= x;
            
        }
    }
}
