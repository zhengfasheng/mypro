/******************************************************************************
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  Author:Zheng Fasheng
 *
 *  Email:zheng_fasheng@outlook.com
 *
 *  Date:2016/7/30 0:17
 *
 *  Summary:Declares the IManager interface
 *  
 ******************************************************************************/
#pragma once
#include "GameTypes.h"
#include "cocos2d.h"

/** @brief	所有管理者必须继承 */
class IManager : public cocos2d::Ref
{
public:
	virtual ~IManager(){}
protected:
	IManager(){}
public:

	/** @brief	管理器初始化 */
	virtual void init(){};
	/** @brief	清理管理器数据，在游戏返回登录等时 */
	virtual void release(){};
	/** @brief	销毁对象 , 一般不用，理论上是销毁单例*/
	virtual void destory(){};
};

/**
* @brief	A macro that defines implement singleton. suggest use
*
* @param	TYPE	The type.
*/

#define IMPLEMENT_MANAGER( TYPE )\
TYPE* TYPE::m_pInstance = nullptr;\
TYPE* TYPE::getInstance() \
{\
	if (m_pInstance == nullptr)\
				{\
		m_pInstance = new TYPE;\
				}\
	return m_pInstance;\
}

#define IMPLEMENT_SINGTON IMPLEMENT_MANAGER

#define DEFINE_SINGTON(TYPE)\
private:\
	static TYPE* m_pInstance;\
public:\
	static TYPE* getInstance()


#define DEFINE_MANAGER( TYPE )\
private:\
	static TYPE* m_pInstance;\
public:\
	static TYPE* getInstance();\
	virtual void destory() override\
	{\
		if(m_pInstance){ delete m_pInstance;} m_pInstance = nullptr; \
	}

#define DEFINE_MANAGER_NOT_IMPLEMENT_DESTORY( TYPE )\
private:\
	static TYPE* m_pInstance;\
public:\
	static TYPE* getInstance();


#define GET_MANAGER_BEGAIN()\
static IManager* getManager(ManagerID mgrID)\
{\
	IManager* pManager = nullptr;\
	switch (mgrID)\
	{

#define HANDLE_GET_MANAGER(TYPE,MANAGER_ID)\
	case MANAGER_ID:\
		pManager = TYPE::getInstance();\
		break

#define GET_MANAGER_END\
	}\
	if ( !pManager )\
	{\
		CCLOG("Not handle getManager , Please add to %s %s %d , the manager id: %d", __FILE__, __FUNCTION__, __LINE__,(int)mgrID);\
	}\
	return pManager;\
}