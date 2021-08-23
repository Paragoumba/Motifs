#ifndef MOTIFS_GRID_HPP
#define MOTIFS_GRID_HPP

#include <vector>

#include "patterns/Pattern.hpp"

class Grid {
protected:
    size_t rowNb;
    size_t colNb;

    std::vector<Pattern*> elements;

public:
    Grid(size_t rowNb, size_t colNb);

    void computeFrame(SDL_Renderer* renderer, double frameCount);

    ~Grid();
};

#endif //MOTIFS_GRID_HPP
