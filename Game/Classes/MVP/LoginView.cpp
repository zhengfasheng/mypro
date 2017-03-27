#include "LoginView.h"
#include "cocostudio\ActionTimeline\CSLoader.h"
#include "LoginPresenter.h"

LoginView::LoginView()
	:m_pLoginPresenter(nullptr)
{

}

LoginView::~LoginView()
{
	if (m_pLoginPresenter)
	{
		delete m_pLoginPresenter;
	}
	m_pLoginPresenter = nullptr;
}

void LoginView::onClearText()
{
	m_pName->setString("");
	m_pPassward->setString("");

	m_pShow->setString("clear success!!!");

}

void LoginView::onLoginResult(bool bIsSuccess, int code)
{
	if (bIsSuccess)
	{
		m_pShow->setString("Logon success!!!");
	}
	else
	{
		m_pShow->setString("Logon failed");
	}
}

bool LoginView::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!ui::Layout::init());

		auto rootNode = CSLoader::createNode("LoginView.csb");

		addChild(rootNode);

		auto pPanel = rootNode->getChildByName("Panel");
		CC_BREAK_IF(!pPanel);

		m_pPassward = (TextField*)pPanel->getChildByName("passward");
		m_pName = (TextField*)pPanel->getChildByName("name");
		m_pLogin = (Button*)pPanel->getChildByName("Login");
		m_pClear = (Button*)pPanel->getChildByName("Clear");
		m_pShow = (Text*)pPanel->getChildByName("show");

		m_pLogin->addClickEventListener(CC_CALLBACK_1(LoginView::onClick, this, 12));
		m_pClear->addClickEventListener(CC_CALLBACK_1(LoginView::onClick, this, 13));

		m_pLoginPresenter = new LoginPresenter(this);

		bRet = true;
	} while (0);
	return bRet;
}

void LoginView::onClick(Ref* pSender, int nCode)
{
	if (pSender == m_pLogin)
	{
		m_pLoginPresenter->doLogin(m_pName->getString(), m_pPassward->getString());
	}
	if (pSender == m_pClear)
	{
		m_pLoginPresenter->clear();
	}
}

void LoginView::show()
{

	Director::getInstance()->getRunningScene()->addChild(this, 100);
}

