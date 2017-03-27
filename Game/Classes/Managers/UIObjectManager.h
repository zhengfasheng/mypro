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
 *  Summary:UI���������
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
	/** @brief	�ͷ����н�����ͼ�����������Ȼ���� */
	virtual void release() override;

	/**
	 * @brief	�ͷ�ָ��������ͼ
	 *
	 * @param	objID	�������id
	 */

	void release(UIObjectID objID) ;

	/** @brief	���ٽ��棨����������󼰽�����ͼ �� */
	virtual void destory() override;

	/**
	 * @brief	����ָ������
	 *
	 * @param	objID	�������id
	 */

	void destory(UIObjectID objID);

	/**
	 * @brief	��ʾ����
	 *
	 * @param	id	����id
	 */

	void show(UIObjectID objID);

	/**
	 * @brief	���ؽ���
	 *
	 * @param	id	����id
	 */

	void hide(UIObjectID objID);

	/**
	 * @brief	��ʾ�����ؽ���
	 *
	 * @param	objID	�������id
	 */

	void showOrHide(UIObjectID objID);

	/**
	* @brief	�����¼��ɷ�.
	*
	* @param	params	�¼�����.
	*
	* @param	objID	�¼�����.
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
	 * @brief	�õ��������.
	 *
	 * @param	objID					 	�������id.
	 * @param	bIsNotFindCreateTheObject	(Optional) true if this object is not find create the
	 * 										object.
	 *
	 * @return	null if it fails, else the user interface object.
	 */

	CUIObject* getUIObject(UIObjectID objID , bool bIsNotFindCreateTheObject = true );

private:

	/**
	 * @brief	����ָ���Ľ������
	 *
	 * @param	objID	�������id
	 *
	 * @return	null if it fails, else the new user interface object.
	 */

	CUIObject* createUIObject(UIObjectID objID);

private:
	UIObjectManager();

	map<UIObjectID, CUIObject*> m_pObjects;

};