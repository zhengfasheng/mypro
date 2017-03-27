#include "GameEventManager.h"

IMPLEMENT_SINGTON(GameEventManager);

GameEventManager::GameEventManager()
{

}

GameEventManager::~GameEventManager()
{
	m_gameEventObjects.clear();
}

void GameEventManager::addObject(GameEventDelegate* pObj)
{
	m_gameEventObjects[pObj->m_nID] = pObj;
}

void GameEventManager::removeObject(GameEventDelegate* pObj)
{
	m_gameEventObjects.erase(pObj->m_nID);
}

void GameEventManager::dispathGameEvent(const size_t& nObjectID, const string& szEventName, const vector<GValue>& params)
{
	if (nObjectID == GAME_EVENT_FOR_ALL)
	{
		for (auto it = m_gameEventObjects.begin(); it != m_gameEventObjects.end(); ++it)
		{
			auto pObject = it->second;
			if ( pObject )
			{
				pObject->onEvent(szEventName, params);
			}
		}
	}
	else
	{
		auto it = m_gameEventObjects.find(nObjectID);
		if (it != m_gameEventObjects.end())
		{
			auto pObject = it->second;
			if ( pObject )
			{
				pObject->onEvent(szEventName, params);
			}
		}
	}
}

void GameEventManager::dispathGameEvent(const size_t& nObjectID, const string& szEventName,
	const GValue& param1 /*= GValue::Null*/, 
	const GValue& param2 /*= GValue::Null*/, 
	const GValue& param3 /*= GValue::Null*/, 
	const GValue& param4 /*= GValue::Null*/, 
	const GValue& param5 /*= GValue::Null*/,
	const GValue& param6 /*= GValue::Null*/,
	const GValue& param7 /*= GValue::Null*/, 
	const GValue& param8 /*= GValue::Null*/, 
	const GValue& param9 /*= GValue::Null*/, 
	const GValue& param10 /*= GValue::Null */)
{
	dispathGameEvent(nObjectID, szEventName, { param1, param2, param3, param4, param5, param6, param7, param8, param9, param10 });
}

void GameEventManager::dispathGameEvent(const std::string& szObjectName, const string& szEventName, const vector<GValue>& params)
{
	if (szObjectName.empty())
	{
		for (auto it = m_gameEventObjects.begin(); it != m_gameEventObjects.end(); ++it)
		{
			auto pObject = it->second;
			if (pObject)
			{
				pObject->onEvent(szEventName, params);
			}
		}
	}
	else
	{
		for (auto it = m_gameEventObjects.begin(); it != m_gameEventObjects.end(); ++it)
		{
			auto pObject = it->second;
			if ( pObject && pObject->getObjectName() == szObjectName )
			{
				pObject->onEvent(szEventName, params);
			}
		}
	}
}

void GameEventManager::dispathGameEvent(const std::string& szObjectName, const string& szEventName,
	const GValue& param1 /*= GValue::Null*/, 
	const GValue& param2 /*= GValue::Null*/, 
	const GValue& param3 /*= GValue::Null*/, 
	const GValue& param4 /*= GValue::Null*/, 
	const GValue& param5 /*= GValue::Null*/, 
	const GValue& param6 /*= GValue::Null*/, 
	const GValue& param7 /*= GValue::Null*/, 
	const GValue& param8 /*= GValue::Null*/, 
	const GValue& param9 /*= GValue::Null*/, 
	const GValue& param10 /*= GValue::Null */)
{
	dispathGameEvent(szObjectName, szEventName, { param1, param2, param3, param4, param5, param6, param7, param8, param9, param10 });
}

void GameEventManager::dispathUIEvent(UIObjectID objID, const string& szEventName, const vector<GValue>& params)
{
	UIObjectManager::getInstance()->setEvent(objID, szEventName, params);
}

void GameEventManager::dispathUIEvent(UIObjectID objID, const string& szEventName, 
	const GValue& param1 /*= GValue::Null*/, 
	const GValue& param2 /*= GValue::Null*/, 
	const GValue& param3 /*= GValue::Null*/, 
	const GValue& param4 /*= GValue::Null*/, 
	const GValue& param5 /*= GValue::Null*/, 
	const GValue& param6 /*= GValue::Null*/, 
	const GValue& param7 /*= GValue::Null*/, 
	const GValue& param8 /*= GValue::Null*/, 
	const GValue& param9 /*= GValue::Null*/, 
	const GValue& param10 /*= GValue::Null */)
{
	dispathUIEvent(objID, szEventName, { param1, param2, param3, param4, param5, param6, param7, param8, param9, param10 });
}



