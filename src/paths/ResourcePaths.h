// ResourcePaths.h
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

#include <string>

using std::string;

class ResourcePaths
{
public:
	static const string IMG__BACKGROUNG;
	static const string IMG__CHESS_PIECE_KING;
	static const string IMG__CHESS_PIECE_QUEEN;
	static const string IMG__CHESS_PIECE_ROOK;
	static const string IMG__CHESS_PIECE_BISHOP;
	static const string IMG__CHESS_PIECE_KNIGHT;
	static const string IMG__CHESS_PIECE_PAWN;
	static const string IMG__CHESSBOARD_TILE;
	static const string FONT__ARCADE_CLASSIC;
};