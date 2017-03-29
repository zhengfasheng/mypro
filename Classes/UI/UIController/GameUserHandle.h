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
 *  Date:2016/11/12 17:36
 *
 *  Summary:Declares the game user controller class
 *  
 ******************************************************************************/
#pragma once
#include "GameLogicDispatcher.h"

class IHandler
{
public:
	IHandler(){}
	virtual ~IHandler(){}
	virtual void execute(GameModuleEvent eModuleEvent ) = 0;
};

enum class GameUserHandleType
{
	SaveToServer,
	GetFromServer,
};

class GameUserHandle : public IHandler
{
public:
	GameUserHandle();
	~GameUserHandle();

	virtual void execute(GameModuleEvent eModuleEvent) override;

private:

	virtual void saverUserInfo();

	virtual void getUserInfo();

	

};