#include "SoundManager.h"
#include "GameCommon.h"

IMPLEMENT_MANAGER(SoundManager);

SoundManager::SoundManager()
	:m_bIsBackMusicOn(true)
	, m_bIsEffectOn(true)
	, m_fBackgroundVolume(0.7f)
	, m_fEffectVolume(1.0f)
{

}

SoundManager::~SoundManager()
{

}

void SoundManager::init()
{
	readStatus();
}

void SoundManager::release()
{
	SimpleAudioEngine::getInstance()->end();
}

void SoundManager::preloadSounds()
{
	
}

void SoundManager::pauseEffects()
{
	if ( m_bIsEffectOn )
	{
		SimpleAudioEngine::getInstance()->pauseAllEffects();
	}
}

void SoundManager::resumeEffects()
{
	if ( !m_bIsEffectOn )
	{
		SimpleAudioEngine::getInstance()->resumeAllEffects();
	}
}

void SoundManager::pauseBackgroundMusic()
{
	if ( m_bIsBackMusicOn )
	{
		SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	}
}

void SoundManager::resumeBackgroundMusic()
{
	if ( !m_bIsBackMusicOn )
	{
		SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	}
}

bool SoundManager::isEffectsOn()
{
	return m_bIsEffectOn;
}

void SoundManager::setEffects(bool bIsOn /*= true*/)
{
	if ( bIsOn == m_bIsEffectOn )
	{
		return;
	}
	m_bIsEffectOn = bIsOn;
	if ( bIsOn )
	{
		resumeEffects();
	}
	else
	{
		pauseEffects();
	}
	saveStatus();
}

bool SoundManager::isBackMusicOn()
{
	return m_bIsBackMusicOn;
}

void SoundManager::setBackMusic(bool bIsOn /*= true*/)
{
	if ( bIsOn == m_bIsBackMusicOn )
	{
		return;
	}
	m_bIsBackMusicOn = bIsOn;
	if ( bIsOn )
	{
		resumeBackgroundMusic();
	}
	else
	{
		pauseBackgroundMusic();
	}
	saveStatus();
}

void SoundManager::playEffect(EffectID id)
{
	if (!m_bIsEffectOn) return;
	auto szSound = getEffect(id);
	if (szSound.empty()) return;
	playEffect(szSound);
}

void SoundManager::playBackMusic(const string& szMusic)
{
	if (!m_bIsBackMusicOn) return;
	if (szMusic.empty())return;
	SimpleAudioEngine::getInstance()->playBackgroundMusic(szMusic.data(), true);
}

void SoundManager::playEffect(const string& szAudio)
{
	if (!m_bIsEffectOn) return;
	if ( szAudio.empty() )return;
	SimpleAudioEngine::getInstance()->playEffect(szAudio.data());
}

void SoundManager::saveStatus()
{
	auto pUserDefault = cocos2d::UserDefault::getInstance();
	CCLOG("%s", pUserDefault->getXMLFilePath().data());
	CC_ASSERT(pUserDefault);
	pUserDefault->setBoolForKey(s_userEffectsOpenStatusSaveKey, m_bIsEffectOn);
	pUserDefault->setBoolForKey(s_userBackgroundMusicOpenStatusSaveKey, m_bIsBackMusicOn);
	pUserDefault->setFloatForKey(s_userBackgroundMusicVolumeSaveKey, m_fBackgroundVolume);
	pUserDefault->setFloatForKey(s_userEffectsVolumeSaveKey, m_fEffectVolume);
}

void SoundManager::readStatus()
{
	auto pUserDefault = cocos2d::UserDefault::getInstance();
	CCLOG("%s", pUserDefault->getXMLFilePath().data());
	CC_ASSERT(pUserDefault);
	m_bIsBackMusicOn = pUserDefault->getBoolForKey(s_userBackgroundMusicOpenStatusSaveKey, m_bIsBackMusicOn);
	m_bIsEffectOn = pUserDefault->getBoolForKey(s_userEffectsOpenStatusSaveKey, m_bIsEffectOn);
	m_fBackgroundVolume = pUserDefault->getFloatForKey(s_userBackgroundMusicVolumeSaveKey, m_fBackgroundVolume);
	m_fEffectVolume = pUserDefault->getFloatForKey(s_userEffectsVolumeSaveKey, m_fEffectVolume);
}

void SoundManager::setBackgroundMusicVolume(float fValue)
{
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(fValue);
}

float SoundManager::getBackgroundMusicVolume()
{
	return SimpleAudioEngine::getInstance()->getBackgroundMusicVolume();
}

void SoundManager::setEffectsVolume(float fValue)
{
	SimpleAudioEngine::getInstance()->setEffectsVolume(fValue);
}

float SoundManager::getEffectsVolume()
{
	return SimpleAudioEngine::getInstance()->getEffectsVolume();
}

std::string SoundManager::getEffect(EffectID id)
{
	return "";
}



