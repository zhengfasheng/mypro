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
 *  Date:2016/7/24 21:55
 *
 *  Summary:Declares the game tool class
 *  
 ******************************************************************************/
#pragma once

#include "GameTypes.h"
#include "GValue.h"

/**
 * @brief	Convert this object into a string representation.
 *
 * @tparam	T	Generic type parameter.
 * @param	data	The data.
 *
 * @return	data as a string.
 */

template<class T> string toString(const T& data)
{
	stringstream os;
	os << data;
	return os.str();
}

/**
 * @brief	Splits.
 *
 * @param	src				待切分字符串.
 * @param	token			做切割的token
 * @param [in,out]	vect	切分完成后的字符串
 */

extern inline void split(string src, const char* token, vector<string>& vect);


/**
 * @brief	GBK to utf8 .
 *
 * @param	strGBK	GBK string.
 *
 * @return	A utf8 string.
 */

string GBKToUtf8(string strGBK);

