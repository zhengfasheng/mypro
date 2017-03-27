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
 *  Date:2016/11/12 16:46
 *
 *  Summary:Declares the game user class
 *  
 ******************************************************************************/
#pragma once

#include "IModel.h"
#include <string>

class GameUser : public IModel
{
public:
	
	GameUser()
	{
		m_bIsValid = true;
	}
	~GameUser(){}

	enum class Sex
	{
		Male,
		Famale,
	};

	std::string getName(){ return m_szName; }
	Sex getSex(){ return m_sex; }

	void setName(const std::string & szName)
	{
		m_szName = szName;
	}

private:

	std::string m_szName;
	Sex m_sex;


};