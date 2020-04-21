// Game.cpp
//
// Copyright(C) 2020 neobits (Angelo Moro)
//
// This file is part of MiniChess-SFML.
//
// MiniChess-SFML is free software : you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// MiniChess-SFML is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Foobar.If not, see < https://www.gnu.org/licenses/>.

#include "Game.h"

Chess::EGameState Game::gameState = Uninitialized;
sf::RenderWindow Game::mWindow;
GameObjectManager Game::ObjectManager;

sf::Clock Game::tick;
sf::Time Game::elapsedTime;
sf::Time Game::prevTime;
float Game::deltaTime = 0;
sf::Font Game::uiFont;
Player* Game::topPlayer;
Player* Game::bottomPlayer;
Chessboard *Game::board;

GUIText* Game::guiTextMoveCount;
GUIText* Game::guiTextStatus;

sf::Clock Game::eventClock;
float Game::moveTime = 1.5f;

void Game::Init(sf::String title)
{
	if (gameState != Uninitialized)
	{
		return;
	}

	Utils::LogNotice("Game::Init") << "Creating window" << std::endl;
	mWindow.create(sf::VideoMode(1280, 720, 32), title);	
	mWindow.setFramerateLimit(60);
	sf::ContextSettings contextSettings;
	contextSettings.depthBits = 24;
	contextSettings.sRgbCapable = false;

	if (!uiFont.loadFromFile(ResourcePaths::FONT__ARCADE_CLASSIC))
	{
		Utils::LogError("Game::Init") << "Font not loaded" << std::endl;
	}
	
	// Create the background
	Utils::LogNotice("Game::Init") << "Creating bkg" << std::endl;
	SpriteGameObject* background = new SpriteGameObject();
	background->Load(ResourcePaths::IMG__BACKGROUNG);
	ObjectManager.Add("BackgroundImage", background);

	// Players
	Utils::LogNotice("Game::Init") << "Creating players" << std::endl;
	topPlayer = new Player(Chess::Top, &ObjectManager);
	ObjectManager.Add("TopPlayer", topPlayer);
	bottomPlayer = new Player(Chess::Bottom, &ObjectManager);
	ObjectManager.Add("BottomPlayer", bottomPlayer);

	// Chessboard
	Utils::LogNotice("Game::Init") << "Creating board" << std::endl;
	board = new Chessboard();
	board->SetPlayers(topPlayer, bottomPlayer);
	//board->Draw("8/pppppppp/8/8/8/8/PPPPPPPP/8");
	board->Draw("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR");

	// UI
	Utils::LogNotice("Game::Init") << "Creating UI" << std::endl;
	guiTextMoveCount = new GUIText();
	guiTextMoveCount->SetFont(uiFont);
	guiTextMoveCount->SetLabel(sf::String("MOVES"));
	guiTextMoveCount->SetPosition(50, 10);
	ObjectManager.Add("MoveCountText", guiTextMoveCount);

	guiTextStatus = new GUIText();
	guiTextStatus->SetFont(uiFont);
	guiTextStatus->SetLabel(sf::String("STATUS"));
	guiTextStatus->SetPosition(50, 60);
	ObjectManager.Add("GameStatusText", guiTextStatus);

	Utils::LogNotice("Game::Init") << "Set gameState to Playing" << std::endl;
	gameState = Chess::Playing;

	prevTime = sf::Time();
	elapsedTime = sf::Time();

	bottomPlayer->StartMove();

	while (!isExiting())
	{
		if (gameState == Chess::Playing) {
			UpdateTime(tick);
		}
		HandleEvents();
		GameLogic();
		MainLoop();	
	}

	mWindow.close();
}

bool Game::isExiting()
{
	if (gameState == Chess::Exiting) {
		return true;
	}
	else {
		return false;
	}
}

void Game::UpdateTime(sf::Clock tick)
{
	elapsedTime = tick.restart();
	deltaTime = elapsedTime.asSeconds() - prevTime.asSeconds();

	//std::cout << std::to_string(deltaTime) << std::endl;
	prevTime = elapsedTime;
}

void Game::HandleEvents()
{
	sf::Event currentEvent;
	while (mWindow.pollEvent(currentEvent))
	{
		if (currentEvent.type == sf::Event::KeyPressed)
		{
			if (currentEvent.key.code == sf::Keyboard::Escape)
			{
				gameState = Chess::Exiting;
			}
		}

		switch (gameState)
		{
		case Chess::Playing:
			if (currentEvent.type == sf::Event::Closed)
			{
				gameState = Chess::Exiting;
			}
			if (currentEvent.type == sf::Event::KeyReleased)
			{
				if (currentEvent.key.code == sf::Keyboard::Space)
				{
					gameState = Chess::Paused;
					Utils::LogNotice("Game::HandleEvents()") 
						<< "Game Paused";
				}
			}
			break;

		case Chess::Paused:
			if (currentEvent.type == sf::Event::KeyReleased)
			{
				if (currentEvent.key.code == sf::Keyboard::Space)
				{
					gameState = Chess::Playing;
					Utils::LogNotice("Game::HandleEvents()")
						<< "Game Resumed";
				}
			}
			break;

		case Chess::Exiting:
			mWindow.close();
			break;
		}
	}
}

void Game::GameLogic()
{
	std::string str = std::to_string(bottomPlayer->GetMoveCount());
	guiTextMoveCount->SetInfo(sf::String(str));

	switch (gameState)
	{
	case Chess::EGameState::Playing:
		str = "PLAYING";
		break;
	case Chess::EGameState::Paused:
		str = "PAUSED";
		break;
	case Chess::EGameState::Exiting:
		str = "EXITING";
		break;
	}
	guiTextStatus->SetLabel(sf::String(str));

	//if (mPlayerBottom->IsMoving())
	//{
	//	if (mEventClock.getElapsedTime().asSeconds() >= mMoveTime)
	//	{
	//		mPlayerBottom->StopMove();
	//	}
	//}
}

void Game::MainLoop()
{
	// OpenGL render pipeline
	mWindow.clear(sf::Color(0, 0, 0));
	if (gameState == Chess::EGameState::Playing) {
		ObjectManager.UpdateObjects(deltaTime);
	}
	ObjectManager.DrawObjects(mWindow);
	mWindow.display();
	// End main OpenGL render pipeline
}

const sf::Event& Game::GetInput()
{
	sf::Event e;
	mWindow.pollEvent(e);
	return e;
}