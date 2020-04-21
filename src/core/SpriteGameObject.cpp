// SpriteGameObject.cpp
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

#include "SpriteGameObject.h"


SpriteGameObject::SpriteGameObject()
	:loaded(false), mPosition(sf::Vector2f::Vector2(0, 0))
{
	mPivot = EPivot::TopLeft;
}

SpriteGameObject::~SpriteGameObject()
{
}

void SpriteGameObject::Load(std::string filename)
{
	if (!mTexture.loadFromFile(filename))
	{
		std::cerr << "Error loading " << filename << std::endl;
		mFilename = "";
		loaded = false;
	}
	else
	{
		mFilename = filename;
		mSprite.setTexture(mTexture);
		loaded = true;
	}
}

void SpriteGameObject::Draw(sf::RenderWindow & renderWindow)
{
	if (loaded)
	{
		mTexture.setSmooth(true);
		renderWindow.draw(mSprite);
	}
}

void SpriteGameObject::Update(float deltaTime)
{
}

void SpriteGameObject::SetPosition(sf::Vector2f &position)
{
	switch (mPivot)
	{
	case SpriteGameObject::TopLeft:
		mPosition = position;
		break;
	case SpriteGameObject::TopRight:
		break;
	case SpriteGameObject::Center:
		mPosition.x = position.x + mTexture.getSize().x * 0.f;
		mPosition.y = position.y + mTexture.getSize().y * 0.f;
		break;
	case SpriteGameObject::BottomLeft:
		break;
	case SpriteGameObject::BottomRight:
		break;
	default:
		break;
	}

	if (loaded) {
		mSprite.setPosition(mPosition);
	}
}

void SpriteGameObject::SetPosition(float x, float y)
{
	switch (mPivot)
	{
	case SpriteGameObject::TopLeft:
		mPosition.x = x;
		mPosition.y = y;
		break;
	case SpriteGameObject::TopRight:
		break;
	case SpriteGameObject::Center:
		mPosition.x = x + mTexture.getSize().x * 0.f;
		mPosition.y = y + mTexture.getSize().y * 0.f;
		break;
	case SpriteGameObject::BottomLeft:
		break;
	case SpriteGameObject::BottomRight:
		break;
	default:
		break;
	}

	if (loaded) {
		mSprite.setPosition(mPosition);
	}
}

sf::Vector2f SpriteGameObject::GetPosition(void) const
{
	if (loaded) {
		return mSprite.getPosition();
	}
	else {
		return mPosition;
	}

	//return sf::Vector2f::Vector2(0, 0);
}

void SpriteGameObject::SetPivot(EPivot p)
{
	mPivot = p;
}

SpriteGameObject::EPivot SpriteGameObject::GetPivot(void) const
{
	return mPivot;
}
