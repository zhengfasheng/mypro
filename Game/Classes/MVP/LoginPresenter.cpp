#include "LoginPresenter.h"
#include "LoginView.h"
#include "UserInfo.h"

LoginPresenter::LoginPresenter(ILoginView* pLoginView)
	:m_pLoginView(pLoginView)
{
	m_pUserInfo = new UserInfo;
}

LoginPresenter::~LoginPresenter()
{
	m_pLoginView = nullptr;
	if ( m_pUserInfo )
	{
		delete m_pUserInfo;
	}
	m_pUserInfo = nullptr;
}

void LoginPresenter::clear()
{
	m_pLoginView->onClearText();
}

void LoginPresenter::doLogin(const std::string& szName, const std::string& szPassward)
{
	bool bIsSuccess = (szName == "zheng fa sheng" && szPassward == "123456");
	int code = bIsSuccess;
	m_pLoginView->onLoginResult(bIsSuccess, code);
}

