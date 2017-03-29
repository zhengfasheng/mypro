#include "UIObjectFactory.h"
#include "UIConfig.h"
#include "UIObject.h"


IMPLEMENT_MANAGER(UIObjectFactory);

#define GET_UI_OBJECT_BEGIN \
CUIObject* UIObjectFactory::createUIObject(const int& objID )\
{\
	switch( (UIObjectID)objID )\
	{\

#define GET_UI_OBJECT( objID , className ) \
	case objID:\
		return new className();\
		break\

#define GET_UI_OBJECT_END \
	default:\
		break;\
	}\
	return nullptr;\
}


#define GET_UI_VIEW_BEGIN \
CUIView* UIObjectFactory::createUIView(const int& viewID ,CUIObject* pOwner)\
{\
	switch( (UIViewID)viewID )\
	{\

#define GET_UI_VIEW( viewID , className ) \
	case viewID:\
		return className::create(pOwner);\
		break\

#define GET_UI_VIEW_END \
	default:\
		break;\
	}\
	return nullptr;\
}

#define GET_UI_CONFIG_BEGIN \
UIViewID UIObjectFactory::getConfig(UIObjectID uiObjectID )\
{\
	switch( uiObjectID )\
	{\

#define GET_UI_CONFIG( objID , viewID ) \
	case objID:\
		return viewID;\

#define GET_UI_CONFIG_END \
	default:\
		return UIViewID::Max;\
		break;\
	}\
}


UIObjectFactory::UIObjectFactory()
{

}

UIObjectFactory::~UIObjectFactory()
{

}



//界面对象跟界面的绑定
GET_UI_CONFIG_BEGIN

GET_UI_CONFIG(UIObjectID::Min, UIViewID::Min);

GET_UI_CONFIG_END


//对象创建绑定
GET_UI_OBJECT_BEGIN

GET_UI_OBJECT(UIObjectID::Min, CUIObject);

GET_UI_OBJECT_END


//界面创建绑定
GET_UI_VIEW_BEGIN


GET_UI_VIEW_END
