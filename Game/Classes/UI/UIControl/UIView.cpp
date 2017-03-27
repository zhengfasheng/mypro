#include "UIView.h"
#include "UIObject.h"

CUIView::CUIView(CUIObject* pOwner)
	:m_pOwnerObject(pOwner)
{

}

CUIView::~CUIView()
{
	m_pOwnerObject = nullptr;
}

void CUIView::show()
{

}

void CUIView::hide()
{

}

bool CUIView::isShow()
{
	return false;
}

bool CUIView::isShowEnd()
{
	return true;
}

bool CUIView::isHideEnd()
{
	return false;
}

void CUIView::onEvent(string szEventName, const vector<GValue> params)
{

}

void CUIView::destory()
{

}

void CUIView::enableTouch()
{

}

void CUIView::disableTouch()
{

}

void CUIView::onKeyboardBack()
{

}

bool CUIView::isEnableKeyboardBack()
{
	return false;
}
