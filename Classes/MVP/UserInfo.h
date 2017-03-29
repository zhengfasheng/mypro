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
 *  Date:2016/11/16 22:03
 *
 *  Summary:Declares the user information class
 *  
 ******************************************************************************/
#pragma once
#include <string>

class UserInfo
{
public:
	UserInfo(const std::string& szName  = "" , const std::string& szPassward = "")
	:m_szName(szName)
	,m_szPassward(szPassward)
	{
	}
	~UserInfo(){}

	void setName(const std::string& szName)
	{
		m_szName = szName;
	}

	const std::string& getName() const
	{
		return m_szName;
	}

	void setPassward(const std::string& szPassward)
	{
		m_szPassward = szPassward;
	}

	const std::string& getPassward() const
	{
		return m_szPassward;
	}

private:

	std::string m_szName;
	
	std::string m_szPassward;
	
};