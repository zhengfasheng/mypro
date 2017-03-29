#include "UIObject.h"
#include "UIObjectFactory.h"
#include "UIView.h"

CUIObject::CUIObject()
	:m_pUIView(nullptr)
	, m_uiObjectID(UIObjectID::Max)
	, m_uiViewID(UIViewID::Max)
{

}

CUIObject::~CUIObject()
{
	destory();
}

void CUIObject::show()
{
	if ( m_pUIView )
	{
		if ( m_pUIView->isShow() )
		{
			return;
		}
		m_pUIView->show();
	}
	else
	{
		m_pUIView = UIObjectFactory::getInstance()->createUIView((int)m_uiViewID,this);
		if ( m_pUIView )
		{
			m_pUIView->retain();
			m_pUIView->show();
		}
		else
		{
			CCLOG("create view failure , view id %d", (int)m_uiViewID);
		}
	}
}

void CUIObject::hide()
{
	if ( m_pUIView && !m_pUIView->isShow() )
	{
		m_pUIView->hide();
	}
}

bool CUIObject::isShow()
{
	if ( m_pUIView )
	{
		return m_pUIView->isShow();
	}
	return false;
}

bool CUIObject::isShowEnd()
{
	if ( m_pUIView )
	{
		return m_pUIView->isShowEnd();
	}
	return false;
}

bool CUIObject::isHideEnd()
{
	if ( m_pUIView )
	{
		return m_pUIView->isHideEnd();
	}
	return true;
}

void CUIObject::onEvent(std::string szEventName, const vector<GValue>& params)
{
	if ( m_pUIView )
	{
		m_pUIView->onEvent(szEventName, params);
	}
}


void CUIObject::destory()
{
	if ( m_pUIView )
	{
		if ( m_pUIView->isShow() )
		{
			m_pUIView->hide();
		}
		m_pUIView->destory();
		m_pUIView->release();
		m_pUIView = nullptr;
	}
}

void CUIObject::enableTouch()
{
	if ( m_pUIView )
	{
		m_pUIView->enableTouch();
	}
}

void CUIObject::disableTouch()
{
	if ( m_pUIView )
	{
		m_pUIView->disableTouch();
	}
}

void CUIObject::onKeyboardBack()
{
	if ( m_pUIView )
	{
		m_pUIView->onKeyboardBack();
	}
}

bool CUIObject::isEnableKeyboardBack()
{
	if ( m_pUIView )
	{
		return m_pUIView->isEnableKeyboardBack();
	}
	return false;
}



