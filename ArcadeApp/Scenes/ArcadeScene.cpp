#include "../Scenes/ArcadeScene.h"
#include "../Graphics/Screen.h"
#include "../Input/GameController.h"
#include <iostream>
#include "../App/App.h"
#include "GameScene.h"
#include "../Games/BreakOut/BreakOut.h"
#include "NotImplementedScene.h"
#include "../Games/Pacman/PacmanGame.h"

ArcadeScene::ArcadeScene():ButtonOptionsScene({"Tetris (Not Yet)", "Break Out!", "Asteroids (Not Yet)", "Pac-man"}, Color::Cyan())
{

}

void ArcadeScene::Init()
{

	std::vector<Button::ButtonAction> actions;

	actions.push_back([this]{
		App::Singleton().PushScene(GetScene(TETRIS));
	});

	actions.push_back([this]{
		App::Singleton().PushScene(GetScene(BREAK_OUT));
	});

	actions.push_back([this]{
		App::Singleton().PushScene(GetScene(ASTEROIDS));
	});

	actions.push_back([this]{
		App::Singleton().PushScene(GetScene(PACMAN));
	});

	SetButtonActions(actions);

	ButtonOptionsScene::Init();

	//temp
	{
		mSpriteSheet.Load("PacmanSprites");
		mSprite.Init(App::Singleton().GetBasePath() + "Assets/Pacman_animations.txt", mSpriteSheet);
		mSprite.SetAnimation("death", true);
	}
}

void ArcadeScene::Update(uint32_t dt)
{
	mSprite.Update(dt);
}

void ArcadeScene::Draw(Screen& theScreen)
{
	ButtonOptionsScene::Draw(theScreen);

	mSprite.Draw(theScreen);
}

const std::string& ArcadeScene::GetSceneName() const
{
	static std::string sceneName = "Arcade";
	return sceneName;
}


std::unique_ptr<Scene> ArcadeScene::GetScene(eGame game)
{
	switch(game)
	{
		case TETRIS:
		{

		}
		break;

		case BREAK_OUT:
		{
			std::unique_ptr<BreakOut> breakoutGame = std::make_unique<BreakOut>();

			std::unique_ptr<GameScene> breakoutScene = std::make_unique<GameScene>(std::move(breakoutGame));

			return breakoutScene;
		}
		break;

		case ASTEROIDS:
		{

		}
		break;

		case PACMAN:
		{
				std::unique_ptr<PacmanGame> pacmanGame = std::make_unique<PacmanGame>();

				std::unique_ptr<GameScene> pacmanScene = std::make_unique<GameScene>(std::move(pacmanGame));

				return pacmanScene;
		}
		break;
	}

	std::unique_ptr<Scene> notImplementedScene = std::make_unique<NotImplementedScene>();

	return notImplementedScene;
}
