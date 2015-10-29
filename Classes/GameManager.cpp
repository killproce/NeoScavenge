#include "GameManager.h"
#include "MainCharacter.h"

GameManager* GameManager::_instance = NULL;

GameManager::GameManager()
	:m_mainCharacter(NULL)
	,m_gameState(eNone)
{

}

GameManager* GameManager::getInstance()
{
	if (!_instance)
	{
		_instance = new GameManager;
	}
	return _instance;
}