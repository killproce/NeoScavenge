#ifndef __GAME_MANAGER_H__
#define __GAME_MANAGER_H__

class MainCharacter;

class GameManager
{
public:
	static GameManager* getInstance();
	MainCharacter* getMainCharacter() { return m_mainCharacter; }
private:
	GameManager();
private:
	static GameManager* _instance;
	MainCharacter* m_mainCharacter;
};

#endif	// __GAME_MANAGER_H__