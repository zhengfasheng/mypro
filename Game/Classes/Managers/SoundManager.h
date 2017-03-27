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
 *  Summary:声音管理器
 *  
 ******************************************************************************/
#pragma once

#include "SimpleAudioEngine.h"
#include "IManager.h"

using namespace CocosDenshion;

class SoundManager final : public IManager
{
public:
	~SoundManager();

	DEFINE_MANAGER(SoundManager);

	/** 音效的id. */
	enum class EffectID
	{

	};

	virtual void init() override;

	virtual void release() override;

	/** 预加载声音文件. */
	void preloadSounds();

	/** 暂停音效. */
	void pauseEffects();

	/** 恢复音效. */
	void resumeEffects();

	/** 暂停背景音乐. */
	void pauseBackgroundMusic();

	/** Resume background music. */
	void resumeBackgroundMusic();

	/**
	 * 是否开启音效.
	 *
	 * @return	true if audio on, false if not.
	 */

	bool isEffectsOn();

	/**
	 * 设置音效的开关状态.
	 *
	 * @param	bIsOn	(Optional) true if this object is on.
	 */

	void setEffects(bool bIsOn = true);

	/**
	 * 是否开启背景音乐.
	 *
	 * @return	true if back music on, false if not.
	 */

	bool isBackMusicOn();

	/**
	 * 设置背景音乐开关状态.
	 *
	 * @param	bIsOn	(Optional) true if this object is on.
	 */

	void setBackMusic(bool bIsOn = true);

	/**
	 * 播放音乐(包括音乐与音效)
	 *
	 * @param	id	音效id.
	 */

	void playEffect(EffectID id);

	/**
	 * Sets background music volume.
	 *
	 * @param	fValue	must be within the range of 0.0 as the minimum and 1.0 as the maximum.
	 */

	void setBackgroundMusicVolume(float fValue);

	/**
	 * Gets background music volume.
	 *
	 * @return	The background music volume.
	 */

	float getBackgroundMusicVolume();

	/**
	 * Sets effects volume.
	 *
	 * @param	fValue	must be within the range of 0.0 as the minimum and 1.0 as the maximum.
	 */

	void setEffectsVolume(float fValue);

	/**
	 * Gets effects volume.
	 *
	 * @return	The effects volume.
	 */

	float getEffectsVolume();

private:
	SoundManager();

	/**
	 * 得到音效路径.
	 *
	 * @param	id	音效id.
	 *
	 * @return	返回音效路径.
	 */

	string getEffect(EffectID id);

	/**
	 * 播放背景音乐.
	 *
	 * @param	szMusic	The music.
	 */

	void playBackMusic(const string& szMusic);

	/**
	 * Play audio.
	 *
	 * @param	szAudio	The audio.
	 */

	void playEffect(const string& szAudio);

	/** 保存游戏音效与背景音乐的设置. */
	void saveStatus();

	/** 读取游戏音效与背景音乐的设置. */
	void readStatus();

private:

	/** true if this object is effect on. */
	bool m_bIsEffectOn;
	/** true if this object is back music on. */
	bool m_bIsBackMusicOn;
	/** The effect volume. */
	float m_fEffectVolume;
	/** The background volume. */
	float m_fBackgroundVolume;
};


