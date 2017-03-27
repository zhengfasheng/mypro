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
 *  Date:2016/7/31 18:14
 *
 *  Summary:界面对象接口定义
 *	界面对象由界面视图(即真实的界面供给玩家操作的)
 *	这里把界面视图作为界面对象的和个属性，为了在界面隐藏的时清除界面
 *	而不删除用户在界面对象中存储的数据
 *  
 ******************************************************************************/
#pragma once
#include "UIConfig.h"
#include "UIEvent.h"
#include "GameCommon.h"

class CUIView;
class CUIObject
{
public:
	CUIObject();
	virtual ~CUIObject();

	/** @brief	显示界面 */
	virtual void show() ;

	/** @brief	隐藏界面,但不销毁 */
	virtual void hide();

	/**
	* @brief	界面是否显示
	*
	* @return	true 为显示.
	*/

	virtual bool isShow();

	/**
	* @brief	界面是否显示结束(当界面有进入动画时，只有动画完成后才算显示结束)
	*
	* @return	true 为显示结束
	*/

	virtual bool isShowEnd();

	/**
	* @brief	界面是否隐藏结束(当界面有退出动画时，只有动画完成后才算显示结束)
	*
	* @return	true 隐藏结束
	*/

	virtual bool isHideEnd() ;

	/**
	* @brief	处理界面事件
	*
	* @param	szEventName	事件名称
	* @param	params	   	事件参数
	*/

	virtual void onEvent(std::string szEventName, const vector<GValue>& params) ;

	/** @brief	销毁对象界面视图 */
	virtual void destory() ;

	/** @brief	允许接收触摸事件(在显示/隐藏完成后调用) */
	virtual void enableTouch() ;

	/** @brief	禁止接收触摸事件(在显示/隐藏过程中调用) */
	virtual void disableTouch()  ;

	/** @brief	当接收到手机返回按钮 */
	virtual void onKeyboardBack() ;

	/**
	* @brief	查询是否接收返回按钮键的事件
	*
	* @return	true 为接收
	*/

	virtual bool isEnableKeyboardBack();


private:

	CUIView* m_pUIView;

	UIObjectID m_uiObjectID;
	UIViewID m_uiViewID;
	friend class UIObjectManager;
};