// Game.h
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

#pragma once

#ifndef _GAME_H_
#define _GAME_H_

#include "../core/stdafx.h"
#include "../core/GameObjectManager.h"
#include "../core/SpriteGameObject.h"
#include "../ui/GUIText.h"
#include "../paths/ResourcePaths.h"
#include "Chess.h"
#include "Player.h"
#include "Chessboard.h"
#include "../utils/ConsoleLog.h"

#include <vector>
#include <random>
#include <string>

using namespace Chess;

class Player;
class Chessboard;

class Game
{
	static sf::Time prevTime;
	static sf::Time elapsedTime;
	static float deltaTime;

public:

	static void Init(sf::String title);

	static inline sf::RenderWindow& GetWindow() { return mWindow; }
	static inline float GetDeltaTime() { return deltaTime; }
	static inline EGameState GetState() { return gameState; }
	static inline const sf::Event& Game::GetInput();
	static inline const sf::Font GetFont() { return uiFont; }

private:

	static bool isExiting();
	static void MainLoop();
	static void GameLogic();
	static void HandleEvents();
	static void UpdateTime(sf::Clock tick);

	/* !! */

	static EGameState gameState;
	static sf::RenderWindow mWindow; // main window
	static GameObjectManager ObjectManager;
	
	static sf::Font uiFont;
	static Player *topPlayer;
	static Player *bottomPlayer;
	static Chessboard *board;

	/* GUI */

	static GUIText *guiTextMoveCount;
	static GUIText *guiTextStatus;
	
	static sf::Clock tick;
	static sf::Clock eventClock;
	
	static float moveTime; // Play time in (s)
};

#endif // !_GAME_H_