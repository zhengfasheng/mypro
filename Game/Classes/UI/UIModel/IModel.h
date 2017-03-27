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
 *  Date:2016/11/12 11:23
 *
 *  Summary:Declares the IModel interface
 *  
 MVC 模式结构
 MVC 模式将应用分为模型、视图和控制器三个部分：

 1. 视图：数据的展现。
 视图是用户看到并与之交互的界面。视图向用户显示相关的数据，并能接收用户的输入数据，
 但是它并不进行任何实际的业务处理。视图可以向模型查询业务状态，但不能改变模型。
 视图还能接受模型发出的数据更新事件，从而对用户界面进行同步更新。

 2. 模型：应用对象。
 模型是应用程序的主体部分。 模型代表了业务数据和业务逻辑； 
 当数据发生改变时，它要负责通知视图部分；一个模型能为多个视图提供数据。
 由于同一个模型可以被多个视图重用，所以提高了应用的可重用性。

 3. 控制器：逻辑处理、控制实体数据在视图上展示、调用模型处理业务请求。
 当 Web 用户单击 Web 页面中的提交按钮来发送 HTML 表单时，控
 制器接收请求并调用相应的模型组件去处理请求，然后调用相应的视图来显示模型返回的数据。

 MVC 模式运行机制
 如图 2.2 所示为 MVC 模式运行机制：


 在 MVC 模式中，Web 用户向服务器提交的所有请求都由控制器接管。接受到请求之后，控制器负责决定应该调用哪个模型来进行处理；然后模型根据用户请求进行相应的业务逻辑处理，并返回数据；最后控制器调用相应的视图来格式化模型返回的数据，并通过视图呈现给用户。

 *  
 ******************************************************************************/
#pragma once

class IViewBase;
class IModel
{
public:
	IModel():m_bIsValid(false){}
	virtual ~IModel(){}

	/**
	 * @brief	当前的模型是否有效
	 *
	 * @return	true if valid, false if not.
	 */

	virtual bool isValid() final
	{
		return m_bIsValid;
	}

	virtual void setValid( bool bIsVaild ) final
	{
		m_bIsValid = bIsVaild;
	}

protected:

	bool m_bIsValid;
};