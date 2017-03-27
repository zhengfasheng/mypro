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
 *  Date:2016/11/15 22:10
 *
 *  Summary:游戏模型管理器
 *  
 ******************************************************************************/
#pragma once
#include <unordered_map>

class IModel;
enum class ModelID
{
	GameUser,
};
class GameModelManager final
{
public:
	~GameModelManager();

	static GameModelManager* getInstance();

	IModel* getModel(ModelID eModelID);

	template<class T>
	T* getModel(ModelID eModelID)
	{
		return dynamic_cast<T*>(getModel(eModelID));
	}

private:
	GameModelManager();

	IModel* createModel(ModelID eModelID);

	std::unordered_map<ModelID, IModel*> m_models;

};