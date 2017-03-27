#include "GameUserHandle.h"
#include "UIView/UIViewManager.h"
#include "UIModel/GameUser.h"
#include "UIModel/GameModelManager.h"

GameUserHandle::GameUserHandle()
{

}

GameUserHandle::~GameUserHandle()
{

}

void GameUserHandle::saverUserInfo()
{
	//向服务器发送存储信息
	auto pGameUser = GameModelManager::getInstance()->getModel<GameUser>(ModelID::GameUser);
	CCLOG("name : %s", pGameUser->getName().data());
}

void GameUserHandle::getUserInfo()
{
	auto pGameUser = GameModelManager::getInstance()->getModel<GameUser>(ModelID::GameUser);
	if ( pGameUser )
	{
		pGameUser->setName("xxxxxxxxxx");
	}
	auto pGameUserView = UIViewManager::getInstance()->getGameUserView();
	if ( pGameUserView )
	{
		pGameUserView->updateUI(pGameUser);
	}
}

void GameUserHandle::execute(GameModuleEvent eModuleEvent)
{
	switch (eModuleEvent)
	{
	case GameModuleEvent::SaveUserInfoToServer:
		this->saverUserInfo();
		break;
	case GameModuleEvent::GetUserInfoFromServer:
		this->getUserInfo();
		break;
	default:
		break;
	}
}


