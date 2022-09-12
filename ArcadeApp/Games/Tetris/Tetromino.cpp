#include "Tetromino.h"
#include "../../Graphics/Color.h"

Tetromino::Tetromino()
{
    
}

Tetromino::Tetromino(TetrominoType type)
{
    mType = type;
}

void Tetromino::Init(TetrominoType type)
{
    mType = type;
}

void Tetromino::Update(uint32_t dt)
{
}

void Tetromino::Draw(Screen& screen)
{
    
}

void Tetromino::Rotate(RotationType rotationType)
{
    
}

Color Tetromino::GetColorForType(TetrominoType type)
{
    switch (type) {
    case NONE:
        return Color::Black();
    case OCCUPIED:
        return Color::White();
    case TETROMINO_I:
        return Color::Cyan();
    case TETROMINO_O:
        return Color::Yellow();
    case TETROMINO_T:
        return Color::Magenta();
    case TETROMINO_L:
        return Color::Orange();
    case TETROMINO_J:
        return Color::Blue();
    case TETROMINO_Z:
        return Color::Red();
    case TETROMINO_S:
        return Color::Green();
    }
    return {};
}