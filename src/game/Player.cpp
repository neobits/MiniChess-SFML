// Player.cpp
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

#include "Player.h"


Player::Player(Chess::EAlignment alg, GameObjectManager *mng)
	:moveCount(0), isMoving(false)
{
	manager = mng;
	faction = alg;

	if (faction == EAlignment::Top)
		factionName = "Top";
	else if (faction == EAlignment::Bottom)
		factionName = "Bottom";

	std::stringstream ss;
	string code;
	sf::Color color;

	if (faction == Chess::Top) {
		color = sf::Color::Black;
		CreatePiece(Chess::Queen, 'q', color, 0);
		CreatePiece(Chess::King, 'k', color, 0);
	}
	else if (faction == Chess::Bottom) {
		color = sf::Color::White;
		CreatePiece(Chess::Queen, 'Q', color, 0);
		CreatePiece(Chess::King, 'K', color, 0);
	}

	int idx = 0;
	for (idx = 0; idx < PAWN_START_COUNT; idx++)
	{
		char pawn;
		if (faction == Chess::Top) pawn = 'p';
		else if (faction == Chess::Bottom)pawn = 'P';

		CreatePiece(Chess::Pawn, pawn, color, idx);
	}

	for (idx = 0; idx < ROOK_START_COUNT; idx++)
	{
		char rook;
		if (faction == Chess::Top) rook = 'r';
		else if (faction == Chess::Bottom)rook = 'R';

		CreatePiece(Chess::Rook, rook, color, idx);
	}
	for (idx = 0; idx < KNIGHT_START_COUNT; idx++)
	{
		char knight;
		if (faction == Chess::Top) knight = 'n';
		else if (faction == Chess::Bottom)knight = 'N';

		CreatePiece(Chess::Knight, knight, color, idx);
	}
	for (idx = 0; idx < BISHOP_START_COUNT; idx++)
	{
		char bishop;
		if (faction == Chess::Top) bishop = 'b';
		else if (faction == Chess::Bottom)bishop = 'B';

		CreatePiece(Chess::Bishop, bishop, color, idx);
	}
}

void Player::CreatePiece(EChessPiece kind, char code, 
						 sf::Color color, int it)
{
	ChessPiece *piece = new ChessPiece(kind, faction);
	piece->SetPivot(SpriteGameObject::Center);
	piece->SetColor(color);
	stringstream sname;
	stringstream scode;
	scode << std::to_string(code) << codeSep << std::to_string(it);
	pieces.insert(std::pair<string, ChessPiece*>(scode.str(), piece));
	
	sname << "ChessPiece_" << piece->GetFactionName() << "_" 
		<< piece->GetFigureName() << "_" << std::to_string(it);
	manager->Add(sname.str(), piece);
	sname.clear();
	scode.clear();
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{

}

void Player::Draw()
{

}

ChessPiece* Player::GetPiece(string code)
{
	std::map<string, ChessPiece*>::iterator itr = pieces.find(code);
	if (itr == pieces.end())
		return NULL;

	return itr->second;
}

ChessPiece* Player::GetAvailablePiece(char code, bool log)
{
	std::map<string, ChessPiece*>::iterator itr;

	for (itr = pieces.begin(); itr != pieces.end(); ++itr)
	{
		if (log) {
			Utils::LogNotice("PPlayer::GetAvailablePiece")
				<< "Player:" << itr->second->GetFactionName()
				<< ":" << itr->second->GetFigureName()
				<< "-" << itr->first << endl;
		}

		std::string token = itr->first.substr(0, itr->first.find(codeSep));
		if (std::to_string(code) == token) {
			if (itr->second->IsAlive() && itr->second->IsPlayable())
				return itr->second;
		}
	}

	return NULL;
}

bool Player::StartMove()
{
	isMoving = true;
	Utils::LogNotice("Player::StartMove") << factionName << std::endl;
	return true;
}

void Player::StopMove()
{
	isMoving = false;
	moveCount++;
	Utils::LogNotice("Player::StopMove") << factionName << std::endl;
}