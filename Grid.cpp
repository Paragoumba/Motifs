#include "Grid.hpp"

Grid::Grid(size_t rowNb, size_t colNb) : rowNb(rowNb), colNb(colNb){

    size_t gridSize = rowNb * colNb;

    for (int i = 0; i < gridSize; ++i){

        elements.push_back(new Pattern);

    }
}

void Grid::computeFrame(SDL_Renderer* renderer, double frameCount){

    SDL_Rect clip;

    //TODO Compute clip

    for (auto& element : elements){

        element->compute(clip, renderer, frameCount);

    }
}

Grid::~Grid(){

    for (auto& element : elements){

        delete element;

    }
}
