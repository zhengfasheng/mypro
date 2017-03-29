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
 *  Date:2016/9/4 15:04
 *
 *  Summary:游戏事件接口
 *  
 ******************************************************************************/
#pragma once
#include "GameCommon.h"

template<typename _EventType> class IEvent
{
public:
	explicit IEvent(const _EventType& type , void* data )
		:m_data(data),m_type(type){}

	virtual ~IEvent(){}

	virtual void* getData() final { return m_data; }

	template< typename class _DataType>
	_DataType getData() { return (_DataType)m_data; }

	virtual _EventType getType() final { return m_type; }

private:
	void* m_data;
	_EventType m_type;
};

class GameEventManager;
class IEventDelegate
{
public:
	IEventDelegate();
	virtual ~IEventDelegate();

	const size_t getObjectID() const { return m_nID; }
	void setObjectName(const std::string& szObjectName) { m_szObjectName = szObjectName; }
	const string& getObjectName() const { return m_szObjectName; }

protected:

	/** @brief	对象的唯一标识 */
	size_t m_nID;
	std::string m_szObjectName;

	friend class GameEventManager;
};