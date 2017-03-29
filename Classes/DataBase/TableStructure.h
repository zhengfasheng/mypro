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
 *  Date:2016/7/30 14:34
 *
 *  Summary:���ݱ�ṹ����
 *  
 ******************************************************************************/
#pragma once
#include "DataBaseDefine.h"

DBC_BEGIN
//���ݱ�ṹ�Ķ��壬��ο�DBC::Data�����ͣ�
//ֻ�ܶ�����Щ����


struct tbBase
{
	INT	    id;
};

//���ı��������� 
struct tbTextConfig : public tbBase
{
	INT nColorR;
	INT nColorG;
	INT nColorB;
	PCHAR szFontName;
	INT nFontSize;
	INT nFontType;
};

//���ı�ͼƬ����
struct tbImageConfig : public tbBase
{
	INT nResourceType;
	FLOAT fScale;
	PCHAR szSpriteFrameName;
};

//���ı�����֡����
struct tbAmimateConfig : public tbBase
{
	INT nResourceType;
	FLOAT fScale;
	PCHAR szFormat;
	INT nStartIndex;
	INT nEndIndex;
	FLOAT fSpeed;
};

//���ı�������������
struct tbArmatureConfig : public tbBase
{
	INT nResourceType;
	FLOAT fScale;
	PCHAR szArmatureName;
	PCHAR szAnimatinName;
	INT   nDurationTo;
	INT   nLoop;
};

DBC_END
