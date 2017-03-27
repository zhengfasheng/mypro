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
 *  Date:2016/7/31 17:26
 *
 *  Summary:管理器配置，主要以初始化有关
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

//管理器请定义在Min-Max之间，这里的顺序直接决定了管理器的初始化顺序，在前的先被初始化
enum class ManagerID
{
	//游戏总管理器
	GameManager,
	Min,
	//数据库
	DataBase = Min,
	//语言包
	Language,
	//资源
	Resource,
	//声音
	Sound,
	//平台
	Platform,
	//SDK
	SDK,
	//UI管理器
	UIObjManager,
	Max,
};

//请在些处增获取管理器的宏
GET_MANAGER_BEGAIN()

HANDLE_GET_MANAGER(DatabaseManager, ManagerID::DataBase);
HANDLE_GET_MANAGER(Language, ManagerID::Language);
HANDLE_GET_MANAGER(ResourceManager, ManagerID::Resource);
HANDLE_GET_MANAGER(SoundManager, ManagerID::Sound);
HANDLE_GET_MANAGER(PlatformHelper, ManagerID::Platform);
HANDLE_GET_MANAGER(SDKHelper, ManagerID::SDK);
HANDLE_GET_MANAGER(UIObjectManager, ManagerID::UIObjManager);

GET_MANAGER_END
