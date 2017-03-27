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
 *  Date:2016/7/24 21:56
 *
 *  Summary:��Ϸ�ܹ��������������е��ӹ�����
 *  
 ******************************************************************************/
#pragma once
#include "SoundManager.h"
#include "DatabaseManager.h"
#include "Language.h"
#include "ResourceManager.h"
#include "PlatformHelper.h"
#include "SDKHelper.h"
#include "UIObjectManager.h"

class GameManager final : public IManager
{
public:
	~GameManager();
	DEFINE_MANAGER_NOT_IMPLEMENT_DESTORY(GameManager);

	/** @brief	��ʼ�����еĹ�������������ϵĹ������ĳ�ʼ��һ��Ҫ���������ʼ�� */
	virtual void init() override;

	/** @brief	���й������Ļ��� */
	virtual void release() override;

	virtual void destory() override;

private:

private:
	GameManager();
};