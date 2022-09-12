#include "Grid.h"

#include "../../Graphics/Screen.h"
#include "../../Shapes/AARectangle.h"

Grid::Grid(): grid()
{
}

void Grid::Update(uint32_t dt)
{
}

void Grid::Draw(Screen& screen)
{
    for (int c = 0; c < GRID_WIDTH; ++c)
    {
        for (int r = 0; r < GRID_HEIGHT; ++r)
        {
            if (grid[c][r].GetFixed())
            {
                AARectangle rect{Vec2D(c * 10, r * 10), 20, 20};
                screen.Draw(rect, Tetromino::GetColorForType(grid[c][r].GetTetrominoType()));

                std::cout << rect.GetCenterPoint() << std::endl;
            }
        }
    }
}

GridElement* Grid::GetGridElementAt(uint8_t row, uint8_t column)
{
    if (row >= GRID_WIDTH || column >= GRID_HEIGHT)
    {
        return nullptr;
    }

    return &grid.at(row).at(column);
}

void Grid::CheckCompleteLines()
{
}
