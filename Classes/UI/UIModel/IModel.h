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
 MVC ģʽ�ṹ
 MVC ģʽ��Ӧ�÷�Ϊģ�͡���ͼ�Ϳ������������֣�

 1. ��ͼ�����ݵ�չ�֡�
 ��ͼ���û���������֮�����Ľ��档��ͼ���û���ʾ��ص����ݣ����ܽ����û����������ݣ�
 ���������������κ�ʵ�ʵ�ҵ������ͼ������ģ�Ͳ�ѯҵ��״̬�������ܸı�ģ�͡�
 ��ͼ���ܽ���ģ�ͷ��������ݸ����¼����Ӷ����û��������ͬ�����¡�

 2. ģ�ͣ�Ӧ�ö���
 ģ����Ӧ�ó�������岿�֡� ģ�ʹ�����ҵ�����ݺ�ҵ���߼��� 
 �����ݷ����ı�ʱ����Ҫ����֪ͨ��ͼ���֣�һ��ģ����Ϊ�����ͼ�ṩ���ݡ�
 ����ͬһ��ģ�Ϳ��Ա������ͼ���ã����������Ӧ�õĿ������ԡ�

 3. ���������߼���������ʵ����������ͼ��չʾ������ģ�ʹ���ҵ������
 �� Web �û����� Web ҳ���е��ύ��ť������ HTML ��ʱ����
 �����������󲢵�����Ӧ��ģ�����ȥ��������Ȼ�������Ӧ����ͼ����ʾģ�ͷ��ص����ݡ�

 MVC ģʽ���л���
 ��ͼ 2.2 ��ʾΪ MVC ģʽ���л��ƣ�


 �� MVC ģʽ�У�Web �û���������ύ�����������ɿ������ӹܡ����ܵ�����֮�󣬿������������Ӧ�õ����ĸ�ģ�������д���Ȼ��ģ�͸����û����������Ӧ��ҵ���߼��������������ݣ���������������Ӧ����ͼ����ʽ��ģ�ͷ��ص����ݣ���ͨ����ͼ���ָ��û���

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
	 * @brief	��ǰ��ģ���Ƿ���Ч
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