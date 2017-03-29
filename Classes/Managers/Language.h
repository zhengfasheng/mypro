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
 *  Date:2016/7/30 15:35
 *
 *  Summary:���԰�������
 *  
 ******************************************************************************/
#pragma once

#include "IManager.h"
#include "GameTypes.h"
#include "cocos2d.h"
#include "GValue.h"

USING_NS_CC;
/** @brief	���԰������� This class cannot be inherited. */
class Language final : public IManager
{
public:
	~Language();
	DEFINE_MANAGER(Language);

	virtual void init() override;

	virtual void release() override;

	/**
	 * @brief	ͨ��key�õ����԰�������
	 *
	 * @param	key			 	The key.
	 * @param	defaultString	(Optional) ��û�ҵ������ص�Ĭ��ֵ
	 *
	 * @return	������Ϣ
	 */

	string getString(const string& key , string defaultString = "" );

	/**
	* @brief	������Ҫ��������д�����ʱ������ݴ���Ĳ���ƴд�������ַ���
	* 			��:aaaa{%any}bbbb{%any}cccc{%any}ddddd
	* 			����getStringWithParam("com.title",{"add",23,45.6}) -> aaaaaddbbbb23cccc45.6ddddd;
	* 			�ǰ���˳����и�ֵ,���Ҫ���þ��ȣ����ڴ���GValue��������setFormatString������
	*
	* @param	key   	The key.
	* @param	params	�����б� ע������ݴ���Ĳ�����������һ����ʽ��
	* 					��{"",""}->%s%s {"",22.3}->%s%f
	*
	* @return	The string.
	*/

	string getStringWithParam(
		const string& key, 
		const vector<GValue>& params, 
		string defaultString = "");

	string getStringWithParam(
		const string& key,
		const GValue& param1 = GValue::Null,
		const GValue& param2 = GValue::Null,
		const GValue& param3 = GValue::Null,
		const GValue& param4 = GValue::Null,
		const GValue& param5 = GValue::Null,
		const GValue& param6 = GValue::Null,
		const GValue& param7 = GValue::Null,
		const GValue& param8 = GValue::Null,
		const GValue& param9 = GValue::Null,
		const GValue& param10 = GValue::Null,
		string defaultString = "");


	/**
	 * @brief	������Ҫ��������д�����ʱ������ݴ���Ĳ���ƴд�������ַ��� 
	 * 			��:aaaa{%any}bbbb{%any}cccc{%any}ddddd
	 *			����formatString(aaaa{%any}bbbb{%any}cccc{%any}ddddd,{"add",23,45.6}) -> aaaaaddbbbb23cccc45.6ddddd;
	 *
	 * @param [in,out]	szFormat	����ʽ�ַ���
	 * @param	params			 	�����б� ע������ݴ���Ĳ�����������һ����ʽ�� ��{"",""}->%s%s {"",22.3}->%s%f.
	 *
	 * @return	A string.
	 */

	string formatString(string szFormat, const vector<GValue>& params);
	string formatString(
		string szFormat,
		const GValue& param1 = GValue::Null,
		const GValue& param2 = GValue::Null,
		const GValue& param3 = GValue::Null,
		const GValue& param4 = GValue::Null,
		const GValue& param5 = GValue::Null,
		const GValue& param6 = GValue::Null,
		const GValue& param7 = GValue::Null,
		const GValue& param8 = GValue::Null,
		const GValue& param9 = GValue::Null,
		const GValue& param10 = GValue::Null);

	/**
	 * @brief	ͨ��key�õ����԰���������������
	 *
	 * @param	key	The key.
	 *
	 * @return	������������
	 */

	vector<string> getVector(const string& key);

	string getLocalFont();

private:

	Language();

	/**
	 * @brief	Searches for the first string.
	 *
	 * @param	keys	The keys.
	 *
	 * @return	The found string.
	 */

	string findString(const vector<string>& keys , string defaultString );

	/**
	 * @brief	Searches for the first vector.
	 *
	 * @param	keys		 	The keys.
	 * @param	defaultString	The default string.
	 *
	 * @return	The found vector.
	 */

	vector<string> findVector(const vector<string>& keys);

	/**
	 * @brief	Check key.
	 *
	 * @param	key	The key.
	 *
	 * @return	true if it succeeds, false if it fails.
	 */

	bool checkKey(const string& key , vector<string>& keys );

	/**
	 * @brief	Splits.
	 *
	 * @param	src				���з��ַ���.
	 * @param [in,out]	vect	�з���ɺ���ַ���.
	 * @param	values			�и�ֵ.
	 */

	void splitWithParam(string src,vector<string>& vect,vector<GValue> values);

	/**
	 * @brief	Creates split tokens.
	 *
	 * @param [in,out]	values	The values.
	 * @param [in,out]	tokens	The tokens.
	 */

	void createSplitTokens(vector<GValue>& values, vector<string>& tokens);

private:

	__Dictionary* m_pLanguage;
};