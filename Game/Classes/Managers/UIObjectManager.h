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
 *  Date:2016/7/31 18:03
 *
 *  Summary:UI对象管理器
 *  
 ******************************************************************************/
#pragma once

#include "IManager.h"
#include "UIConfig.h"
#include "UIObject.h"

class UIObjectManager final : public IManager
{
public:
	~UIObjectManager();
	DEFINE_MANAGER_NOT_IMPLEMENT_DESTORY(UIObjectManager);
	virtual void init() override;
	/** @brief	释放所有界面视图，界面对象仍然保留 */
	virtual void release() override;

	/**
	 * @brief	释放指定界面视图
	 *
	 * @param	objID	界面对象id
	 */

	void release(UIObjectID objID) ;

	/** @brief	销毁界面（包括界面对象及界面视图 ） */
	virtual void destory() override;

	/**
	 * @brief	销毁指定界面
	 *
	 * @param	objID	界面对象id
	 */

	void destory(UIObjectID objID);

	/**
	 * @brief	显示界面
	 *
	 * @param	id	界面id
	 */

	void show(UIObjectID objID);

	/**
	 * @brief	隐藏界面
	 *
	 * @param	id	界面id
	 */

	void hide(UIObjectID objID);

	/**
	 * @brief	显示或隐藏界面
	 *
	 * @param	objID	界面对象id
	 */

	void showOrHide(UIObjectID objID);

	/**
	* @brief	界面事件派发.
	*
	* @param	params	事件参数.
	*
	* @param	objID	事件名称.
	*/
	void setEvent(UIObjectID objID, const string& szEventName, const vector<GValue>& params);

	void setEvent(
		UIObjectID objID,
		const string& szEventName, 
		const GValue& param1 = GValue::Null,
		const GValue& param2 = GValue::Null,
		const GValue& param3 = GValue::Null,
		const GValue& param4 = GValue::Null,
		const GValue& param5 = GValue::Null,
		const GValue& param6 = GValue::Null,
		const GValue& param7 = GValue::Null,
		const GValue& param8 = GValue::Null,
		const GValue& param9 = GValue::Null,
		const GValue& param10 = GValue::Null
		);

	/**
	 * @brief	得到界面对象.
	 *
	 * @param	objID					 	界面对象id.
	 * @param	bIsNotFindCreateTheObject	(Optional) true if this object is not find create the
	 * 										object.
	 *
	 * @return	null if it fails, else the user interface object.
	 */

	CUIObject* getUIObject(UIObjectID objID , bool bIsNotFindCreateTheObject = true );

private:

	/**
	 * @brief	创建指定的界面对象
	 *
	 * @param	objID	界面对象id
	 *
	 * @return	null if it fails, else the new user interface object.
	 */

	CUIObject* createUIObject(UIObjectID objID);

private:
	UIObjectManager();

	map<UIObjectID, CUIObject*> m_pObjects;

};