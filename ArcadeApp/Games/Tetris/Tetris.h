#pragma once
#include <memory>

#include "Grid.h"
#include "../Game.h"

class Tetris : public Game
{
public:
    Tetris();
    void Init(GameController& controller) override;
    void Update(uint32_t dt) override;
    void Draw(Screen& screen) override;
    const std::string& GetName() const override;

private:
    void ResetGame();

    std::unique_ptr<Grid> gameGrid;
};
