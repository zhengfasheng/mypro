#include "CTestObject.h"
#include "CCPlatformMacros.h"

void CTestObject::onEvent(std::string szEventName, const vector<GValue>& params)
{
	CCLOG("receive notify name : %s , my id %u , name : %s", szEventName.data(),getObjectID(),getObjectName().data());

}

