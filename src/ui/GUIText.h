// GUIText.h
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
#include "../core/GameObject.h"

class GUIText : public GameObject
{
public:
	GUIText();
	~GUIText();

	void Update(float dt);
	void Draw(sf::RenderWindow & win);
	sf::Text GetText() const { return text; }
	inline void SetText(sf::String& s) { text.setString(s); }
	inline void SetFont(sf::Font& f) { text.setFont(f); }
	inline void SetLabel(sf::String& s) { label = s; }
	inline void SetInfo(sf::String& s) { infoText = s; }
	inline void SetPosition(float x, float y) { text.setPosition(x, y); }
	inline void SetPosition(sf::Vector2f p) { text.setPosition(p); }

private:
	sf::Text text;
	sf::String label;
	sf::String infoText;
};