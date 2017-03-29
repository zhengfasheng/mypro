#include "UIObjectManager.h"
#include "UIObjectFactory.h"

IMPLEMENT_MANAGER(UIObjectManager);

UIObjectManager::UIObjectManager()
{

}

UIObjectManager::~UIObjectManager()
{

}

void UIObjectManager::init()
{

}

void UIObjectManager::release()
{
	for (auto it = m_pObjects.begin(); it != m_pObjects.end(); ++it)
	{
		auto &pUIObject = it->second;
		if ( pUIObject )
		{
			pUIObject->destory();
		}
	}
}

void UIObjectManager::release(UIObjectID objID)
{
	auto pUIObject = getUIObject(objID,false);
	if ( pUIObject )
	{
		pUIObject->destory();
	}
}


void UIObjectManager::show(UIObjectID objID)
{
	auto pUIObject = getUIObject(objID);
	if ( pUIObject )
	{
		pUIObject->show();
	}
}

void UIObjectManager::hide(UIObjectID objID)
{
	auto pUIObject = getUIObject(objID,false);
	if ( pUIObject )
	{
		pUIObject->hide();
	}
}

void UIObjectManager::setEvent(UIObjectID objID, const string& szEventName, const vector<GValue>& params)
{
	if ( objID == UIObjectID::Max )//向所有界面派发事件
	{
		for (auto it = m_pObjects.begin(); it != m_pObjects.end(); ++it )
		{
			auto pUIObject = it->second;
			if ( pUIObject )
			{
				pUIObject->onEvent(szEventName, params);
			}
		}
	}
	else
	{
		auto pUIObject = getUIObject(objID,false);
		if ( pUIObject )
		{
			pUIObject->onEvent(szEventName, params);
		}
	}
}

void UIObjectManager::setEvent(UIObjectID objID, const string& szEventName,
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
	setEvent(objID, szEventName, { param1, param2, param3, param4, param5, param6, param7, param8, param9, param10 });
}

void UIObjectManager::showOrHide(UIObjectID objID)
{
	auto pUIObject = getUIObject(objID,false);
	if ( pUIObject )
	{
		if ( pUIObject->isShow() )
		{
			pUIObject->hide();
		}
		else
		{
			pUIObject->show();
		}
	}
	else
	{
		//创建一个
		pUIObject = createUIObject(objID);
		if ( pUIObject )//刚创建出来的，直接显示就行了
		{
			pUIObject->show();
		}
	}
}

CUIObject* UIObjectManager::getUIObject(UIObjectID objID , bool bIsNotFindCreateTheObject /* = true */ )
{
	auto it = m_pObjects.find(objID);
	if ( it != m_pObjects.end() )
	{
		return it->second;
	}
	//找不到，创建一个
	if ( bIsNotFindCreateTheObject )
	{
		return createUIObject(objID);
	}
	return nullptr;
}

void UIObjectManager::destory()
{
	for (auto it = m_pObjects.begin(); it != m_pObjects.end(); ++it)
	{
		auto &pUIObject = it->second;
		if ( pUIObject )
		{
			pUIObject->destory();
			delete pUIObject;
			pUIObject = nullptr;
		}
	}
	m_pObjects.clear();
}

void UIObjectManager::destory(UIObjectID objID)
{
	auto it = m_pObjects.find(objID);
	if ( it != m_pObjects.end() )
	{
		auto pUIOjbect = it->second;
		if ( pUIOjbect )
		{
			pUIOjbect->destory();
			delete pUIOjbect;
			pUIOjbect = nullptr;
		}
		m_pObjects.erase(it);
	}
}

CUIObject* UIObjectManager::createUIObject(UIObjectID objID)
{
	if (objID <= UIObjectID::Min || objID >= UIObjectID::Max)
	{
		CCLOG("this ui object id invaild , the id %d", (int)objID);
		return nullptr;
	}
	auto viewID = UIObjectFactory::getInstance()->getConfig(objID);
	if (viewID <= UIViewID::Min || viewID >= UIViewID::Max)
	{
		return nullptr;
	}

	CUIObject* pUIObject = UIObjectFactory::getInstance()->createUIObject((int)objID);
	if ( pUIObject )
	{
		pUIObject->m_uiObjectID = objID;
		pUIObject->m_uiViewID = viewID;
	}

	return pUIObject;
}




