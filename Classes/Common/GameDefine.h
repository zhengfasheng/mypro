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
 *  Date:2016/7/24 21:54
 *
 *  Summary:游戏数据定义
 *  
 ******************************************************************************/
#pragma once

#include "GameTypes.h"

#define DEFINE_STATIC_KEY( key )\
	static const char* key = #key
//static const char* s_userBackgroundMusicOpenStatusSaveKey = "s_userBackgroundMusicOpenStatusSaveKey";
DEFINE_STATIC_KEY(s_userBackgroundMusicOpenStatusSaveKey);
DEFINE_STATIC_KEY(s_userEffectsOpenStatusSaveKey);
DEFINE_STATIC_KEY(s_userBackgroundMusicVolumeSaveKey);
DEFINE_STATIC_KEY(s_userEffectsVolumeSaveKey);


