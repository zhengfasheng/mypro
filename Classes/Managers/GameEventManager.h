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
 *  Date:2016/9/4 0:31
 *
 *  Summary:游戏事件总管理器,如果是针对UI界面，请使用UIObjectManager
 *  
 ******************************************************************************/
#pragma once

#include "GameEvent.h"
#include "UIObjectManager.h"
#include "ServerEvent.h"

#define GAME_EVENT_FOR_ALL 0
class GameEventManager final
{
public:
	DEFINE_SINGTON(GameEventManager);
	~GameEventManager();

	/**
	* @brief	GameEventDelegate对象事件 GAME_EVENT_FOR_ALL将对所有非界面对象发送
	*
	* @param	nObjectID  	Name of the object.
	* @param	szEventName	Name of the event.
	* @param	params	   	事件参数.
	*/

	void dispathGameEvent(const size_t& nObjectID, const string& szEventName, const vector<GValue>& params);

	void dispathGameEvent(
		const size_t& nObjectID,
		const string& szEventName,
		const GValue& param1 = GValue::Null,
		const GValue& param2 = GValue::Null,
		const GValue& param3 = GValue::Null,
		const GValue& param4 = GValue::Null,
		const GValue& param5 = GValue::Null,
		const GValue& param6 = GValue::Null,
		const GValue& param7 = GValue::Null,
		const GValue& param8 = GValue::Null,
		const GValue& param9 = GValue::Null,
		const GValue& param10 = GValue::Null
		);

	/**
	* @brief	GameEventDelegate对象事件 GAME_EVENT_FOR_ALL将对所有非界面对象发送
	*
	* @param	nObjectID  	Name of the object.
	* @param	szEventName	Name of the event.
	* @param	params	   	事件参数.
	*/

	void dispathGameEvent(const std::string& szObjectName, const string& szEventName, const vector<GValue>& params);

	void dispathGameEvent(
		const std::string& szObjectName,
		const string& szEventName,
		const GValue& param1 = GValue::Null,
		const GValue& param2 = GValue::Null,
		const GValue& param3 = GValue::Null,
		const GValue& param4 = GValue::Null,
		const GValue& param5 = GValue::Null,
		const GValue& param6 = GValue::Null,
		const GValue& param7 = GValue::Null,
		const GValue& param8 = GValue::Null,
		const GValue& param9 = GValue::Null,
		const GValue& param10 = GValue::Null
		);


	/**
	* @brief	界面事件派发.
	*
	* @param	params	事件参数.
	*
	* @param	objID	事件名称.
	*/
	void dispathUIEvent(UIObjectID objID, const string& szEventName, const vector<GValue>& params);

	void dispathUIEvent(
		UIObjectID objID,
		const string& szEventName,
		const GValue& param1 = GValue::Null,
		const GValue& param2 = GValue::Null,
		const GValue& param3 = GValue::Null,
		const GValue& param4 = GValue::Null,
		const GValue& param5 = GValue::Null,
		const GValue& param6 = GValue::Null,
		const GValue& param7 = GValue::Null,
		const GValue& param8 = GValue::Null,
		const GValue& param9 = GValue::Null,
		const GValue& param10 = GValue::Null
		);
	
private:

	void addObject(GameEventDelegate* pObj);
	void removeObject(GameEventDelegate* pObj);

private:
	GameEventManager();

	std::unordered_map<size_t, GameEventDelegate*> m_gameEventObjects;

	friend class GameEventDelegate;
};