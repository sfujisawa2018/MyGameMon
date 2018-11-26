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

	// �X�v���C�g�̐���
	Sprite* spr = Sprite::create("mario.jpg");
	addChild(spr);
	//spr->setPosition(Vec2(300, 300));
	spr->setScale(0.5f);
	//MoveTo* action1 = MoveTo::create(2.0f, Vec2(600.0f, 300.0f));
	//ScaleTo* action1 = ScaleTo::create(2.0f, 2.0f);
	//
	//JumpTo* action2 = JumpTo::create(1.0f, Vec2(200.0f, 200.0f), 300.0f, 2);

	//TintTo* action3 = TintTo::create(2.0f, Color3B(0, 0, 255));
	//ScaleTo* action2_1 = ScaleTo::create(1.0f, 0.5f);
	// �����Ŏw�肵�����Ɏ��s����A�N�V����
	//Sequence* action3 = Sequence::create(action1, action2, action1, action2, nullptr);
	// �w�肵�������������Ɏ��s����A�N�V����
	//Spawn* action4 = Spawn::create(action1, action2, action3, nullptr);
	//ScaleTo* action4 = ScaleTo::create(2.0f, 2.0f);
	//Sequence* action5 = Sequence::create(action3, action4, nullptr);
	// �A�N�V�������N��
	//spr->runAction(action1);
	//spr->runAction(action2);
	//spr->runAction(action3);
	//// �E��ړ��A�N�V����
	//MoveBy* action1 = MoveBy::create(2.0f, Vec2(100, 100));
	//// �E���ړ��A�N�V����
	//MoveBy* action2 = MoveBy::create(2.0f, Vec2(100, -100));
	//// ��\���A�N�V����
	////Hide* action3 = Hide::create();
	//// �폜�A�N�V����
	//RemoveSelf* action3 = RemoveSelf::create();
	//DelayTime* action4 = DelayTime::create(1.0f);
	//// �\���A�N�V����
	//Show* action5 = Show::create();
	//// �V�[�P���X
	//Sequence* action6 = Sequence::create(action1, action2, action3, action4, action5, nullptr);
	////// �����ɌJ��Ԃ�
	//RepeatForever* action7 = RepeatForever::create(action6);
	//spr->runAction(action7);

	// �E��ɏo��������
	spr->setPosition(Vec2(1280-100, 720-100));
	MoveTo* actionMoveLeft = MoveTo::create(5.0f, Vec2(100, 720 - 100));
	MoveTo* actionMoveRight = MoveTo::create(5.0f, Vec2(1280 - 100, 720 - 100));
	Sequence* actionMoveLeftRight = Sequence::create(actionMoveLeft, actionMoveRight, nullptr);

	//spr->runAction(actionMoveLeftRight);

	// �t�F�[�h�C���A�E�g
	FadeOut* actionFadeOut = FadeOut::create(5.0f);
	FadeIn* actionFadeIn = FadeIn::create(5.0f);
	Sequence* actionFadeOutIn = Sequence::create(actionFadeOut, actionFadeIn, nullptr);

	//spr->runAction(actionFadeOutIn);
	// �ӂ��̃A�N�V�������J��Ԃ�
	Spawn* actionSpawn = Spawn::create(actionMoveLeftRight, actionFadeOutIn, nullptr);
	Repeat* repeat = Repeat::create(actionSpawn, 5);
	spr->runAction(repeat);

    return true;
}

// �p���I�ɂ�邱��
void HelloWorld::update(float delta)
{
	
}