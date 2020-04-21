// GameObjectManager.cpp
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

#include "GameObjectManager.h"

GameObjectManager::GameObjectManager()
{
}

GameObjectManager::~GameObjectManager()
{
	std::for_each(mGameObjects.begin(), mGameObjects.end(), GameObjectDeallocator());
}

void GameObjectManager::Add(std::string name, GameObject* gameObject)
{
	mGameObjects.insert(std::pair<std::string, GameObject*>(name, gameObject));
}

void GameObjectManager::Remove(std::string name)
{
	// Finds the game object by name and then deletes the 
	std::map<std::string, GameObject*>::iterator pair = mGameObjects.find(name);
	if (pair != mGameObjects.end())
	{
		delete pair->second;
		mGameObjects.erase(pair);
	}
}

GameObject* GameObjectManager::GetObject(std::string name) const
{
	std::map<std::string, GameObject*>::const_iterator pair = mGameObjects.find(name);
	if (pair == mGameObjects.end())
		return NULL;

	return pair->second;
}

void GameObjectManager::DrawObjects(sf::RenderWindow& window)
{
	std::map<std::string, GameObject*>::const_iterator itr = mGameObjects.begin();
	while (itr != mGameObjects.end())
	{
		itr->second->Draw(window);
		itr++;
	}
}

void GameObjectManager::UpdateObjects(float deltaTime)
{
	std::map<std::string, GameObject*>::const_iterator it = mGameObjects.begin();
	
	while (it != mGameObjects.end())
	{
		it->second->Update(deltaTime);
		it++;
	}
}