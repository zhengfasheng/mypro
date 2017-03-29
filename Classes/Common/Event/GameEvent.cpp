#include "GameEvent.h"
#include "GameEventManager.h"

GameEventDelegate::GameEventDelegate()
{
	static unsigned int uObjectCount = 0;
	m_nID = ++uObjectCount;
	GameEventManager::getInstance()->addObject(this);
}

GameEventDelegate::~GameEventDelegate()
{
	GameEventManager::getInstance()->removeObject(this);
}

