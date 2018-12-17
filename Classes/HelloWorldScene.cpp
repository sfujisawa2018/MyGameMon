/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include <time.h>

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
// �ŏ��Ɉ�x������邱��
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

	// ��ʃT�C�Y�̎擾
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	// �����ō�����֐����A�Ăяo�����悤�ɐݒ�
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(HelloWorld::onTouchCancelled, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	// �X�v���C�g�����
	spr = Sprite::create("mario.jpg");
	addChild(spr);
	// �ʒu��ݒ肷��
	spr->setPosition(Vec2(500,300));
	spr->setScale(0.2f);

    return true;
}

// �p���I�ɂ�邱��
void HelloWorld::update(float delta)
{
	
}

// ���상���o�֐�
void HelloWorld::MyFunction()
{
	//log("Hello,MyFuction!!");
	Sprite* spr = Sprite::create("koura.png");
	addChild(spr);

	float x = (float)rand() / RAND_MAX * 1280;
	float y = (float)rand() / RAND_MAX * 768;

	spr->setPosition(Vec2(x, y));

	// �t�F�[�h�ŏ�����
	FadeOut* action1 = FadeOut::create(2.0f);

	CallFunc* action = CallFunc::create(
		CC_CALLBACK_0(HelloWorld::MyFunction, this));
	// �폜�A�N�V����
	RemoveSelf* action2 = RemoveSelf::create();
	// �V�[�P���X�łȂ�
	Sequence* action3 = 
		Sequence::create(action1, action, action2, nullptr);

	spr->runAction(action3);
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* unused_event)
{
	// �^�b�`���W
	Vec2 touch_pos = touch->getLocation();

	Rect rect_spr = spr->getBoundingBox();

	bool hit = rect_spr.containsPoint(touch_pos);

	if (hit)
	{
		log("touch sprite!!");
		// �X�v���C�g�����
		Sprite* spr2 = Sprite::create("Kuppa.jpg");
		addChild(spr2);
	}

	return true;
}

void HelloWorld::onTouchMoved(Touch* touch, Event* unused_event)
{

}

void HelloWorld::onTouchEnded(Touch* touch, Event* unused_event)
{

}

void HelloWorld::onTouchCancelled(Touch* touch, Event* unused_event)
{

}