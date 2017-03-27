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
 *  Date:2016/7/24 21:57
 *
 *  Summary:Declares the singleton class
 *  
 ******************************************************************************/
#pragma once

#include "GameTypes.h"


//这种方式的单列有缺点，构造函数不能私有化
template <typename T>
class Singleton
{
public:
	static T* m_pInstance;

public:
	Singleton(void)
	{
		m_pInstance = static_cast<T*>(this);
		assert(m_pInstance);
	}


	virtual ~Singleton(void)
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

	virtual void init(){}

	virtual void release(){}

	/**
	 * @brief	Gets the instance.
	 *
	 * @return	null if it fails, else the instance.
	 */

	static T* getInstance(){ assert(m_pInstance); return m_pInstance; }
};

/**
 * @brief	A macro that defines singleton init.
 *
 * @param	TYPE	The type.
 */

#define SINGLETON_INIT( TYPE )							\
template <>	 TYPE * Singleton< TYPE >::m_pInstance = new TYPE;	

