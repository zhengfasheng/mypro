#include "PlatformHelper.h"
#include "CCPlatformConfig.h"

#if ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
#include "android/AndroidHelper.h"
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
#include "ios/IOSHelper.h"
#endif


PlatformHelper* PlatformHelper::m_pInstance = nullptr;

PlatformHelper* PlatformHelper::getInstance()
{
	if ( m_pInstance == nullptr)
	{
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID )
		m_pInstance = new AndroidHelper;
#elif ( CC_TARGET_PLATFORM == CC_PLATFORM_IOS )
		m_pInstance = new IOSHelper;
#else
		m_pInstance = new PlatformHelper;
#endif
	}
	return m_pInstance;
}

PlatformHelper::PlatformHelper()
{

}

PlatformHelper::~PlatformHelper()
{

}

