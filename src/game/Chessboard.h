// Chessboard.h
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

#ifndef _CHESSBOARD_H_
#define _CHESSBOARD_H_

#include <regex>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctype.h>
#include <chrono>
#include "../utils/ConsoleLog.h"

#include "Player.h"

using namespace std;

class Player;

class Chessboard
{
public:

	Chessboard();
	~Chessboard() {}

	void Draw(string board, char separator = '/');
	void SetPlayers(Player *top, Player *bottom);

	// Returns the position for the given algebraic notation
	sf::Vector2f GetPosition(string notation);
	sf::Vector2f GetPosition(int file, int rank);
	sf::Vector2f GetPosition(char file, char rank);

	vector<string> Split(string str, char separator);

private:
	Player *topPlayer;
	Player *bottomPlayer;

	// Origin of coordinates
	sf::Vector2f initPos;
	// Number of square tiles in the board.
	const int SQUARE_TILES = 8;
	// Tile size in pixels
	sf::Vector2f tileSize;
	// Regex to match piece letter code: [pbnrqk] and [PBNRQK]
	regex letter;
	// Regex to match numbers [1-8]
	regex num;
};

#endif // !_CHESSBOARD_H_