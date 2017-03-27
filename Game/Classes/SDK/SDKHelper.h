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
 *  Date:2016/7/31 17:52
 *
 *  Summary:ƽ̨sdk�ӿڶ���,��ƽ̨�̳е���ʵ��
 *  
 ******************************************************************************/
#pragma once

#include "IManager.h"

class SDKHelper : public IManager
{
public:
	virtual ~SDKHelper();
	DEFINE_MANAGER(SDKHelper);
	virtual void init() override{}
	virtual void release() override{}

	virtual void login();

	virtual void logout();

protected:
	SDKHelper();
};