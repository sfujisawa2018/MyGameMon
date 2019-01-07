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

	for (int i = 0; i < 10; i++)
	{
		// �X�v���C�g�����
		spr[i] = Sprite::create("mario.jpg");
		addChild(spr[i]);
		// �ʒu��ݒ肷��
		float x = (float)rand() / RAND_MAX * 1280;
		float y = (float)rand() / RAND_MAX * 720;
		spr[i]->setPosition(Vec2(x, y));
		spr[i]->setScale(0.2f);

		x = (float)rand() / RAND_MAX * 1280;
		y = (float)rand() / RAND_MAX * 720;

		// �ړ��A�N�V����
		MoveTo* action1 = MoveTo::create(5.0f, Vec2(x, y));
		// �A�N�V�����ɔԍ��i�^�O�j���ӂ�
		action1->setTag(100);
		spr[i]->runAction(action1);
		// �_�ŃA�N�V����
		Blink* action2 = Blink::create(5.0f, 10);
		spr[i]->runAction(action2);
	}

	//// �R�b���MyFunction�����s����A�N�V����
	//CallFunc* action10 = CallFunc::create(
	//	CC_CALLBACK_0(HelloWorld::MyFunction, this)
	//);
	//DelayTime* action11 = DelayTime::create(3.0f);
	//Sequence* action12 = Sequence::create(
	//	action11, action10, nullptr);

	//this->runAction(action12);

    return true;
}

// �p���I�ɂ�邱��
void HelloWorld::update(float delta)
{
	
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* unused_event)
{
	// �^�b�`���W
	Vec2 touch_pos = touch->getLocation();

	for (int i = 0; i < 10; i++)
	{
		if (spr[i] != nullptr)
		{
			// �X�v���C�g�̋�`���擾
			Rect rect_spr = spr[i]->getBoundingBox();
			// �X�v���C�g�ƃ^�b�`�_�̓����蔻��
			bool hit = rect_spr.containsPoint(touch_pos);

			// �X�v���C�g���^�b�`�����H
			if (hit)
			{
				log("touch sprite!!");
				// �A�N�V������S�Ď~�߂�
				//spr[i]->stopAllActions();
				spr[i]->stopActionByTag(100);

				MoveBy* action = MoveBy::create(1.0f, Vec2(0, -500));
				spr[i]->runAction(action);
			}
		}
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

void HelloWorld::MyFunction()
{
	// �w��ԍ��̃A�N�V�������~�߂�
	//spr->stopActionByTag(100);
	// �X�v���C�g�̃A�N�V������S�Ď~�߂�
	//spr->stopAllActions();
}