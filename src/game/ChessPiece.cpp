// ChessPiece.cpp
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

#include "ChessPiece.h"

ChessPiece::ChessPiece(EChessPiece kind, EAlignment faction)
	:isPlayable(true), isAlive(true)
{
	std::string path = "";
	kind = kind;
	switch (kind)
	{
	case EChessPiece::King:
		path = ResourcePaths::IMG__CHESS_PIECE_KING;
		figureName = "King";
		break;
	case EChessPiece::Queen:
		path = ResourcePaths::IMG__CHESS_PIECE_QUEEN;
		figureName = "Queen";
		break;
	case EChessPiece::Rook:
		path = ResourcePaths::IMG__CHESS_PIECE_ROOK;
		figureName = "Rook";
		break;
	case EChessPiece::Bishop:
		path = ResourcePaths::IMG__CHESS_PIECE_BISHOP;
		figureName = "Bishop";
		break;
	case EChessPiece::Knight:
		path = ResourcePaths::IMG__CHESS_PIECE_KNIGHT;
		figureName = "Knight";
		break;
	case EChessPiece::Pawn:
		path = ResourcePaths::IMG__CHESS_PIECE_PAWN;
		figureName = "Pawn";
		break;
	}
	Load(path);
	alignment = faction;

	switch (faction)
	{
	case Chess::EAlignment::Top:
		color = sf::Color::Black;
		factionNane = "Top";
		break;

	case Chess::EAlignment::Bottom:
		color = sf::Color::White;
		factionNane = "Bottom";
		break;
	}

	assert(isLoaded());
	spriteSize = sf::Vector2i(72, 72);
}

ChessPiece::~ChessPiece()
{
}

void ChessPiece::Update(float dt)
{

}

void ChessPiece::Stop()
{

}

void ChessPiece::Draw(sf::RenderWindow & window)
{
	if (isLoaded())
	{
		GetSprite().setColor(color);
		window.draw(GetSprite());
	}
}

void ChessPiece::Move(sf::Vector2f targetPosition)
{
	SetPosition(targetPosition);
	SetPlayable(false);
}