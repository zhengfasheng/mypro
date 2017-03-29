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
 *  Summary:游戏总管理器，管理所有的子管理器
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

	/** @brief	初始化所有的管理器，后面加上的管理器的初始化一定要加在里面初始化 */
	virtual void init() override;

	/** @brief	所有管理器的回收 */
	virtual void release() override;

	virtual void destory() override;

private:

private:
	GameManager();
};