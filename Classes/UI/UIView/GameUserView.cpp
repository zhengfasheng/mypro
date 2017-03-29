#include "GameUserView.h"
#include "cocostudio\ActionTimeline\CSLoader.h"
#include "UIModel\GameUser.h"
#include "UIController/GameLogicDispatcher.h"
#include "UIModel/GameModelManager.h"

GameUserView::GameUserView()
	:m_pNameLabel(nullptr)
	, m_pSaveBtn(nullptr)
{
	m_pModel = new GameUser;
}

GameUserView::~GameUserView()
{
	
}

GameUserView* GameUserView::create()
{
	auto pRet = new GameUserView;
	if ( pRet && pRet->init() )
	{
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}
	return pRet;
}

bool GameUserView::init()
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!IView::init());

		auto rootNode = CSLoader::createNode("GameUserView.csb");

		addChild(rootNode);

		auto pRootPanel = rootNode->getChildByName("Panel_1");
		CC_BREAK_IF(!pRootPanel);

		auto pName = (Text*)pRootPanel->getChildByName("name");
		CC_BREAK_IF(!pName);
		m_pNameLabel = pName;

		auto pSaveBtn = (Button*)pRootPanel->getChildByName("save_btn");
		CC_BREAK_IF(!pSaveBtn);
		m_pSaveBtn = pSaveBtn;
		pSaveBtn->addClickEventListener([this](Ref* pSender){
			GameLogicDispatcher::getInstance()->dispatcher(GameModule::GameUser, GameModuleEvent::SaveUserInfoToServer);
		});

		auto pChangeBtn = (Button*)pRootPanel->getChildByName("change");
		CC_BREAK_IF(!pChangeBtn);
		pChangeBtn->addClickEventListener([this](Ref* pSender){
			auto pModel = GameModelManager::getInstance()->getModel<GameUser>(ModelID::GameUser);
			if ( pModel && pModel->isValid()  )
			{
				pModel->setName("zheng fa sheng");
			}
		});

		bRet = true;
	} while (0);
	return bRet;
}

void GameUserView::updateUI(IModel* pModel)
{
	auto pRealModel = dynamic_cast<GameUser*>(pModel);
	if ( pRealModel )
	{
		m_pNameLabel->setString(pRealModel->getName());
	}
}

void GameUserView::updateUI()
{
	auto pRealModel = dynamic_cast<GameUser*>(m_pModel);
	if (pRealModel)
	{
		m_pNameLabel->setString(pRealModel->getName());
	}
}

void GameUserView::show()
{
	GameLogicDispatcher::getInstance()->dispatcher(GameModule::GameUser, GameModuleEvent::GetUserInfoFromServer);
	Director::getInstance()->getRunningScene()->addChild(this, 100);
}

