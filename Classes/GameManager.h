#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

#include "public.h"

class MainCharacter;

class GameManager
{
public:
	static GameManager* getInstance();
	MainCharacter* getMainCharacter() { return m_mainCharacter; }
	void setMainCharacter(MainCharacter* character) { m_mainCharacter = character; }
	void setGameState(eGameState state) { m_gameState = state; }
	eGameState getGameState() { return m_gameState; }
private:
	GameManager();
private:
	static GameManager* _instance;
	MainCharacter* m_mainCharacter;
	eGameState m_gameState;
};

#endif	// __GAME_MANAGER_H__