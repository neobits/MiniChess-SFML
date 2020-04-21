// ChessPiece.h
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

#ifndef _CHESS_PIECE_H_
#define _CHESS_PIECE_H_

#include "../core/SpriteGameObject.h"
#include "../paths/ResourcePaths.h"
#include "Chess.h"

using namespace Chess;

class ChessPiece : public SpriteGameObject
{
public:

	ChessPiece() :isPlayable(true) {}
	ChessPiece(EChessPiece kind, EAlignment faction);
	~ChessPiece();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow & window);
	void Move(sf::Vector2f targetPosition);

	inline void SetColor(sf::Color& c) { color = c; }
	inline sf::Color GetColor() { return color; }
	inline bool IsPlayable() { return isPlayable; }
	inline bool IsAlive() { return isAlive; }
	inline void SetPlayable(bool value) { isPlayable = value; }
	inline void SetAlive(bool value) { isAlive = value; }
	inline sf::Vector2i GetSpriteSize() { return spriteSize; }
	inline EChessPiece GetKind() { return kind; }
	inline std::string GetFigureName() { return figureName; }
	inline EAlignment GetAlignment() { return alignment; }
	inline std::string GetFactionName() { return factionNane; }
	void Stop();

private:
	sf::Color color;
	sf::Vector2i spriteSize;
	// Chess piece kind
	EChessPiece kind;
	// Chess piece name
	std::string figureName;
	// Chess faction
	EAlignment alignment;
	// Chess faction name = alignment
	std::string factionNane;
	// Check if the piece can played this turn.
	bool isPlayable;
	bool isAlive;
};

#endif // !_CHESS_PIECE_H_