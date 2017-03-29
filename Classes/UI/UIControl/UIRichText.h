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
 *  Date:2016/8/25 23:14
 *
 *  Summary:
 *  富文本
 *  文字格式如下class Type
 *  {Type+ID这是一个{Type+IDssssss{Type+ID测}试}的字符串}
 *  如果只是要显示成{1001}请在前加转义字符\{1001\}
 *  
 ******************************************************************************/
#pragma once
#include "GameCommon.h"
#include "ui/CocosGUI.h"
#include "UIDefine.h"

USING_NS_CC;

UI_BEGIN

using namespace cocos2d::ui;

/** @brief	Rich text element base class. */
class UIRichElement : public Ref
{
public:
	enum class Type
	{
		Text = 1,      //文字
		Image,     //图片
		Animate, //序列帧动画
		Armature,//骨骼动画，请先预加载资源
		NewLine,   //强制换行
	};

	//std::string getLocalFont();
	//std::string getLocalBoldFont();
	//std::string getLocalHelveticaBold();
	//std::string getAlphaFont();
	//std::string getAlphaBoldFont();
	// 请自行根据自己项目来定
	enum class FontType
	{
		Min,
		Custom = Min,//自定义
		LocalFont,
		LocalBoldFont,
		LocalHelveticaBold,
		AlphaFont,
		AlphaBoldFont,
		Max,
	};

	UIRichElement(Type type );
	virtual ~UIRichElement();

	/**
	 * @brief	Initialize a RichElement
	 *
	 * @param	type  	The type.
	 * @param	opcity	The opcity.
	 *
	 * @return	true if it succeeds, false if it fails.
	 */

	virtual bool init( GLubyte opcity , const Color3B& color );
	
protected:
	Type m_type;
	GLubyte m_opcity;
	Color3B m_color;
	size_t m_nID;//会自动增加，唯一的id
	friend class UIRichText;
};

/** @brief	Rich element for displaying text */
class UIRichElementText : public UIRichElement
{
public:
	UIRichElementText();
	virtual ~UIRichElementText();

	/**
	 * @brief	Initialize a RichElementText
	 *
	 * @param	szContent	The content.
	 * @param	fontName 	Name of the font.
	 * @param	fontColor	the font color.
	 * @param	fontSize 	size of the font.
	 * @param	opacity  	the opacity.
	 *
	 * @return	true if it succeeds, false if it fails.
	 */

	virtual bool init(
		const std::string& szContent , 
		const std::string& szFontName, 
		const Color3B& fontColor,
		int nFontSize,
		int nFontType,
		const GLubyte opacity);

	/**
	 * @brief	Creates a new UIRichElementText.
	 *
	 * @param	szContent	The content.
	 * @param	fontName 	Name of the font.
	 * @param	fontColor	(Optional) the font color.
	 * @param	fontSize 	(Optional) size of the font.
	 * @param	opacity  	(Optional) the opacity.
	 *
	 * @return	null if it fails, else a pointer to an UIRichElementText.
	 */

	static UIRichElementText* create(
		const std::string& szContent,
		const std::string& szFontName,
		const Color3B& fontColor = Color3B::WHITE,
		int nFontSize = 14,
		int nFontType = 1,
		const GLubyte opacity = 255);

	UIRichElementText* copy();
protected:
	
	std::string m_szContent;
	std::string m_szFontName;
	int m_nFontSize;
	friend class UIRichText;
};

/** @brief	Rich element for displaying image */
class UIRichElementImage : public UIRichElement
{
public:
	UIRichElementImage();
	virtual ~UIRichElementImage();

	/**
	 * @brief	Initialize a UIRichElementImage
	 *
	 * @param	szPath 	Full pathname of the file.
	 * @param	resType	Type of the resource.
	 * @param	fScale 	The scale.
	 * @param	color  	The color.
	 * @param	opcity 	The opcity.
	 *
	 * @return	true if it succeeds, false if it fails.
	 */

	virtual bool init( 
		const std::string& szPath , 
		const Widget::TextureResType resType,
		float fScale , 
		const Color3B& color , 
		GLubyte opcity );

	/**
	 * @brief	Creates a new UIRichElementImage
	 *
	 * @param	szPath 	Full pathname of the file.
	 * @param	resType	Type of the resource.
	 * @param	fScale 	(Optional) the scale.
	 * @param	color  	(Optional) the color.
	 * @param	opcity 	(Optional) the opcity.
	 *
	 * @return	null if it fails, else a pointer to an UIRichElementImage.
	 */

	static UIRichElementImage* create(
		const std::string& szPath,
		const Widget::TextureResType resType,
		float fScale = 1.0f,
		const Color3B& color = Color3B::WHITE,
		GLubyte opcity = 255);

protected:
	std::string m_szPath;
	float m_fScale;
	Widget::TextureResType m_resType;
	friend class UIRichText;
};

/** @brief	换行 */
class UIRichElementNewLine : public UIRichElement
{
public:
	UIRichElementNewLine();
	virtual ~UIRichElementNewLine();

	static UIRichElementNewLine* create();
protected:
	friend class UIRichText;
};

class UIRichElementAnimate : public UIRichElement
{
public:
	UIRichElementAnimate();
	virtual ~UIRichElementAnimate();

	/**
	 * @brief	Initialize a UIRichElementAnimate
	 *
	 * @param	szFormat	   	序列帧格式串
	 * @param	resType		   	Type of the resource.
	 * @param	fScale		   	The scale.
	 * @param	nStartIndex	   	The start index.
	 * @param	nEndIndex	   	The end index.
	 * @param	fEachFrameSpeed	每帧的播放时长
	 * @param	color		   	The color.
	 * @param	opcity		   	The opcity.
	 *
	 * @return	true if it succeeds, false if it fails.
	 */

	virtual bool init(
		const std::string& szFormat,
		const Widget::TextureResType resType,
		float fScale,
		int nStartIndex,
		int nEndIndex,
		float fSpeed,
		const Color3B& color,
		GLubyte opcity );

	/**
	 * @brief	Creates a new UIRichElementAnimate
	 *
	 * @param	szFormat   	Describes the format to use.
	 * @param	resType	   	Type of the resource.
	 * @param	fScale	   	The scale.
	 * @param	nStartIndex	The start index.
	 * @param	nEndIndex  	The end index.
	 * @param	fSpeed	   	The speed.
	 * @param	color	   	(Optional) the color.
	 * @param	opcity	   	(Optional) the opcity.
	 *
	 * @return	null if it fails, else a pointer to an UIRichElementAnimate.
	 */

	static UIRichElementAnimate* create(
		const std::string& szFormat,
		const Widget::TextureResType resType,
		float fScale,
		int nStartIndex,
		int nEndIndex,
		float fSpeed,
		const Color3B& color = Color3B::WHITE,
		GLubyte opcity = 255);
protected:

	/** @brief	动画格式字符串 */
	std::string m_szFormat;
	/** @brief	Type of the resource. */
	Widget::TextureResType m_resourceType;
	/** @brief	The scale. */
	float m_fScale;
	/** @brief	The start index. */
	int m_nStartIndex;
	/** @brief	The end index. */
	int m_nEndIndex;
	/** @brief	播放一次需要的总时长 */
	float m_fSpeed;

	friend class UIRichText;
};

class UIRichElementArmature : public UIRichElement
{
public:
	UIRichElementArmature();
	virtual ~UIRichElementArmature();

	/**
	 * @brief	Initialize a UIRichElementArmature
	 *  
	 *  play param see the ArmatureAnimation::play.
	 *
	 * @param	szArmatureName	Name of the armature.
	 * @param	szActionName  	The animation name you want to play.
	 * @param	nDurationTo   	The frames between two animation changing-over. It's meaning is
	 * 							changing to this animation need how many frames
	 * 							
	 * 							-1 : use the value from MovementData get from flash design panel.
	 * @param	nLoop		  	Whether the animation is loop
	 * 							
	 * 							loop &lt; 0 : use the value from MovementData get from flash design
	 * 							panel loop = 0 : this animation is not loop loop &gt; 0 : this
	 * 							animation is loop.
	 * @param	fScale		  	The scale.
	 * @param	color		  	The color.
	 * @param	opcity		  	The opcity.
	 *
	 * @return	true if it succeeds, false if it fails.
	 */

	virtual bool init( 
		const std::string& szArmatureName ,
		const std::string& szActionName,
		int nDurationTo,
		int nLoop,
		float fScale,
		const Color3B& color,
		GLubyte opcity );

	static UIRichElementArmature* create( 
		const std::string& szArmatureName ,
		const std::string& szActionName,
		int nDurationTo,
		int nLoop,
		float fScale,
		const Color3B& color = Color3B::WHITE,
		GLubyte opcity = 255);

private:
	/** @brief	骨骼名. */
	std::string m_szArmatureName;
	/** @brief	需要play的动画名称 */
	std::string m_szActionName;
	int m_nDurationTo;
	int m_nLoop;
	/** @brief	The scale. */
	float m_fScale;
	friend class UIRichText;
};


class UIRichText : public Widget
{
public:
	enum CutType
	{
		None,//不做处理
		UP, //超出的截断最上面,即只显示内容的后面部分
		Down,//超出的截断下面，即只显示内容的前面部分
	};

	UIRichText();
	virtual ~UIRichText();

	static UIRichText* create(const std::string& szContent = "");

	virtual bool init(const std::string& szContent );

	virtual std::string getDescription() const override;
	virtual void ignoreContentAdaptWithSize(bool ignore) override;
	/**
	 * @brief	Sets a string.
	 *
	 * @param	szContent	The content.
	 */

	virtual void setString(const std::string& szContent);
	/**
	* @brief	Appends a string.
	*
	* @param	szContent	The content.
	*/

	virtual void appendString(const std::string& szContent);

	/** @brief	强制重新布局，请确保所有数据完全给出,在本帧中刷新 */
	virtual void forceDoLayout();

	/** @brief	重新布局,将会在下一帧刷新 */
	virtual void doLayout();

	/**
	 * @brief	设置是否忽略最大高度限制，默认为true
	 * 			true 当设置的内容超过了设置的大小将会重新调整高度
	 * 			false 不会进行高度的调整,但超出的部分将会是在显示区域的下方
	 * 			ignoreContentAdaptWithSize false 时有效
	 *
	 * @param	bIsIgnore	true if this object is ignore.
	 */

	virtual void ignoreContentAdaptWithHeight(bool bIsIgnore);
	virtual bool isIignoreContentAdaptWithHeight(){ return m_bIsIgnoreMaxHeight; }

	/**
	 * @brief	最设置最大的显示行数 ignoreContentAdaptWithSize false 时有效.
	 *
	 * @param	nRow	The height.
	 */

	virtual void setMaxRow(size_t nRow );
	virtual float getMaxRowt(){ return m_nMaxRow; }

	/**
	 * @brief	设置内容超出显示区域的截断类型，默认None
	 * 			ignoreContentAdaptWithSize false 时有效
	 *
	 * @param	cutType	Type of the cut.
	 */

	virtual void setCutType(CutType cutType);
	virtual CutType getCutType(){ return m_cutType; }

	/**
	 * @brief	设置行间距
	 *
	 * @param	fLineSpacing	The line spacing.
	 */

	virtual void setLineSpacing(float fLineSpacing){ m_fLineSpacing = fLineSpacing; }
	virtual float getLineSpacing(){ return m_fLineSpacing; }

protected:

	/** @brief	重绘 */
	virtual void adaptRenderers() override;

private:

	void pushToContainer(Node* pRender);

	class ParseData
	{
	public:
		ParseData() :nType(0), nID(0), szText("")
		{
		}
		int nType;
		int nID;
		std::string szText;
	};

	/** @brief	解析字符串 */
	void parseString();

	void parseString(const std::string& szContent, std::vector<ParseData>& outDatas);

	/** @brief	Format string. */
	void formatString();

	/** @brief	Format renders. */
	void formatRenders();

	void handleTextRenderer(
		const std::string& szContent, 
		const std::string& szFontName, 
		int nFontSize, 
		const Color3B &color, 
		GLubyte opacity, 
		bool bIsIgnoreSize);
	void handleImageRenderer(UIRichElement* pElement);
	void handleAnimateRenderer(UIRichElement* pElement);
	void handleArmatureRenderer(UIRichElement* pElement);
	void handleCustomRenderer(Node* pRender);

	void addNewLine();

	/**
	 * @brief	检查文字中是否有强制换行的标志.
	 *
	 * @param [in,out]	pRender   	If non-null, the render.
	 * @param [in,out]	outRenders	[in,out] If non-null, the out vector.
	 */

	void checkTextElementHavaNewLine(UIRichElement* pRender , std::vector<UIRichElement*>& outRenders);

	/**
	 * @brief	创建一个换行元素
	 *
	 * @return	null if it fails, else the new new line element.
	 */

	UIRichElementNewLine* createNewLineElement();

	/**
	 * @brief	切分字符串以\n 或 \\n
	 *
	 * @param	szContent	  	The content.
	 * @param [in,out]	outVec	The out vector.
	 */

	void splitWithNewLine(const std::string& szContent, std::vector<std::string>& outVec);

	//以下这几个方法暂时不提供，针对文字会在里部进行切分处理
	/**
	* @brief Insert a RichElement at a given index.
	*
	* @param element A RichElement type.
	* @param index A given index.
	*/
	void insertElement(UIRichElement* element, int index);

	/**
	* @brief Add a RichElement at the end of RichText.
	*
	* @param element A RichElement instance.
	*/
	void pushBackElement(UIRichElement* pElement);

	/**
	* @brief Remove a RichElement at a given index.
	*
	* @param index A integer index value.
	*/
	void removeElement(int index);

	/**
	* @brief Remove specific RichElement.
	*
	* @param element A RichElement type.
	*/
	void removeElement(UIRichElement* element);

private:

	/** @brief	The content. */
	std::string m_szContent;
	/** @brief	是否需要重新布局 */
	bool m_bIsDoLayout;
	/** @brief	The elements. */
	Vector<UIRichElement*> m_elements;
	/** @brief	The element renders. */
	std::vector<Vector<Node*>> m_elementRenders;
	/** @brief	是否忽略最大高度的限制 */
	bool m_bIsIgnoreMaxHeight;
	/** @brief	行间距 */
	float m_fLineSpacing;
	/** @brief	剩余宽度 */
	float m_fLeftSpaceWidth;
	/** @brief	内容超出显示区域时截断类型 */
	CutType m_cutType;
	/** @brief	最大显示行数 */
	size_t m_nMaxRow;
};

UI_END