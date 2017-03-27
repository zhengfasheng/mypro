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
 *  Date:2016/7/31 23:47
 *
 *  Summary:界面事件定义
 *  
 ******************************************************************************/
#pragma once

enum class UIEventID
{
	ON_SHOW,//界面显示
	ON_SHOW_END,//界面显示结束
	ON_HIDE,//界面隐藏
	ON_HIDE_END,//界面隐藏结束
	ON_KEYBOARD_BACK,//接收到用户按下键盘返回
};

class CUIObject;
class CUIEvent final
{
public:
	CUIEvent(UIEventID eventID );
	~CUIEvent();

private:
	UIEventID m_nID;
};