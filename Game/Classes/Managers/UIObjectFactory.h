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
 *  Date:2016/8/24 23:44
 *
 *  Summary:UI对象创建工厂
 *  
 ******************************************************************************/
#pragma once
#include "IManager.h"
#include "UIConfig.h"


class CUIObject;
class CUIView;
class UIObjectFactory final : public IManager
{
public:
	~UIObjectFactory();

	DEFINE_MANAGER(UIObjectFactory);

	/**
	 * @brief	创建ui对象.
	 *
	 * @param	objID	对象id
	 *
	 * @return	null if it fails, else the new user interface object.
	 */

	CUIObject* createUIObject(const int& objID );

	/**
	 * @brief	创建对象显示视图
	 *
	 * @param	nViewID	对象视图id
	 *
	 * @return	null if it fails, else the new user interface view.
	 */

	CUIView* createUIView(const int& nViewID, CUIObject* pOwner);

	/**
	* @brief	得到界面对象配置
	*
	* @param	objID	界面对象id
	*
	* @return	界面配置
	*/

	UIViewID getConfig(UIObjectID uiObjectID );

private:
	UIObjectFactory();
};