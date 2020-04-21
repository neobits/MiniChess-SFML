// Chess.h
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

#ifndef _CHESS_H_
#define _CHESS_H_

namespace Chess
{
	enum EAlignment {
		Top = 0,
		Bottom = 1
	};

	enum EGameState {
		Uninitialized,
		Paused,
		Playing,
		Exiting
	};

	enum EChessPiece {
		King = 100,
		Queen = 10,
		Rook = 5,
		Bishop = 4,
		Knight = 3,
		Pawn = 1,
	};
}

#endif // !_CHESS_H_