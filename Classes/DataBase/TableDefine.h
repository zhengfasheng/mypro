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
 *  Date:2016/7/29 22:28
 *
 *  Summary:��Ϸ���ݿ�ӿڶ��壬��Ҫ���صı�id�������������Ϣд�ڴ�
 *  
 ******************************************************************************/
#pragma once
#include "DataBaseDefine.h"

DBC_BEGIN

enum TableID
{
	TextConfig,//�������ñ�
	ImageConfig,//ͼƬ���ñ�
	AnimateConfig,//����֡�������ñ�
	ArmatureConfig,//�����������ñ�,��Ҫ��ǰ������Դ
};

static TableConfig g_tableConfig[] = {
	{ TableID::TextConfig, "TextConfig.txt", "config" },
	{ TableID::ImageConfig, "ImageConfig.txt", "config" },
	{ TableID::AnimateConfig, "AnimateConfig.txt","config" },
	TableConfig(TableID::ArmatureConfig, "ArmatureConfig.txt","config" ),
};

DBC_END