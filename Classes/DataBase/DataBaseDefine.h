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
 *  Date:2016/7/29 23:18
 *
 *  Summary:���ݿ��ļ���ʽ����
 *  
 ******************************************************************************/
#pragma once
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

#define DBC_BEGIN                     namespace DBC {
#define DBC_END                       }
#define USING_DBC                     using namespace DBC

DBC_BEGIN
using namespace std;

//���ݿ��������Ͷ���
#ifdef _IOS
#if defined(_ARM_ARCH_7)
typedef int	INT;
typedef float FLOAT;
#else
typedef long long	INT;
typedef double FLOAT;
#endif

#else
typedef int	INT;
typedef float FLOAT;
#endif

typedef char CHAR, *PCHAR;
typedef long long INT64, *PINT64;
typedef bool BOOL;
typedef unsigned int UINT;
typedef string STRING;

/** @brief	�������� */
enum class DataType
{
	INT,   //����
	FLOAT, //����
	STRING,//�ַ���
	PINT64,//������,��ָ����ʽ�洢
};

/** @brief	���� */
union Data
{
	PCHAR   pStringValue;
	INT     nValue;
	FLOAT   fValue;
	PINT64  pValue64;

	Data(){ memset(this, 0, sizeof(Data)); }
	~Data(){}
	Data(INT value){ nValue = value; }
	Data(FLOAT value){ fValue = value; }
	Data(PINT64 value){ pValue64 = value; }
	Data(PCHAR value){ pStringValue = value; }
};

/** @brief	���ݱ����� */
struct TableConfig
{
	TableConfig(UINT id, PCHAR name = nullptr , PCHAR path = nullptr ) : uID(id), szName(name), szPath(path){}
	/** @brief	��id. */
	UINT  uID;
	/** @brief	���� */
	PCHAR szName;
	/** @brief	��·�� */
	PCHAR szPath;
};

//���ݱ�
typedef std::unordered_map<INT, const Data*> TableMap;

//���ݿ������
const static std::string Null = "NULL";

DBC_END