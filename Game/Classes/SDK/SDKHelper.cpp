#include "SDKHelper.h"


SDKHelper* SDKHelper::m_pInstance = nullptr;
SDKHelper* SDKHelper::getInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = new SDKHelper;
	}
	return m_pInstance;
}

SDKHelper::SDKHelper()
{
	
}

SDKHelper::~SDKHelper()
{

}

void SDKHelper::login()
{

}

void SDKHelper::logout()
{

}

