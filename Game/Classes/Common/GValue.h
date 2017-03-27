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
 *  Date:2016/7/30 18:30
 *
 *  Summary:������������
 *  
 ******************************************************************************/
#pragma once
#include <string>
using namespace std;

class GValue final
{
public:

	static const GValue Null;

	GValue();

	enum class Type
	{
		NONE,//������
		INT, //����
		STRING,//�ַ���
		FLOAT,//float
		DOUBLE,
		PVOID,//void*������
		BOOL,
		INT64,//long long
	};

	GValue(int nValue);

	GValue(float fValue);

	GValue(double fValue);

	GValue(bool bValue);

	GValue(void* pVoidValue);

	GValue(const string& szValue);

	GValue(const char* szValue);

	GValue(long long lValue);

	GValue(const GValue& value);

	GValue(GValue&& value);

	~GValue();

	GValue& operator=(int nValue);

	GValue& operator=(float fValue);

	GValue& operator=(double dValue);

	GValue& operator=(bool bValue);

	GValue& operator=(void* pVoidValue);

	GValue& operator=(const string& szValue);

	GValue& operator=(const char* szValue);

	GValue& operator=(long long lValue);

	GValue& operator=(const GValue& other);

	GValue& operator=(GValue&& other);

	bool operator==(const GValue& other);

	bool operator==(const GValue& other) const;

	bool operator!=(const GValue& other);

	bool operator!=(const GValue& other) const;

	Type getType() const { return m_type; }

	int asInt();

	long long asInt64();

	float asFloat();

	double asDouble();

	bool asBool();

	string asString();

	const char* asCString();

	void* asPointer();

	/**
	 * @brief	���ݵ�ǰ���ͷ���һ����ʽ�ַ�������float %s
	 *
	 * @return	��ʽ�ַ���
	 */

	string getFormatString() const;

	/**
	 * @brief	���ø�ʽ����֧������
	 *
	 * @param	szFormat	Describes the format to use.
	 *
	 * @return	A reference to a GValue.
	 */

	GValue& setFormatString(const string& szFormat);

	bool isNull() const { return m_type == Type::NONE; }

private:

	/**
	 * @brief	����ʽ���Ƿ���Ч
	 *
	 * @param	szFormat	��ʽ��
	 *
	 * @return	true if it succeeds, false if it fails.
	 */

	bool checkFormat(const string& szFormat);

	void clear();

	void reset(Type type);

	union Data
	{
		int        nValue;
		float      fValue;
		double     dValue;
		bool       bValue;
		void*      pVoid;
		long long  lValue;
		string*    pStringValue;
	};

	Data m_data;

	Type m_type;


	/** @brief Ϊ���������С����Ҫ��string��  
	/** �������ֻ���ڸ���ʱ����ָ��Ĭ�ϵĸ�ʽ��������Ĭ��%f,  
	/** ����Ҫ����ָ������ʱ�Ż�����ڴ� */
	string* m_pFormat;
};

