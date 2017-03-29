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
 *  Date:2016/9/4 0:22
 *
 *  Summary:游戏事件代理
 *  
 ******************************************************************************/
#pragma once
#include "IEvent.h"

/** @brief	A game event delegate. */
class GameEventManager;
//请记住名称，否则在派发事件时，如果没有名字将无法收到事件
class GameEventDelegate : public IEventDelegate
{
public:
	GameEventDelegate();
	virtual ~GameEventDelegate();

	virtual void onEvent(std::string szEventName, const vector<GValue>& params) = 0;
};