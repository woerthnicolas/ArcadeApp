#pragma once
#include <array>
#include <vector>
#include "../../Utils/Vec2D.h"

class Color;
class Screen;
class AARectangle;

enum TetrominoType
{
    NONE = 0,
    OCCUPIED,
    TETROMINO_I,
    TETROMINO_O,
    TETROMINO_T,
    TETROMINO_L,
    TETROMINO_J,
    TETROMINO_Z,
    TETROMINO_S
};

enum RotationType
{
    ROTATE_LEFT = 0,
    ROTATE_RIGHT
};

class Tetromino
{
public:
    Tetromino();
    Tetromino(TetrominoType type);

    void Init(TetrominoType type);
    void Update(uint32_t dt);
    void Draw(Screen& screen);

    void Rotate(RotationType rotationType);
    static Color GetColorForType(TetrominoType type);
private:
    
    TetrominoType mType;
    Vec2D mVelocity;
    std::array<std::array<int, 4>, 3> shape;
};
