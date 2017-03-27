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
 *  Date:2016/7/31 14:53
 *
 *  Summary:��Դ������
 *  
 ******************************************************************************/
#pragma once

#include "IManager.h"

/** @brief	Manager for resources. */
class ResourceManager final : public IManager
{
public:
	~ResourceManager();
	DEFINE_MANAGER(ResourceManager);
	virtual void init() override;
	virtual void release() override;

private:

	virtual void addSearchPath();

	void onResourceComplete(float fPercent);

	ResourceManager();
};
