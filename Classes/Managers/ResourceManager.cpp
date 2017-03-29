#include "ResourceManager.h"
#include "cocos2d.h"
#include "cocostudio/CCArmatureDataManager.h"
#include "HelloWorldScene.h"

USING_NS_CC;
using namespace cocostudio;

IMPLEMENT_MANAGER(ResourceManager);
ResourceManager::ResourceManager()
{

}

ResourceManager::~ResourceManager()
{

}

void ResourceManager::init()
{
	addSearchPath();
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("ui.plist");
	ArmatureDataManager::getInstance()->addArmatureFileInfoAsync("armature/bear.ExportJson", this, CC_SCHEDULE_SELECTOR(ResourceManager::onResourceComplete));
}

void ResourceManager::release()
{

}

void ResourceManager::onResourceComplete(float fPercent)
{
	// create a scene. it's an autorelease object
	auto scene = HelloWorld::createScene();

	// run
	Director::getInstance()->runWithScene(scene);
}

void ResourceManager::addSearchPath()
{
	FileUtils::getInstance()->addSearchPath("res");
}


