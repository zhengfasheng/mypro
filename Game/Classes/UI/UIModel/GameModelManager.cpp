#include "GameModelManager.h"
#include "GameUser.h"

GameModelManager::GameModelManager()
{

}

GameModelManager::~GameModelManager()
{

}

GameModelManager* GameModelManager::getInstance()
{
	static GameModelManager* s_pInstance = nullptr;
	if ( !s_pInstance )
	{
		s_pInstance = new GameModelManager;
	}
	return s_pInstance;
}

IModel* GameModelManager::getModel(ModelID eModelID)
{
	auto it = m_models.find(eModelID);
	if ( it != m_models.end( ) )
	{
		return it->second;
	}
	else
	{
		return createModel(eModelID);
	}
}

IModel* GameModelManager::createModel(ModelID eModelID)
{
	switch (eModelID)
	{
	case ModelID::GameUser:
	{
		auto pGameUser = new GameUser;
		if ( pGameUser )
		{
			m_models[eModelID] = pGameUser;
		}
		return pGameUser;
	}
		break;
	default:
		break;
	}
	return nullptr;
}

