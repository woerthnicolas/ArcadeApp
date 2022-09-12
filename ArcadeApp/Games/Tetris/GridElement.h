#pragma once
#include "Tetromino.h"
#include "../../Graphics/Color.h"


class GridElement
{
public:
    GridElement();
    
    void Update(uint32_t dt);
    void Draw(Screen& screen);
    inline TetrominoType GetTetrominoType() const { return mType; }
    inline void SetTetrominoType(TetrominoType type) { mType = type; }

    void SetFixed();
    bool GetFixed() const;

private:
    TetrominoType mType; // Color and occupied or not
    Color mColor;

    bool mIsFixed;
};
