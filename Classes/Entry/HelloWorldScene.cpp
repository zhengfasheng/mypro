#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameCommon.h"
#include "UIRichText.h"
#include "CTestObject.h"
#include "GameEventManager.h"
#include "ServerEvent.h"
#include "Any.h"
#include "UIView/UIViewManager.h"
#include "LoginView.h"


USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    /**  you can create scene with following comment code instead of using csb file.
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    **/
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);

	auto pBtn = (ui::Button*)rootNode->getChildByName("btn");

	auto pSprite = Sprite::create("grossini_dance_01.png");
	EventListenerTouchOneByOne* pListener = nullptr;
	if (pSprite)
	{
		rootNode->addChild(pSprite);
		pSprite->setPosition(Vec2(rootNode->getContentSize().width / 2, rootNode -> getContentSize().height / 2));

		pListener = EventListenerTouchOneByOne::create();
		pListener->setSwallowTouches(false);
		pListener->onTouchBegan = [pListener](Touch*, Event*)->bool{
			return true;
		};
		pListener->onTouchMoved = [](Touch*, Event*){
		};
		pListener->onTouchEnded = [](Touch*, Event*){
		};
		_eventDispatcher->addEventListenerWithSceneGraphPriority(pListener, pSprite);
	}

	if ( pBtn )
	{
		pBtn->addClickEventListener([this, pListener,pSprite](Ref* pSender){
			
			//pSprite->removeFromParent();
			CCLOG("%d", pListener->getReferenceCount());
			_eventDispatcher->removeEventListener(pListener);

			/*auto pLoginView = LoginView::create();
			if ( pLoginView )
			{
			pLoginView->show();
			}*/

			/*auto pGameUserView = UIViewManager::getInstance()->getGameUserView();
			if ( pGameUserView )
			{
				pGameUserView->show();
			}*/

		});
	}

	


	/*auto pName = Label::createWithSystemFont("", "", 26);
	rootNode->addChild(pName);

	pName->setPosition(rootNode->getContentSize().width / 2, rootNode->getContentSize().height / 2);
	std::vector<GValue> params;
	auto v1 = GValue("22");
	auto v2 = GValue(4);

	auto v3 = GValue(456.56677).setFormatString("%0.3f");
	v3.setFormatString("%.3f");
	const GValue v4 = std::move(v3);
	params.push_back(v1);
	params.push_back(v2);
	//params.push_back(v4);
	//params.push_back(v2);

	//string vec = Language::getInstance()->getStringWithParam("Activity.pay_feedback.format", params);
	string vec = Language::getInstance()->getStringWithParam("Activity.pay_feedback.format", { "222", 4,v3 });
	string szStr = "";
	for (size_t i = 0; i < vec.size(); i++)
	{
		szStr += vec[i];
	}

	auto format = Language::getInstance()->formatString("%s,%d,%f", { "zheng", 23, 45.6 });

	//pName->setString(GBKToUtf8(pData->arr[1]));
	pName->setString(GBKToUtf8(szStr));

	//std::string str = fmt::format("djhfgadshg {} fdskhf {},s---{}-+++{:.3f}",45264536453,"fdhjgkahsg",34.5);
	
	auto szRet = Language::getInstance()->getStringWithParam("Activity.pay_feedback.format","222",33,334.65);
	pName->setString(GBKToUtf8(szRet));

	//DatabaseManager::getInstance()->release();
	auto pRich = UI::UIRichText::create(Language::getInstance()->getString("common.text"));
	//pRich->ignoreContentAdaptWithSize(false);
	//pRich->ignoreContentAdaptWithHeight(true);
	//pRich->setContentSize(Size(200, 30));
	//pRich->setCutType(UI::UIRichText::UP);
	//pRich->forceDoLayout();
	this->addChild(pRich);

	pRich->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);

	pRich->setPosition(Vec2(getContentSize().width / 2, 100));
	*/
	
    return true;
}
