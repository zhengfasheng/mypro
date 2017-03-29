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
 *  Summary:UI���󴴽�����
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
	 * @brief	����ui����.
	 *
	 * @param	objID	����id
	 *
	 * @return	null if it fails, else the new user interface object.
	 */

	CUIObject* createUIObject(const int& objID );

	/**
	 * @brief	����������ʾ��ͼ
	 *
	 * @param	nViewID	������ͼid
	 *
	 * @return	null if it fails, else the new user interface view.
	 */

	CUIView* createUIView(const int& nViewID, CUIObject* pOwner);

	/**
	* @brief	�õ������������
	*
	* @param	objID	�������id
	*
	* @return	��������
	*/

	UIViewID getConfig(UIObjectID uiObjectID );

private:
	UIObjectFactory();
};