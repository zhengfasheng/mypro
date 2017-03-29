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
 *  Date:2016/7/24 21:57
 *
 *  Summary:Declares the file class
 *  
 ******************************************************************************/
#pragma once
#include "DataBaseDefine.h"

DBC_BEGIN
/** @brief	���ݱ����鲻Ҫ�������޸ı����� */
class CTable
{
public:
	CTable(TableConfig);
	virtual ~CTable();

	/**
	* @brief	�õ����ݿ�����.
	*
	* @return	����
	*/

	virtual const UINT getRow() const { return m_nRow; };

	/**
	* @brief	�õ����ݿ�����
	*
	* @return	����
	*/

	virtual const UINT getColumn() const { return m_nCol;};

	/**
	* @brief	Searches for the first with value.
	*
	* @param	nValue	The value.
	*
	* @return	null if it fails, else the found with value.
	*/

	virtual const Data* searchWithValue(INT nValue);
	template<class T> const T* searchWithValue(UINT nRow)
	{
		auto pOut = searchWithValue(nRow);
		if ( pOut )
		{
			return (const T*)pOut;
		}
		else
		{
			return nullptr;
		}
	}
	/**
	* @brief	���в��ң����Ч�ʷǳ���
	*
	* @param	nRow	The row.
	*
	* @return	null if it fails, else the found with row.
	*/

	virtual const Data* searchWithRow(UINT nRow);

	/**
	 * @brief	�õ���ͷ
	 *
	 * @return	��ʼ
	 */

	TableMap::const_iterator cbegin();

	/**
	 * @brief	�õ���β
	 *
	 * @return	�����
	 */

	TableMap::const_iterator cend();

	/** @brief	Opens this table. */
	virtual BOOL open();

private:

	/** @brief	Closes this table. */
	virtual void close();

	/**
	 * @brief	��ȡ�ļ���ʽ����
	 *
	 * @param [in,out]	szContent	�ļ�����
	 * @param	filePath		 	�ļ�·�� 
	 *
	 * @return	true if it succeeds, false if it fails.
	 */

	BOOL readText(STRING& szContent );
	//��ȡ�ڴ���һ������(���ջ��з�)
	void splitStringToVector(STRING& szContent, vector<STRING>& outVec);

	//�������� 
	void createIndex( );

private:
	//������
	std::vector<Data>		m_vDataBuf;

	//����
	UINT m_nRow;

	//����
	UINT m_nCol;

	//�ļ���ʽ
	vector< DataType > m_tpye;

	//������
	TableMap m_table;

	//������Ϣ
	TableConfig m_config;

};
DBC_END