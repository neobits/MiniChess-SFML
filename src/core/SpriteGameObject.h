// SpriteGameObject.h
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
#include "stdafx.h"
#include "GameObject.h"

class SpriteGameObject : public GameObject
{
public:

	enum EPivot
	{
		TopLeft = 1, // default
		TopRight,
		Center,
		BottomLeft,
		BottomRight
	};

	SpriteGameObject();
	~SpriteGameObject();

	virtual void Load(std::string filename);
	virtual void Draw(sf::RenderWindow &window);
	virtual void Update(float deltaTime);

	virtual void SetPosition(sf::Vector2f &postion);
	virtual void SetPosition(float x, float y);
	virtual sf::Vector2f GetPosition(void) const;

	virtual void SetPivot(EPivot p);
	virtual EPivot GetPivot() const;

	virtual bool isLoaded() const { return loaded; }


protected:
	sf::Sprite& GetSprite() { return mSprite; }

private:
	sf::Sprite mSprite;
	sf::Texture mTexture;
	std::string mFilename;
	bool loaded;
	sf::Vector2f mPosition;
	EPivot mPivot;
};

