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
 *  Date:2016/9/4 14:55
 *
 *  Summary:服务器事件
 *  
 ******************************************************************************/
#pragma once

#include "IEvent.h"

enum class ServerEventType
{
	Common,
};

class ServerEvent : public IEvent<ServerEventType>
{
public:
	typedef IEvent<ServerEventType> _Myt;
	explicit ServerEvent(const ServerEventType& type, void* data )
		:_Myt(type, data)
	{
		
	}

	virtual ~ServerEvent(){}
};


class ServerEventDelegate : public IEventDelegate
{
public:

	virtual void onEvent( const ServerEvent& serverEvent ) = 0;
};

