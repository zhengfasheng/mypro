#include "UIViewManager.h"


UIViewManager* UIViewManager::getInstance()
{
	static UIViewManager* pManager = nullptr;
	if ( !pManager )
	{
		pManager = new UIViewManager;
	}
	return pManager;
}

