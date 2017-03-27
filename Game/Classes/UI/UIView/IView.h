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
 *  Date:2016/11/12 16:53
 *
 *  Summary:Declares the IView interface
 *  
 ******************************************************************************/
#pragma once
#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

class IModel;

class IViewBase : public Layout
{

};

class IView : public IViewBase
{
public:
	IView():m_pModel(nullptr){}
	virtual ~IView(){}

	/**
	 * @brief	ͨ������ģ�͹������е�����ģ�͸��½���
	 * 			����������ģ������ͬ�ڸ�������ͬ
	 * 			����������ģ�Ͱ����ڱ�����
	 * 			������ӵ�����ģ�͹�������
	 *
	 * @param [in,out]	pModel	If non-null, the model.
	 */

	virtual void updateUI(IModel* pModel){}

	/** @brief	ͨ�������ڵ�����ģ�͸��½��� */
	virtual void updateUI(){}


	virtual void show(){}

	virtual IModel* getModel()
	{
		return m_pModel;
	}

protected:

	IModel* m_pModel;
};