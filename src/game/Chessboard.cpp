// Chessboard.cpp
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

#include "Chessboard.h"

Chessboard::Chessboard()
{
	initPos = sf::Vector2f(352.f, 576.f);
	tileSize = sf::Vector2f(72, 72);
	letter = regex("[pbnrqkPBNRQK]");
	num = regex("[1-8]");
}

void Chessboard::SetPlayers(Player *top, Player *bottom)
{
	topPlayer = top;
	bottomPlayer = bottom;
}

void Chessboard::Draw(string board, char separator)
{
	auto start_t = chrono::steady_clock::now();

	vector<string> rows = Split(board, separator);
	sf::Vector2f pos;
	string col;
	int pFile = 0, pRank = 0;
	for (size_t i = rows.size() - 1; pRank < rows.size(); i--, pRank++)
	{
		pFile = 0;
		col = rows[i];
		for (size_t j = 0; j < col.length(); j++)
		{
			if (isdigit(col[j]))
			{
				if (col[j] >= '1' && col[j] <= '8')
				{
					pFile += (int)col[j] - (int)'0' - 1;
				}
				else {
					Utils::LogError("Chessboard::Draw")
						<< " input must be 1 to 8" << std::endl;
				}
			}
			else if (isalpha(col[j]))
			{
				if (col[j] == 'p' || col[j] == 'r' || col[j] == 'n' ||
					col[j] == 'b' || col[j] == 'q' || col[j] == 'k') {
					pos = GetPosition(pFile, pRank);
					topPlayer->GetAvailablePiece(col[j])->Move(pos);
					//cout << "[notice] Chessboard::Draw | " << "Piece found and placed." << endl;
					pFile++;
				}
				else if (col[j] == 'P' || col[j] == 'R' || col[j] == 'N' ||
					col[j] == 'B' || col[j] == 'Q' || col[j] == 'K') {
					pos = GetPosition(pFile, pRank);
					bottomPlayer->GetAvailablePiece(col[j])->Move(pos);
					//cout << "[notice] Chessboard::Draw | " << "Piece found and placed." << endl;
					pFile++;
				}
				else {
					Utils::LogError("Chessboard::Draw")
						<< "Input must be a valid piece" << std::endl;
				}
			}
			else {
				Utils::LogError("Chessboard::Draw")
					<< "Invalid character input!" << std::endl;
			}
		}
	}
	auto end_t = chrono::steady_clock::now();
	auto diff_t = end_t - start_t;
	long ms_t = (long)chrono::duration_cast<chrono::milliseconds>(diff_t).count();
	long micros_t = (long)chrono::duration_cast<chrono::microseconds>(diff_t).count();

	Utils::LogNotice("Chessboard::Draw")
		<< "Ended at " << pFile << "x" << pRank
		<< " in approx. " << ms_t << " ms"
		<< " ~ " << micros_t << " micro s" << std::endl;
}

sf::Vector2f Chessboard::GetPosition(int file, int rank)
{
	sf::Vector2f pos = initPos;
	pos.x += file * tileSize.x;
	pos.y -= rank * tileSize.y;

	return pos;
}

sf::Vector2f Chessboard::GetPosition(char file, char rank)
{
	int f = (int)file - (int)'a';
	int r = (int)rank - (int)'1';

	sf::Vector2f pos = initPos;
	pos.x += f * tileSize.x;
	pos.y -= r * tileSize.y;

	return pos;
}

sf::Vector2f Chessboard::GetPosition(string coordinates)
{
	int file = (int)coordinates[0] - (int)'a';
	int rank = (int)coordinates[1] - (int)'1';

	sf::Vector2f pos = initPos;
	pos.x += file * tileSize.x;
	pos.y += rank * tileSize.y;

	return pos;
}

vector<string> Chessboard::Split(string str, char separator)
{
	vector<string> result;
	stringstream ss(str);
	string token;

	while (getline(ss, token, separator)) {
		result.push_back(token);
	}

	return result;
}