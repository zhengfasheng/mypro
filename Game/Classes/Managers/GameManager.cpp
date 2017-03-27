#include "GameManager.h"
#include "ManagerConfig.h"

IMPLEMENT_MANAGER(GameManager);

GameManager::GameManager()
{

}

GameManager::~GameManager()
{
	
}

void GameManager::init()
{
	for (int i = (int)ManagerID::Min; i < (int)ManagerID::Max;i++ )
	{
		auto pManager = getManager((ManagerID)i);
		if ( pManager )
		{
			pManager->init();
		}
	}
}

void GameManager::release()
{
	for (int i = (int)ManagerID::Min; i < (int)ManagerID::Max; i++)
	{
		auto pManager = getManager((ManagerID)i);
		if (pManager)
		{
			pManager->release();
		}
	}
}


void GameManager::destory()
{
	for (int i = (int)ManagerID::Min; i < (int)ManagerID::Max; i++)
	{
		auto pManager = getManager((ManagerID)i);
		if (pManager)
		{
			pManager->destory();
		}
	}

	CC_SAFE_DELETE(m_pInstance);
}

