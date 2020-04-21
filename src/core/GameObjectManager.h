// GameObjectManager.h
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

#include "GameObject.h"
#include "stdafx.h"

class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();

	// Adds a single game object
	void Add(std::string name, GameObject* object);
	// Removes a single game object
	void Remove(std::string name);
	
	inline int GetObjectCount()const { return (int)mGameObjects.size(); }
	GameObject *GetObject(std::string s) const;

	void DrawObjects(sf::RenderWindow &win);
	void UpdateObjects(float deltaTime);

private:
	// Will keep on memory a table mapping each object with its name
	std::map<std::string, GameObject*> mGameObjects;

	struct GameObjectDeallocator
	{
		void operator()(const std::pair<std::string, GameObject*>& p) const
		{
			delete p.second;
		}
	};
};

