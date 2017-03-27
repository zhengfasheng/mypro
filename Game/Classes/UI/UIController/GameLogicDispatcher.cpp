#include "GameLogicDispatcher.h"
#include "GameUserHandle.h"


GameLogicDispatcher* GameLogicDispatcher::getInstance()
{
	static GameLogicDispatcher* pInstance = nullptr;
	if (!pInstance)
	{
		pInstance = new GameLogicDispatcher;
	}
	return pInstance;
}

void GameLogicDispatcher::dispatcher(GameModule eModule, GameModuleEvent eModuleEvent)
{
	switch (eModule)
	{
	case GameModule::GameUser:
	{
		GameUserHandle handler;
		handler.execute(eModuleEvent);
	}
		break;
	default:
		break;
	}
}

