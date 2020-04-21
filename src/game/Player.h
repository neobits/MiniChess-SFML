// Player.h
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

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "../core/GameObject.h"
#include "../core/GameObjectManager.h"

#include "Chess.h"
#include "Chessboard.h"
#include "ChessPiece.h"
#include "Game.h"

using namespace Chess;

class Player : public GameObject
{
	enum EPlayState
	{
		Waiting,
		Moving,
		Won,
		Lost,
	};

	int moveCount;
	bool isMoving;
	EPlayState state;
	EAlignment faction;
	string factionName;
	std::map<std::string, ChessPiece*> pieces;
	// Code padding separator
	std::string codeSep = "#";
	GameObjectManager *manager;

	static const int PAWN_START_COUNT = 8;
	static const int ROOK_START_COUNT = 2;
	static const int BISHOP_START_COUNT = 2;
	static const int KNIGHT_START_COUNT = 2;
	static const int QUEEN_START_COUNT = 1;
	static const int KING_START_COUNT = 1;

public:
	//Player() {};
	Player(EAlignment faction, GameObjectManager *manager);
	~Player();

	void Update(float deltaTime);
	void Draw();

	bool StartMove();
	void StopMove();

	int GetMoveCount() const { return moveCount; }
	ChessPiece *GetPiece(string code);
	ChessPiece *GetAvailablePiece(char code, bool log = false);
	bool IsMoving() const { return isMoving; }

	void CreatePiece(EChessPiece kind, char code, 
					 sf::Color color, int it);

};

#endif // !_PLAYER_H_