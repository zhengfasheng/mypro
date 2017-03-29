#include "IView.h"

class GameUserView : public IView
{
public:
	GameUserView();
	~GameUserView();

	static GameUserView* create();

	virtual bool init() override;

	virtual void updateUI(IModel* pModel) override;

	virtual void updateUI() override;

	virtual void show() override;

private:

	void save();

private:

	Text* m_pNameLabel;

	Button* m_pSaveBtn;
};