#pragma once
#include <array>

#include "GridElement.h"

const size_t GRID_HEIGHT = 22;
const size_t GRID_WIDTH = 10;

class Grid
{
public:
    Grid();
    void Update(uint32_t dt);
    void Draw(Screen& screen);
    inline auto* GetGrid() const { return &grid; }

    GridElement* GetGridElementAt(uint8_t row, uint8_t column);

    void CheckCompleteLines();
private:
    std::array<std::array<GridElement, GRID_HEIGHT>, GRID_WIDTH> grid;

};
