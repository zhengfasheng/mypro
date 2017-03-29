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
 *  Summary:����������
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

	/** ��Ч��id. */
	enum class EffectID
	{

	};

	virtual void init() override;

	virtual void release() override;

	/** Ԥ���������ļ�. */
	void preloadSounds();

	/** ��ͣ��Ч. */
	void pauseEffects();

	/** �ָ���Ч. */
	void resumeEffects();

	/** ��ͣ��������. */
	void pauseBackgroundMusic();

	/** Resume background music. */
	void resumeBackgroundMusic();

	/**
	 * �Ƿ�����Ч.
	 *
	 * @return	true if audio on, false if not.
	 */

	bool isEffectsOn();

	/**
	 * ������Ч�Ŀ���״̬.
	 *
	 * @param	bIsOn	(Optional) true if this object is on.
	 */

	void setEffects(bool bIsOn = true);

	/**
	 * �Ƿ�����������.
	 *
	 * @return	true if back music on, false if not.
	 */

	bool isBackMusicOn();

	/**
	 * ���ñ������ֿ���״̬.
	 *
	 * @param	bIsOn	(Optional) true if this object is on.
	 */

	void setBackMusic(bool bIsOn = true);

	/**
	 * ��������(������������Ч)
	 *
	 * @param	id	��Чid.
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
	 * �õ���Ч·��.
	 *
	 * @param	id	��Чid.
	 *
	 * @return	������Ч·��.
	 */

	string getEffect(EffectID id);

	/**
	 * ���ű�������.
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

	/** ������Ϸ��Ч�뱳�����ֵ�����. */
	void saveStatus();

	/** ��ȡ��Ϸ��Ч�뱳�����ֵ�����. */
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


