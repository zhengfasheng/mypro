#include "UIRichText.h"
#include "DatabaseManager.h"
#include "cocostudio/CCArmature.h"
#include "Language.h"

UI_BEGIN



UIRichElement::UIRichElement(Type type )
	:m_type(type)
	, m_opcity(255)
	, m_color(Color3B::WHITE)
{
	static size_t uniqueID = 0;
	m_nID = ++uniqueID;
}

UIRichElement::~UIRichElement()
{

}

bool UIRichElement::init( GLubyte opcity , const Color3B& color )
{
	m_opcity = opcity;
	m_color = color;
	return true;
}

UIRichElementText::UIRichElementText()
	:UIRichElement(Type::Text)
	, m_nFontSize(14)
	, m_szContent("")
	, m_szFontName("")
{
	
}

UIRichElementText::~UIRichElementText()
{
	
}

bool UIRichElementText::init(
	const std::string& szContent , 
	const std::string& szFontName, 
	const Color3B& fontColor, 
	int nFontSize, 
	int nFontType, 
	const GLubyte opacity)
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!UIRichElement::init(opacity, fontColor));
		CC_BREAK_IF(szContent.empty());
		auto fontType = (FontType)nFontType;
		switch (fontType)
		{
		case UI::UIRichElement::FontType::Custom:
			{
				if ( szFontName.empty() || szFontName == DBC::Null )
				{
					m_szFontName = Language::getInstance()->getLocalFont();
				}
				else
				{
					m_szFontName = szFontName;
				}
			}
			break;
		case UI::UIRichElement::FontType::LocalFont:
			{
				m_szFontName = Language::getInstance()->getLocalFont();
			}
			break;
		case UI::UIRichElement::FontType::LocalBoldFont:
			{
				m_szFontName = Language::getInstance()->getLocalFont();
			}
			break;
		case UI::UIRichElement::FontType::LocalHelveticaBold:
			{
				m_szFontName = Language::getInstance()->getLocalFont();
			}
			break;
		case UI::UIRichElement::FontType::AlphaFont:
			{
				m_szFontName = Language::getInstance()->getLocalFont();
			}
			break;
		case UI::UIRichElement::FontType::AlphaBoldFont:
			{
				m_szFontName = Language::getInstance()->getLocalFont();
			}
			break;
		default:
			{
				m_szFontName = Language::getInstance()->getLocalFont();
			}
			break;
		}
		m_szContent = szContent;
		
		m_nFontSize = nFontSize;
		bRet = true;
	} while (0);
	return bRet;
}

UIRichElementText* UIRichElementText::create(
	const std::string& szContent, 
	const std::string& szFontName, 
	const Color3B& fontColor /* = Color3B::WHITE */, 
	int nFontSize /* = 14 */, 
	int nFontType /* = 1 */, 
	const GLubyte opacity /* = 255 */)
{
	auto pRet = new UIRichElementText;
	if ( pRet && pRet->init(szContent,szFontName,fontColor,nFontSize,nFontType,opacity))
	{
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}
	return pRet;
}

UIRichElementText* UIRichElementText::copy()
{
	auto pOut = UIRichElementText::create(m_szContent, m_szFontName, m_color, m_nFontSize, m_opcity);
	if ( pOut )
	{
		pOut->m_nID = this->m_nID;
	}
	return pOut;
}


UIRichElementImage::UIRichElementImage()
	:UIRichElement(Type::Image)
{

}

UIRichElementImage::~UIRichElementImage()
{

}

bool UIRichElementImage::init(
	const std::string& szPath, 
	const Widget::TextureResType resType, 
	float fScale, 
	const Color3B& color, 
	GLubyte opcity)
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!UIRichElement::init(opcity, color));
		CC_BREAK_IF(szPath.empty() || szPath == DBC::Null || (resType == Widget::TextureResType::LOCAL && resType == Widget::TextureResType::PLIST ));
		m_fScale = fScale;
		m_resType = resType;
		m_szPath = szPath;
		bRet = true;
	} while (0);
	return bRet;
}

UIRichElementImage* UIRichElementImage::create(
	const std::string& szPath, 
	const Widget::TextureResType resType, 
	float fScale /*= 1.0f*/, 
	const Color3B& color /*= Color3B::WHITE*/, 
	GLubyte opcity /*= 255*/)
{
	auto pRet = new UIRichElementImage;
	if ( pRet && pRet->init(szPath,resType,fScale,color,opcity) )
	{
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}
	return pRet;
}

UIRichElementNewLine::UIRichElementNewLine()
	:UIRichElement(Type::NewLine)
{

}

UIRichElementNewLine::~UIRichElementNewLine()
{

}

UIRichElementNewLine* UIRichElementNewLine::create()
{
	auto pRet = new UIRichElementNewLine;
	if ( pRet && pRet->init(255,Color3B::WHITE))
	{
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}
	return pRet;
}

UIRichElementAnimate::UIRichElementAnimate()
	:UIRichElement(UIRichElement::Type::Animate)
{

}

UIRichElementAnimate::~UIRichElementAnimate()
{

}

UIRichElementAnimate* UIRichElementAnimate::create(
	const std::string& szFormat, 
	const Widget::TextureResType resType, 
	float fScale, 
	int nStartIndex, 
	int nEndIndex, 
	float fSpeed, 
	const Color3B& color /* = Color3B::WHITE */, 
	GLubyte opcity /* = 255 */)
{
	auto pRet = new UIRichElementAnimate;
	if (pRet && pRet->init(szFormat, resType, fScale, nStartIndex, nEndIndex, fSpeed, color, opcity))
	{
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}
	return pRet;
}

bool UIRichElementAnimate::init(
	const std::string& szFormat, 
	const Widget::TextureResType resType, 
	float fScale, 
	int nStartIndex, 
	int nEndIndex, 
	float fSpeed, 
	const Color3B& color, 
	GLubyte opcity)
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!UIRichElement::init( opcity, color));
		CC_BREAK_IF(szFormat.empty() || szFormat == DBC::Null || 
			nEndIndex < 0 || nStartIndex < 0 || nEndIndex - nStartIndex < 1 || //不足两张一序列帧动画，建议直接显示图片
			fSpeed <= 0.0f ||
			( resType == Widget::TextureResType::LOCAL && resType == Widget::TextureResType::PLIST )
			);
		m_szFormat = szFormat;
		m_resourceType = resType;
		m_fScale = fScale;
		m_nStartIndex = nStartIndex;
		m_nEndIndex = nEndIndex;
		m_fSpeed = fSpeed;
		bRet = true;
	} while (0);
	return bRet;
}

UIRichElementArmature::UIRichElementArmature()
	:UIRichElement(UIRichElement::Type::Armature)
{

}

UIRichElementArmature::~UIRichElementArmature()
{

}

bool UIRichElementArmature::init( 
	const std::string& szArmatureName , 
	const std::string& szActionName, 
	int nDurationTo, 
	int nLoop, 
	float fScale,
	const Color3B& color, 
	GLubyte opcity )
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!UIRichElement::init(opcity,color));
		CC_BREAK_IF(szArmatureName.empty() || szActionName == DBC::Null || szActionName.empty() || szActionName == DBC::Null);
		m_szArmatureName = szArmatureName;
		m_szActionName = szActionName;
		m_nDurationTo = nDurationTo;
		m_nLoop = nLoop;
		m_fScale = fScale;
		bRet = true;
	} while (0);
	return bRet;
}

UIRichElementArmature* UIRichElementArmature::create(
	const std::string& szArmatureName , 
	const std::string& szActionName, 
	int nDurationTo, 
	int nLoop, 
	float fScale,
	const Color3B& color /* = Color3B::WHITE */, 
	GLubyte opcity /* = 255 */)
{
	auto pRet = new UIRichElementArmature;
	if ( pRet && pRet->init(szArmatureName,szActionName,nDurationTo,nLoop,fScale,color,opcity) )
	{
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}
	return pRet;
}


UIRichText::UIRichText()
	:m_szContent("")
	, m_bIsDoLayout(false)
	, m_nMaxRow(1)
	, m_bIsIgnoreMaxHeight(false)
	, m_fLineSpacing(0)
	, m_fLeftSpaceWidth(0.0f)
	, m_cutType(CutType::None)
{
	m_elements.clear();
}

UIRichText::~UIRichText()
{
	m_elements.clear();
}

UIRichText* UIRichText::create(const std::string& szContent /*= ""*/)
{
	auto pRet = new UIRichText;
	if ( pRet && pRet->init(szContent) )
	{
		pRet->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(pRet);
	}
	return pRet;
}

bool UIRichText::init(const std::string& szContent)
{
	bool bRet = false;
	do 
	{
		CC_BREAK_IF(!Widget::init());
		setString(szContent);
		bRet = true;
	} while (0);
	return bRet;
}

void UIRichText::setString(const std::string& szContent)
{
	if (szContent != m_szContent )
	{
		m_szContent = szContent;
		parseString();
		m_bIsDoLayout = true;
	}
}

void UIRichText::appendString(const std::string& szContent)
{
	if ( !szContent.empty() )
	{
		m_szContent += szContent;
		parseString();
		m_bIsDoLayout = true;
	}
}

void UIRichText::pushBackElement(UIRichElement* pElement)
{
	if ( pElement )
	{
		//这里检测一下，如果有\n 或\\n的标志，强制换行
		//如果是连续的两个换行，只保证首先存入的换行
		if ( pElement->m_type == UIRichElement::Type::Text )
		{
			std::vector<UIRichElement*> renders;
			checkTextElementHavaNewLine(pElement, renders);
			for (size_t i = 0; i < renders.size(); i++ )
			{
				if ( m_elements.size() > 0 && 
					m_elements.at(m_elements.size()-1)->m_type == UIRichElement::Type::NewLine &&
					renders[i]->m_type == UIRichElement::Type::NewLine )
				{

				}
				else
				{
					m_elements.pushBack(renders[i]);
				}
			}
		}
		else
		{
			m_elements.pushBack(pElement);
		}
		m_bIsDoLayout = true;
	}
}

void UIRichText::insertElement(UIRichElement* element, int index)
{
	m_elements.insert(index, element);
	m_bIsDoLayout = true;
}

void UIRichText::removeElement(int index)
{
	m_elements.erase(index);
	m_bIsDoLayout = true;
}

void UIRichText::removeElement(UIRichElement* element)
{
	m_elements.eraseObject(element);
	m_bIsDoLayout = true;
}

void UIRichText::adaptRenderers()
{
	formatString();
}

void UIRichText::formatString()
{
	if ( m_bIsDoLayout )
	{
		this->removeAllProtectedChildren();
		m_elementRenders.clear();
		addNewLine();
		for (ssize_t i = 0; i < m_elements.size(); i++)
		{
			auto pElement = m_elements.at(i);
			if ( !pElement )
				continue;
			switch (pElement->m_type)
			{
			case UIRichElement::Type::Text:
			{
				auto pTextElement = dynamic_cast<UIRichElementText*>(pElement);
				if ( pTextElement )
				{
					handleTextRenderer(pTextElement->m_szContent,pTextElement->m_szFontName,pTextElement->m_nFontSize,pTextElement->m_color,pTextElement->m_opcity, _ignoreSize);
				}
			}
				break;
			case UIRichElement::Type::Image:
				handleImageRenderer(pElement);
				break;
			case UIRichElement::Type::Animate:
				handleAnimateRenderer(pElement);
				break;
			case UIRichElement::Type::Armature:
				handleArmatureRenderer(pElement);
				break;
			case UIRichElement::Type::NewLine:
				{
					addNewLine();
				}
				break;
			default:
				break;
			}
		}
		formatRenders();
		m_bIsDoLayout = false;
	}
}

void UIRichText::handleTextRenderer(
	const std::string& szContent, 
	const std::string& szFontName, 
	int nFontSize, 
	const Color3B &color, 
	GLubyte opacity, 
	bool bIsIgnoreSize)
{
	Label* pTextRenderer = nullptr;
	auto bIsExistFontName = FileUtils::getInstance()->isFileExist(szFontName);
	auto createRender = [](bool bIsExistFontName, const std::string& szContent, const std::string& szFontName, const int& nFontSize)->Label* {
		if (bIsExistFontName)
		{
			return Label::createWithTTF(szContent, szFontName, nFontSize);
		}
		else
		{
			return Label::createWithSystemFont(szContent, szFontName, nFontSize);
		}
	};

	pTextRenderer = createRender(bIsExistFontName, szContent, szFontName, nFontSize);
	if (!pTextRenderer) return;
	
	if ( bIsIgnoreSize )//忽略控件大小，即显示成一行
	{
		pTextRenderer->setColor(color);
		pTextRenderer->setOpacity(opacity);
		pushToContainer(pTextRenderer);
	}
	else
	{
		//显示指定宽度，即多行显示
		float fRendererWidth = pTextRenderer->getContentSize().width;
		m_fLeftSpaceWidth -= fRendererWidth;
		if (m_fLeftSpaceWidth < 0.0f)//超出了显示范围
		{
			// 计算超出的百分比
			float fOverstepPercent = (-m_fLeftSpaceWidth) / fRendererWidth;
			std::string szCurText = szContent;
			size_t nContentLength = StringUtils::getCharacterCountInUTF8String(szContent);
			// 未超出部分字符串长度
			size_t leftLength = nContentLength * (1.0f - fOverstepPercent);

			// 显示宽度
			auto originalLeftSpaceWidth = m_fLeftSpaceWidth + fRendererWidth;
			// 未超出部分字符串
			auto leftStr = Helper::getSubStringOfUTF8String(szCurText, 0, leftLength);
			pTextRenderer->setString(leftStr);
			// 实际未超出部分字符串显示宽度
			auto leftWidth = pTextRenderer->getContentSize().width;
			if (originalLeftSpaceWidth < leftWidth) {
				//如果未超出部分字符串的显示宽度起出了显示宽度，尝试调整到合适的字符串，即减少显示的文字
				for (;;) {
					leftLength--;
					leftStr = Helper::getSubStringOfUTF8String(szCurText, 0, leftLength);
					pTextRenderer->setString(leftStr);
					leftWidth = pTextRenderer->getContentSize().width;
					if (leftWidth <= originalLeftSpaceWidth) {
						break;
					}
					else if (leftLength <= 0) {
						break;
					}
				}
			}
			else if (leftWidth < originalLeftSpaceWidth) {
				//如果未超出部分字符串的显示宽度还可继续显示，尝试调整到合适的字符串，即增加显示的文字
				for (;;) {
					leftLength++;
					leftStr = Helper::getSubStringOfUTF8String(szCurText, 0, leftLength);
					pTextRenderer->setString(leftStr);
					leftWidth = pTextRenderer->getContentSize().width;
					if (originalLeftSpaceWidth < leftWidth) {
						leftLength--;
						break;
					}
					else if (nContentLength <= leftLength) {
						break;
					}
				}
			}

			// 最坏情况下要取1位，不然将会进入无限的递归中
			if ( leftLength <= 0 ) leftLength = 1;
			std::string leftWords = Helper::getSubStringOfUTF8String(szCurText, 0, leftLength);
			std::string cutWords = Helper::getSubStringOfUTF8String(szCurText, leftLength, nContentLength - leftLength);
			if (leftLength > 0)
			{
				pTextRenderer = createRender(bIsExistFontName, Helper::getSubStringOfUTF8String(leftWords, 0, leftLength), szFontName, nFontSize);
				if (pTextRenderer)
				{
					pTextRenderer->setColor(color);
					pTextRenderer->setOpacity(opacity);
					pushToContainer(pTextRenderer);
				}
			}

			addNewLine();
			handleTextRenderer(cutWords.c_str(), szFontName, nFontSize, color, opacity,bIsIgnoreSize);
		}
		else
		{
			pTextRenderer->setColor(color);
			pTextRenderer->setOpacity(opacity);
			pushToContainer(pTextRenderer);
		}
	}
}

void UIRichText::handleImageRenderer(UIRichElement* pElement)
{
	auto pImageElement = dynamic_cast<UIRichElementImage*>(pElement);
	if ( pImageElement )
	{
		Sprite* pSprite = nullptr;
		if ( pImageElement->m_resType == Widget::TextureResType::LOCAL )
		{
			pSprite = Sprite::create(pImageElement->m_szPath);
		}
		else
		{
			auto pSpriteFrameName = SpriteFrameCache::getInstance()->getSpriteFrameByName(pImageElement->m_szPath);
			if ( pSpriteFrameName )
			{
				pSprite = Sprite::createWithSpriteFrame(pSpriteFrameName);
			}
		}
		if ( pSprite )
		{
			pSprite->setScale(pImageElement->m_fScale);
			handleCustomRenderer(pSprite);
		}
	}
}

void UIRichText::handleAnimateRenderer(UIRichElement* pElement)
{
	do 
	{
		auto pAnimateElement = dynamic_cast<UIRichElementAnimate*>(pElement);
		CC_BREAK_IF(!pAnimateElement);
		auto pSprite = Sprite::create();
		CC_BREAK_IF(!pSprite);
		auto pAnimation = Animation::create();
		CC_BREAK_IF(!pAnimation);
		for (int i = pAnimateElement->m_nStartIndex; i <= pAnimateElement->m_nEndIndex; i++)
		{
			char szName[256] = { 0 };
			sprintf(szName, pAnimateElement->m_szFormat.data(), i);
			if ( pAnimateElement->m_resourceType == Widget::TextureResType::LOCAL )
			{
				pAnimation->addSpriteFrameWithFile(szName);
			}
			else
			{
				auto pSpriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(szName);
				if (pSpriteFrame)
				{
					pAnimation->addSpriteFrame(pSpriteFrame);
				}
			}
		}
		//设置播放速度
		pAnimation->setDelayPerUnit(pAnimateElement->m_fSpeed / pAnimateElement->m_nEndIndex - pAnimateElement->m_nStartIndex + 1);
		CC_BREAK_IF(pAnimation->getFrames().size() <= 0);
		//pAnimation->setRestoreOriginalFrame(true);
		auto pAnimationSpriteFrame = pAnimation->getFrames().at(0);
		CC_BREAK_IF(!pAnimationSpriteFrame);
		CC_BREAK_IF(!pAnimationSpriteFrame->getSpriteFrame());
		pSprite->setContentSize(pAnimationSpriteFrame->getSpriteFrame()->getOriginalSize());
		auto pAction = Animate::create(pAnimation);
		CC_BREAK_IF(!pAction);
		pSprite->runAction(RepeatForever::create(pAction));
		pSprite->setScale(pAnimateElement->m_fScale);
		handleCustomRenderer(pSprite);
	} while (0);
}

void UIRichText::handleArmatureRenderer(UIRichElement* pElement)
{
	do 
	{
		auto pArmatureElement = dynamic_cast<UIRichElementArmature*>(pElement);
		CC_BREAK_IF(!pArmatureElement);
		auto pArmature = cocostudio::Armature::create(pArmatureElement->m_szArmatureName);
		CC_BREAK_IF(!pArmature);
		CC_BREAK_IF(!pArmature->getAnimation());
		pArmature->getAnimation()->play(pArmatureElement->m_szActionName,pArmatureElement->m_nDurationTo,pArmatureElement->m_nLoop);
		pArmature->setScale(pArmatureElement->m_fScale);
		handleCustomRenderer(pArmature);
	} while (0);
}

void UIRichText::handleCustomRenderer(Node* pRender)
{
	if ( !pRender )
	{
		return;
	}
	m_fLeftSpaceWidth -= pRender->getBoundingBox().size.width;
	if ( m_fLeftSpaceWidth < 0.0f )
	{
		addNewLine();
		pushToContainer(pRender);
		m_fLeftSpaceWidth -= pRender->getBoundingBox().size.width;
	}
	else
	{
		pushToContainer(pRender);
	}
}

void UIRichText::addNewLine()
{
	m_fLeftSpaceWidth = _customSize.width;
	m_elementRenders.push_back(Vector<Node*>());
}

void UIRichText::pushToContainer(Node* pRender)
{
	if ( m_elementRenders.size() <= 0 )
	{
		return;
	}
	m_elementRenders[m_elementRenders.size() - 1].pushBack(pRender);
}

void UIRichText::checkTextElementHavaNewLine(UIRichElement* pRender, std::vector<UIRichElement*>& outRenders)
{
	outRenders.clear();
	auto pTextRender = dynamic_cast<UIRichElementText*>(pRender);
	if ( pTextRender)
	{
		std::vector<std::string> vec;
		splitWithNewLine(pTextRender->m_szContent, vec);
		if ( vec.size() <= 1 )//如果只有一个，证明其中没有换行符
		{
			outRenders.push_back(pRender);
		}
		else
		{
			UIRichElementText* pCopyRender = nullptr;
			UIRichElementNewLine* pNewLine = nullptr;
			for (size_t i = 0; i < vec.size(); i++)
			{
				if ( vec[i] == "\n" )
				{
					pNewLine = createNewLineElement();
					if (pNewLine)
					{
						outRenders.push_back(pNewLine);
					}
				}
				else
				{
					//说明下，如果要换一个空行，请使用\n \n的方式去换一个空行，如果要指定空行的大小，如2代表以28号字换行
					// 则配置如：{1002\n \n}
					if ( !vec[i].empty() )
					{
						pCopyRender = pTextRender->copy();
						pCopyRender->m_szContent = vec[i];
						outRenders.push_back(pCopyRender);
					}
				}
			}
			//把之前拿来做切分的元素删除掉
			pTextRender = nullptr;
		}
	}
}

UIRichElementNewLine* UIRichText::createNewLineElement()
{
	return UIRichElementNewLine::create();
}

void UIRichText::splitWithNewLine(const std::string& szContent, std::vector<std::string>& outVec)
{
	outVec.clear();
	size_t nend = 0;
	std::string szCut = "";
	std::string szText = szContent;
	while (szText.size() > 0 && nend < szText.size())
	{
		if (szText[nend] == '\n')
		{
			szCut = szText.substr(0, nend);
			outVec.push_back(szCut);
			outVec.push_back("\n");//处理下对"\n"的支持
			szText = szText.substr(nend + 1);
			nend = 0;
		}
		else if (szText[nend] == '\\' && nend + 1 < szText.size() && szText[nend + 1] == 'n')
		{
			szCut = szText.substr(0, nend);
			outVec.push_back(szCut);
			outVec.push_back("\n");//处理下对"\n"的支持
			szText = szText.substr(nend + 2);
			nend = 0;
		}
		else
		{
			nend++;
		}
	}
	if (szText.size() > 0)
	{
		outVec.push_back(szText);
	}
}

void UIRichText::formatRenders()
{
	if ( _ignoreSize )
	{
		float fNewWidth = 0.0f;
		float fNewHeight = 0.0f;
		Vector<Node*> row = m_elementRenders[0];
		float fCurPosX = 0.0f;
		if ( m_elementRenders.size() == 1 )//说明中间没有强制的换行符
		{
			for (ssize_t i = 0; i < row.size(); i++)
			{
				Node* pRender = row.at(i);
				if (pRender)
				{
					pRender->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
					pRender->setPosition(fCurPosX, 0.0f);
					this->addProtectedChild(pRender, 1);
					fNewWidth += pRender->getBoundingBox().size.width;
					fNewHeight = std::max(fNewHeight, pRender->getBoundingBox().size.height);
					fCurPosX += pRender->getBoundingBox().size.width;
				}
			}
		}
		else
		{
			//中间有强制的换行符
			float fMaxWidth = 0.0f;
			std::vector<float> maxHeights(m_elementRenders.size(), 0.0f);
			std::vector<float> maxWidths(m_elementRenders.size(), 0.0f);
			for (size_t i = 0; i < m_elementRenders.size(); i++)
			{
				Vector<Node*> row = m_elementRenders[i];
				float fMaxHeight = 0.0f;
				float fRowWidth = 0.0f;
				for (ssize_t j = 0; j < row.size(); j++)
				{
					auto pRender = row.at(j);
					if (pRender)
					{
						fMaxHeight = std::max(pRender->getBoundingBox().size.height, fMaxHeight);
						fNewWidth = std::max(pRender->getBoundingBox().size.width, fNewWidth);
						fRowWidth += pRender->getBoundingBox().size.width;
					}
					maxHeights[i] = fMaxHeight;
				}
				maxWidths[i] = fRowWidth;
			}
			//计算出实际高度
			for (size_t i = 0; i < maxHeights.size(); i++ )
			{
				fNewHeight += maxHeights[i];
			}
			//加上最后面的行间距
			fNewHeight += ((maxHeights.size() + 1) * m_fLineSpacing);
			
			//计算出实际的宽度
			auto itMax = std::max_element(maxWidths.begin(), maxWidths.end());
			fNewWidth = *itMax;

			float fCurPosY = fNewHeight;
			for (size_t i = 0; i < m_elementRenders.size(); i++)
			{
				auto row = m_elementRenders[i];
				fCurPosX = 0.0f;
				fCurPosY -= (maxHeights[i] + m_fLineSpacing);
				for (ssize_t j = 0; j < row.size(); j++)
				{
					auto pRender = row.at(j);
					if (pRender)
					{
						pRender->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
						pRender->setPosition(fCurPosX, fCurPosY);
						this->addProtectedChild(pRender, 1);
						fCurPosX += pRender->getBoundingBox().size.width;
					}
				}
			}
		}
		
		this->setContentSize(Size(fNewWidth,fNewHeight));
	}
	else
	{
		//查看一下是否忽略高度的设置
		float fNewHeight = 0.0f;
		std::vector<Vector<Node*>> currentRenders;
		//检查是否有截断类型
		switch (m_cutType)
		{
		case UI::UIRichText::None:
			break;
		case UI::UIRichText::UP:
		{
			for (size_t i = 0; i < m_elementRenders.size(); i++)
			{
				auto row = m_elementRenders[i];
				if ( i >= m_nMaxRow )
				{
					currentRenders.push_back(row);
				}
				else
				{
					row.clear();
				}
			}
			currentRenders.shrink_to_fit();
			std::swap(currentRenders, m_elementRenders);
			//释放当前
			for (size_t i = 0; i < currentRenders.size(); i++)
			{
				auto row = currentRenders[i];
				row.clear();
			}
			currentRenders.clear();
		}
		break;
		case UI::UIRichText::Down:
		{
			for (size_t i = 0; i < m_elementRenders.size(); i++)
			{
				auto row = m_elementRenders[i];
				if (i < m_nMaxRow)
				{
					currentRenders.push_back(row);
				}
				else
				{
					row.clear();
				}
			}
			currentRenders.shrink_to_fit();
			std::swap(currentRenders, m_elementRenders);
			//释放当前
			for (size_t i = 0; i < currentRenders.size(); i++)
			{
				auto row = currentRenders[i];
				row.clear();
			}
			currentRenders.clear();
		}
		break;
		default:
			break;
		}
		std::vector<float> maxHeights(m_elementRenders.size(),0.0f);
		for (size_t i = 0; i < m_elementRenders.size(); i++ )
		{
			Vector<Node*> row = m_elementRenders[i];
			float fMaxHeight = 0.0f;
			for (ssize_t j = 0; j < row.size(); j++ )
			{
				auto pRender = row.at(j);
				if ( pRender )
				{
					fMaxHeight = std::max(pRender->getBoundingBox().size.height, fMaxHeight);
				}
				maxHeights[i] = fMaxHeight;
				fNewHeight += maxHeights[i];
			}
		}

		float fCurPosY = _customSize.height;
		//如果忽略了高度的设置，将重新计算出新的高度
		if ( m_bIsIgnoreMaxHeight )
		{
			//计算出实际高度
			fNewHeight = 0.0f;
			for (size_t i = 0; i < maxHeights.size(); i++)
			{
				fNewHeight += maxHeights[i];
			}
			//加上最后面的行间距
			fNewHeight += ((maxHeights.size() + 1) * m_fLineSpacing);
			fCurPosY = fNewHeight;
		}

		
		float fCurPosX = 0.0f;
		for (size_t i = 0; i < m_elementRenders.size(); i++ )
		{
			auto row = m_elementRenders[i];
			fCurPosX = 0.0f;
			fCurPosY -= (maxHeights[i] + m_fLineSpacing);
			for (ssize_t j = 0; j < row.size();j++)
			{
				auto pRender = row.at(j);
				if ( pRender )
				{
					pRender->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
					pRender->setPosition(fCurPosX, fCurPosY);
					this->addProtectedChild(pRender,1);
					fCurPosX += pRender->getBoundingBox().size.width;
				}
			}
		}
		if ( m_bIsIgnoreMaxHeight )
		{
			this->setContentSize(Size(getContentSize().width, fNewHeight));
		}
	}

	//清空渲染节点数据
	for (size_t i = 0; i < m_elementRenders.size(); i++)
	{
		auto row = m_elementRenders[i];
		row.clear();
	}
	m_elementRenders.clear();

	if ( _ignoreSize )
	{
		this->setContentSize(getVirtualRendererSize());
	}
	else
	{
		this->setContentSize(_customSize);
	}
	updateContentSizeWithTextureSize(_contentSize);
}


std::string UIRichText::getDescription() const
{
	return "UIRichText";
}

void UIRichText::ignoreContentAdaptWithSize(bool ignore)
{
	if (_ignoreSize != ignore)
	{
		m_bIsDoLayout = true;
		Widget::ignoreContentAdaptWithSize(ignore);
	}
}

void UIRichText::parseString()
{
	//{Type + ID这是一个{ Type + IDssssss{ Type + ID测 }试 }的字符串}\{1000\}
	std::vector<ParseData> datas;
	ParseData data;
	m_elements.clear();
	parseString(m_szContent, datas);
	UIRichElement* pElement = nullptr;
	
	for (size_t i = 0; i < datas.size(); i++ )
	{
		data = datas[i];
		switch ((UIRichElement::Type)data.nType)
		{
		case UIRichElement::Type::Animate:
		{
			auto pConfig = DatabaseManager::getInstance()->getTableData<DBC::tbAmimateConfig>(DBC::TableID::AnimateConfig, data.nID);
			if ( pConfig )
			{
				pElement = UIRichElementAnimate::create(
					pConfig->szFormat,
					(Widget::TextureResType)pConfig->nResourceType,
					pConfig->fScale,
					pConfig->nStartIndex,
					pConfig->nEndIndex,
					pConfig->fSpeed);
				pushBackElement(pElement);
			}
		}
			break;
		case UIRichElement::Type::Armature:
			{
				auto pConfig = DatabaseManager::getInstance()->getTableData<DBC::tbArmatureConfig>(DBC::TableID::ArmatureConfig,data.nID);
				if ( pConfig)
				{
					pElement = UIRichElementArmature::create(
						pConfig->szArmatureName,
						pConfig->szAnimatinName,
						pConfig->nDurationTo,
						pConfig->nLoop,
						pConfig->fScale);
					pushBackElement(pElement);
				}
			}
			break;
		case UIRichElement::Type::Image:
		{
			auto pConfig = DatabaseManager::getInstance()->getTableData<DBC::tbImageConfig>(DBC::TableID::ImageConfig, data.nID);
			if ( pConfig )
			{
				pElement = UIRichElementImage::create(pConfig->szSpriteFrameName, (Widget::TextureResType)pConfig->nResourceType, pConfig->fScale);
				pushBackElement(pElement);
			}
		}
			break;
		case UIRichElement::Type::NewLine:
		{
			pElement = createNewLineElement();
			pushBackElement(pElement);
		}
			break;
		case UIRichElement::Type::Text:
		{
			if ( data.szText.empty() )
				break;
			auto pConfig = DatabaseManager::getInstance()->getTableData<DBC::tbTextConfig>(DBC::TableID::TextConfig, data.nID);
			if ( pConfig )
			{
				auto fontColor = Color3B(pConfig->nColorR, pConfig->nColorG, pConfig->nColorB);
				pElement = UIRichElementText::create(data.szText, pConfig->szFontName, fontColor, pConfig->nFontSize,pConfig->nFontType);
				pushBackElement(pElement);
			}
		}
			break;
		default:
			break;
		}
	}
}

void UIRichText::parseString(const std::string& szContent, std::vector<ParseData>& outDatas)
{
	if (szContent.empty()) return;

	auto isType = [](const std::string& szContent, size_t nStartPos, size_t nCount, int& nID, int& nType)->bool
	{

		if (nStartPos + nCount < szContent.size())
		{
			std::string szText = szContent.substr(nStartPos, nCount);
			for (size_t i = 0; i < szText.size(); i++)
			{
				if (!isdigit(szText[i]))
				{
					return false;
				}
			}
			szText = szContent[nStartPos];
			nType = atoi(szText.data());
			szText = szContent.substr(nStartPos + 1, nCount - 1);
			nID = atoi(szText.data());
			return true;
		}
		else
		{
			return false;
		}
	};

	

	int nID = 0;
	int nType = 0;
	if ( !(szContent[0] == '{' && isType(szContent, 1, 4, nID, nType) ))
	{
		CCLOG("%s input string error , Configure the lack of identity , you must configure like {1001xxx}", getDescription().data());
		return;
	}
	std::vector< ParseData > dataStack;

	for (size_t i = 0; i < szContent.size(); i++)
	{
		//这里要处理下转义的问题，如就需要显示{1001},这时会把这个字符串当成格式串来处理，这里需要配置成\{1001\}
		if (szContent[i] == '{' && i > 0 && szContent[i - 1] == '\\')
		{
			//这个是一个转义字符
			if (outDatas.size() > 0)
			{
				ParseData& data = outDatas.back();
				//去掉之前的转义\  
				data.szText = data.szText.substr(0, data.szText.size() - 1);
				data.szText += szContent[i];
			}
		}
		else if (szContent[i] == '{' && isType(szContent, i + 1, 4, nID, nType))
		{
			ParseData data;
			data.nID = nID;
			data.nType = nType;
			outDatas.push_back(data);
			dataStack.push_back(data);
			i += 4;
		}
		else if (szContent[i] == '}' && i > 0 && szContent[i - 1] == '\\')
		{
			//转义
			if (outDatas.size() > 0)
			{
				ParseData& data = outDatas.back();
				//去掉之前的转义\  
				data.szText = data.szText.substr(0, data.szText.size() - 1);
				data.szText += szContent[i];
			}
		}
		else if (szContent[i] == '}')
		{
			if (dataStack.size() <= 0)
			{
				CCLOG("this string {%s} invaild ", szContent.data());
				continue;
			}
			dataStack.pop_back();
			if (dataStack.size() > 0)
			{
				ParseData data = dataStack.back();
				outDatas.push_back(data);
			}
		}
		else
		{
			ParseData& data = outDatas.back();
			data.szText += szContent[i];
		}
	}
}

void UIRichText::forceDoLayout()
{
	m_bIsDoLayout = true;
	adaptRenderers();
}

void UIRichText::doLayout()
{
	if ( !m_bIsDoLayout )
	{
		m_bIsDoLayout = true;
	}
}

void UIRichText::ignoreContentAdaptWithHeight(bool bIsIgnore)
{
	m_bIsIgnoreMaxHeight = bIsIgnore;
	m_bIsDoLayout = true;
}

void UIRichText::setCutType(CutType cutType)
{ 
	if (m_cutType == cutType) return;
	m_cutType = cutType;
	m_bIsDoLayout = true;
}

void UIRichText::setMaxRow(size_t nRow)
{
	if (m_nMaxRow == nRow) return;
	if ( nRow < 1 )
	{
		m_nMaxRow = 1;
	}
	else
	{
		m_nMaxRow = nRow;
	}
	m_bIsDoLayout = true;
}




UI_END