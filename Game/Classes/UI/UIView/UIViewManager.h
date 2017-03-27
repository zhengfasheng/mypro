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
 *  Date:2016/11/12 18:12
 *
 *  Summary:Declares the view manager class
 *  
 ******************************************************************************/
#pragma once

#include "GameUserView.h"

class IViewBase;

class UIViewManager
{
public:
	UIViewManager():m_pGameUserView(nullptr){}
	~UIViewManager(){};

	static UIViewManager* getInstance();

	GameUserView* getGameUserView( )
	{
		if ( !m_pGameUserView )
		{
			m_pGameUserView = GameUserView::create();
		}
		return m_pGameUserView;
	}
	
private:

	GameUserView* m_pGameUserView;
};