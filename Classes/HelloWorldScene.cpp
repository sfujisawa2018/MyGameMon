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

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
        problemLoading("'HelloWorld.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }

	//sprite2 = Sprite::create("mario.jpg");
	//this->addChild(sprite2);

	//spriteKuppa = Sprite::create("kuppa.jpg");
	//spriteKuppa->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));
	//this->addChild(spriteKuppa);
	//// ���S�ɓ����ɂ���
	//spriteKuppa->setOpacity(0);
	//spriteKuppa->setAnchorPoint(Vec2(0.5f, 0));
	// ���W�w��
	//sprite2->setPosition(Vec2(200.0f, 200.0f));
	
	// ���W�w��
	//sprite2->setPosition(Vec2(visibleSize.width/2.0f, visibleSize.height/2.0f));
	//sprite2->setPosition(Vec2(1024-162.5f*0.5f, 768-225.0f*0.5f));
	//sprite2->setPosition(
	//	Vec2(
	//		visibleSize.width - 162.5f*0.5f,
	//		visibleSize.height - 225.0f*0.5f));
	// �s�����x���ő�l��
	//sprite2->setOpacity(255);

	//sprite2->setRotation(-45.0f);
	//sprite2->setScale(0.8f, 0.8f);
	//sprite2->setFlippedX(true);
	// ����(0,0)
	// �E��(1,0)
	// ����(0,1)
	// �E��(1,1)
	//sprite2->setAnchorPoint(Vec2(0.5f, 0));
	// ���㒆�S�ɐݒ�
	//sprite2->setAnchorPoint(Vec2(0, 1));
	//sprite2->setFlippedY(true);
	//sprite2->setVisible(false);
	//                         Red  Green  Blue
	// �ԐF�ɐݒ�
	//sprite2->setColor(Color3B(255, 0, 0));
	//sprite2->setOpacity(0x80);
	//sprite2->setColor(Color3B(255, 255, 255));

	// �A�N�V�����̍쐬�i�P�b�|���ĉE�ɂQ�O�O�A��ɂP�O�O�ړ��j
	//                               2�b�Ł@�@�w����W�Ɂ@�@����300�łP��W�����v
	///JumpTo* action1 = JumpTo::create(2.0f, Vec2(1000, 200), 300, 3);

	// 360�x�ȏ��]������ꍇ�́ARotateBy���g�����B
	//RotateBy* action1 = RotateBy::create(5.0f, 360.0f);
	//ccBezierConfig config;
	//config.controlPoint_1 = Vec2(0, 200);
	//config.controlPoint_2 = Vec2(500, 200);
	//config.endPosition = Vec2(1000, 200);
	//BezierTo* action1 = BezierTo::create(1.0f, config);
	//// �m�[�h�ɑ΂��ăA�N�V���������s����
	//sprite2->runAction(action1);

	//Sprite* spr = Sprite::create("Kuppa.jpg");
	//this->addChild(spr);
	//spr->setPosition(Vec2(300, 200));

	// �A�N�V�����̍쐬
	//MoveBy* action1 = MoveBy::create(2.0f, Vec2(400, 400));
	// �A�N�V�����ɑ΂��āA�C�[�W���O��t�����A�N�V�����̍쐬
	//EaseBackIn* action2 = EaseBackIn::create(action1);
	//spr->runAction(action1);
	// �C�[�W���O�t���A�N�V�����̎��s
	//spr->runAction(action2);

	//// ���t���[���X�V������L���ɂ���
	//this->scheduleUpdate();

	//time = 0;
	//// ���ړ�����B
	//moveDirection = Left;

	// �����_���̏�����
	srand(::time(0));

	Sprite* sprMario[10];
	// �}���I
	for (int i = 0; i < 10; i++)
	{
		sprMario[i] = Sprite::create("mario.jpg");
		this->addChild(sprMario[i]);
		float rnd1 = (float)rand()/RAND_MAX * 1280;
		float rnd2 = (float)rand()/RAND_MAX * 720;
		sprMario[i]->setPosition(Vec2(rnd1, rnd2));
		sprMario[i]->setScale(0.1f);
		float rnd3 = (float)rand() / RAND_MAX * 600 - 300;
		float rnd4 = (float)rand() / RAND_MAX * 600 - 300;
		MoveBy* action1 = MoveBy::create(2.0f, Vec2(rnd3, rnd4));
		sprMario[i]->runAction(action1);
	}

	//sprMario[3]->setColor(Color3B(255, 0, 0));

	//// �N�b�p
	//Sprite* sprKuppa = Sprite::create("Kuppa.jpg");
	//this->addChild(sprKuppa);
	//sprKuppa->setPosition(Vec2(900, 360));
	////MoveBy* action2 = MoveBy::create(2.0f, Vec2(-100, -100));
	//// �A�N�V�����̕���
	//MoveBy* action2 = action1->clone();
	//sprKuppa->runAction(action2);
	//// *�P�̃A�N�V�����𕡐��̃X�v���C�g�ɂ����邱�Ƃ͂ł��Ȃ��B

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}

// �p���I�ɂ�邱��
void HelloWorld::update(float delta)
{
	// ��]
	//{
	//	// ���݂̊p�x���擾
	//	float rot = sprite2->getRotation();
	//	// �p�x�����炷
	//	rot += 1.0f;
	//	// �p�x��ݒ�
	//	sprite2->setRotation(rot);
	//}
	//////Color3B color = sprite2->getColor();
	//switch(moveDirection)
	//{
	//case Left:
	//	{
	//		// ���̍��W���擾
	//		Vec2 pos = sprite2->getPosition();
	//		// ���W�����炷
	//		pos += Vec2(-5.0f, 0.0f);
	//		// ���W��ݒ�
	//		sprite2->setPosition(pos);
	//		// ���[�ɓ��B�����牺�ړ��ɐ؂�ւ�
	//		if (pos.x <= 162.5f * 0.5f)
	//		{
	//			moveDirection = Down;
	//		}
	//		break;
	//	}
	//case Down:
	//	{
	//		// ���̍��W���擾
	//		Vec2 pos = sprite2->getPosition();
	//		// ���W�����炷
	//		pos += Vec2(0.0f, -5.0f);
	//		// ���W��ݒ�
	//		sprite2->setPosition(pos);
	//		// ���[�ɓ��B������E�ړ��ɐ؂�ւ�
	//		if (pos.y <= 225.0f * 0.5f)
	//		{
	//			moveDirection = Right;
	//		}
	//		break;
	//	}
	//default:
	//	break;
	//}
	// ���񂾂񓧖���
#if 0
	{
		time += delta;
		//// ���̕s�����x���擾
		//unsigned char opacity = sprite2->getOpacity();
		//// �s�����x�����炷
		//// 0����1����ƍő�l��255�ɂȂ�
		//opacity--;  // opacity = opacity - 1;
		// �s�����x��ݒ肷��
		// time:0.0f ... opacity:255
		// time:5.0f ... opacity:0
		if (time > 5.0f) time = 5.0f;
		unsigned char opacity = (5.0f-time) * 255 / 5.0f;
		sprite2->setOpacity(opacity);

	}
#endif
#if 0 //�Ԃ����
	{
		// �o�ߕb�������Z���Ă���
		time += delta;
		// �R�b�ȏ�͂R�b�Ɠ�������
		if (time > 3.0f) time = 3.0f;

		// �ԗv�f�͍ő�l����͂��܂��ĂR�b��0�ɁB
		unsigned char r = (3.0f - time) * 255 / 3.0f;
		// �v�f��0����͂��܂��ĂR�b�ōő�l�ɁB
		unsigned char b = (time) * 255 / 3.0f;
		sprite2->setColor(Color3B(r,0,b));

	}
#endif

	// �N���X�t�F�[�h
#if 0
	{
		time += delta;

		// �T�b�𒴂��Ă��T�b�������ɂ���
		if (time > 5.0f) time = 5.0f;
		// �s�����x�̌v�Z              �ő�l�@�ő�ɂȂ鎞��
		// ���x�T�b���_��opacity���ő��255�ɂȂ�
		unsigned char opacity = time * 255 / 5.0f;
		// �T�b�|���ĕs�������瓧����
		sprite2->setOpacity(255-opacity);
		// �T�b�|���ē�������s������
		spriteKuppa->setOpacity(opacity);
	}
#endif

}