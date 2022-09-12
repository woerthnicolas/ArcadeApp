#include "Tetris.h"

#include <iostream>
#include "../../Input/GameController.h"
/*
 *Gameplay

Tetrominos

Tetrominos are the building blocks of tetris which are geometric shapes composed of four square blocks each. There are 7 tetrominos in total:

A random tetrominos are spawned  at the top of the playfield in their initial positions (see above) and subsequently can be moved by the player.

Movement

The player should be able to move the tetrominos around the play area (explained later) to either side (left or right) by one block or down by one block.
The player should also be able to "drop" the current tetromino which will instantly move the piece down to the bottom floor or on top of the nearest block
below it. There should be a short delay before locking the block in place in which the player can still move the piece. Once the piece is locked, the player
should not be able to move it any longer.

Each tetromino moves downward slowly by itself regardless of any player involvement. As the game goes on, there should be less and less time between the
active tetromino being moved down automatically.

Rotation

These shapes should be able to be rotated around one of the blocks that the shape is composed of. They should each have 4 different rotations
(except the O tetromino which doesn't rotate). Each rotation is 90 degrees counter clock-wise. The player should not be able to rotate
the tetromino if there isn't room to rotate (ie. something is blocking it - either another block or the side walls).

Playfield

The playfield is a block grid that contains all of the tetromino pieces. Your playfield should be at least 10 blocks in width and 20 blocks in height.

Any time a full row (or rows) is made, the rows are cleared and any non completed rows are brought down to be flush with the rest of the blocks.
Completed rows (depending on how many rows were completed that turn) give the player points.

There should be a x2 multiplier for each row (above 1) that were completed. 1 completed row should earn the player 100 points.
An extra 1000 points should be awarded to the player if they manage to get 4 rows cleared at once.

Loss condition

If a piece would be initially spawned overlapping at least one block in the playfield.


Visuals

Ghosted block

The active block should show a "ghosted" image of itself where it would land if the player drops it right now.


Next block panel

There should a panel next to the playfield that will tell you what your next block will be and draw it.

The score should exist in this panel, however, since we don't have text rendering yet, we'll save that until later.
Be sure to leave some room for it for later.
*/

/*

Board (grid) h22 x w10

Tetrominos (7)

Next Tetromino

Score

Ghost Tetrimono

*/

Tetris::Tetris()
{
    gameGrid = std::make_unique<Grid>();
}

void Tetris::Init(GameController& controller)
{
    controller.ClearAll();

    ResetGame();

    ButtonAction rotateAction;
    rotateAction.key = GameController::ActionKey();
    rotateAction.action = [this](uint32_t dt, InputState state)
    {
        /*if (mGameState == IN_SERVE)
        {
            if (GameController::IsPressed(state))
            {
                mGameState = IN_PLAY;

                if (mPaddle.isMovingLeft())
                {
                    mBall.SetVelocity(Vec2D(-INITIAL_BALL_SPEED, -INITIAL_BALL_SPEED));
                }
                else
                {
                    mBall.SetVelocity(Vec2D(INITIAL_BALL_SPEED, -INITIAL_BALL_SPEED));
                }
            }
        }
        else if (mGameState == IN_GAME_OVER)
        {
            if (GameController::IsPressed(state))
            {
                ResetGame();
            }
        }*/
    };

    controller.AddInputActionForKey(rotateAction);

    ButtonAction leftKeyAction;
    leftKeyAction.key = GameController::LeftKey();
    leftKeyAction.action = [this](uint32_t dt, InputState state)
    {
        /*if (mGameState == IN_PLAY || mGameState == IN_SERVE)
        {
            if (GameController::IsPressed(state))
            {
                mPaddle.SetMovementDirection(LEFT);
            }
            else
            {
                mPaddle.UnsetMovementDirection(LEFT);
            }
        }*/
    };

    controller.AddInputActionForKey(leftKeyAction);

    ButtonAction rightKeyAction;
    rightKeyAction.key = GameController::RightKey();
    rightKeyAction.action = [this](uint32_t dt, InputState state)
    {
        /*if (mGameState == IN_PLAY || mGameState == IN_SERVE)
        {
            if (GameController::IsPressed(state))
            {
                mPaddle.SetMovementDirection(RIGHT);
            }
            else
            {
                mPaddle.UnsetMovementDirection(RIGHT);
            }
        }*/
    };

    controller.AddInputActionForKey(rightKeyAction);

    ButtonAction downKeyAction;
    downKeyAction.key = GameController::DownKey();
    downKeyAction.action = [this](uint32_t dt, InputState state)
    {
        /*if (mGameState == IN_PLAY || mGameState == IN_SERVE)
        {
            if (GameController::IsPressed(state))
            {
                mPaddle.SetMovementDirection(RIGHT);
            }
            else
            {
                mPaddle.UnsetMovementDirection(RIGHT);
            }
        }*/
    };
    
    std::cout << "Tetris Init ok" << std::endl;
}

void Tetris::Update(uint32_t dt)
{
    gameGrid->Update(dt);
        
    std::cout << "Tetris Update" << std::endl;
}

void Tetris::Draw(Screen& screen)
{
    gameGrid->Draw(screen);
    
    std::cout << "Tetris Draw" << std::endl;
}

const std::string& Tetris::GetName() const
{
    static std::string name = "Tetris!";

    return name;
}

void Tetris::ResetGame()
{
}
