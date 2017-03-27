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
 *  Date:2016/7/31 23:09
 *
 *  Summary:������ͼ
 *  
 ******************************************************************************/
#pragma once

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "GameCommon.h"

USING_NS_CC;
class CUIObject;
using namespace cocos2d::ui;

class CUIView : public Widget
{
public:
	CUIView(CUIObject* pOwner);
	virtual ~CUIView();
	/** @brief	��ʾ���� */
	virtual void show();

	/** @brief	���ؽ���,�������� */
	virtual void hide();

	/**
	* @brief	�����Ƿ���ʾ
	*
	* @return	true Ϊ��ʾ.
	*/

	virtual bool isShow();

	/**
	* @brief	�����Ƿ���ʾ����(�������н��붯��ʱ��ֻ�ж�����ɺ������ʾ����)
	*
	* @return	true Ϊ��ʾ����
	*/

	virtual bool isShowEnd();

	/**
	* @brief	�����Ƿ����ؽ���(���������˳�����ʱ��ֻ�ж�����ɺ������ʾ����)
	*
	* @return	true ���ؽ���
	*/

	virtual bool isHideEnd();

	/**
	* @brief	��������¼�
	*
	* @param	szEventName	�¼�����
	* @param	params	   	�¼�����
	*/

	virtual void onEvent(string szEventName, const vector<GValue> params);

	/** @brief	���ٶ��������Դ */
	virtual void destory();

	/** @brief	������մ����¼�(����ʾ/������ɺ����) */
	virtual void enableTouch();

	/** @brief	��ֹ���մ����¼�(����ʾ/���ع����е���) */
	virtual void disableTouch();

	/** @brief	�����յ��ֻ����ذ�ť */
	virtual void onKeyboardBack();

	/**
	* @brief	��ѯ�Ƿ���շ��ذ�ť�����¼�
	*
	* @return	true Ϊ����
	*/

	virtual bool isEnableKeyboardBack();

private:
	
	CUIObject* m_pOwnerObject;
};