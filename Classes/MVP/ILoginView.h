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
 *  Date:2016/11/16 21:55
 *
 *  Summary:Declares the ILoginView interface
 *  
 ******************************************************************************/
#pragma once

class ILoginView
{
public:
	ILoginView(){}
	virtual ~ILoginView(){}

	virtual void onClearText() = 0;

	virtual void onLoginResult(bool bIsSuccess, int code) = 0;
};