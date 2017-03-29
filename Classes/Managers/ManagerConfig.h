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
 *  Summary:���������ã���Ҫ�Գ�ʼ���й�
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

//�������붨����Min-Max֮�䣬�����˳��ֱ�Ӿ����˹������ĳ�ʼ��˳����ǰ���ȱ���ʼ��
enum class ManagerID
{
	//��Ϸ�ܹ�����
	GameManager,
	Min,
	//���ݿ�
	DataBase = Min,
	//���԰�
	Language,
	//��Դ
	Resource,
	//����
	Sound,
	//ƽ̨
	Platform,
	//SDK
	SDK,
	//UI������
	UIObjManager,
	Max,
};

//����Щ������ȡ�������ĺ�
GET_MANAGER_BEGAIN()

HANDLE_GET_MANAGER(DatabaseManager, ManagerID::DataBase);
HANDLE_GET_MANAGER(Language, ManagerID::Language);
HANDLE_GET_MANAGER(ResourceManager, ManagerID::Resource);
HANDLE_GET_MANAGER(SoundManager, ManagerID::Sound);
HANDLE_GET_MANAGER(PlatformHelper, ManagerID::Platform);
HANDLE_GET_MANAGER(SDKHelper, ManagerID::SDK);
HANDLE_GET_MANAGER(UIObjectManager, ManagerID::UIObjManager);

GET_MANAGER_END
