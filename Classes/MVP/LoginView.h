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
 *  Date:2016/11/16 22:17
 *
 *  Summary:Declares the login view class
 *  
 ******************************************************************************/
#pragma once
#include "ui/CocosGUI.h"
#include "ILoginView.h"


USING_NS_CC;
using namespace cocos2d::ui;

class ILoginPresenter;

class LoginView : public ILoginView , public ui::Layout
{
public:
	LoginView();
	~LoginView();

	CREATE_FUNC(LoginView);

	virtual bool init() override;

	virtual void onClearText() override;
	virtual void onLoginResult(bool bIsSuccess, int code) override;

	virtual void show();

private:

	void onClick(Ref* pSender ,int nCode );

	Button* m_pLogin;
	Button* m_pClear;

	TextField* m_pName;
	TextField* m_pPassward;

	Text* m_pShow;

	ILoginPresenter* m_pLoginPresenter;
};