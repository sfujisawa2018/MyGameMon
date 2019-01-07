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
// 最初に一度だけやること
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

	// 画面サイズの取得
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	// 自分で作った関数を、呼び出されるように設定
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(HelloWorld::onTouchCancelled, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	for (int i = 0; i < 10; i++)
	{
		// スプライトを作る
		spr[i] = Sprite::create("mario.jpg");
		addChild(spr[i]);
		// 位置を設定する
		float x = (float)rand() / RAND_MAX * 1280;
		float y = (float)rand() / RAND_MAX * 720;
		spr[i]->setPosition(Vec2(x, y));
		spr[i]->setScale(0.2f);

		x = (float)rand() / RAND_MAX * 1280;
		y = (float)rand() / RAND_MAX * 720;

		// 移動アクション
		MoveTo* action1 = MoveTo::create(5.0f, Vec2(x, y));
		// アクションに番号（タグ）をふる
		action1->setTag(100);
		spr[i]->runAction(action1);
		// 点滅アクション
		Blink* action2 = Blink::create(5.0f, 10);
		spr[i]->runAction(action2);
	}

	//// ３秒後にMyFunctionを実行するアクション
	//CallFunc* action10 = CallFunc::create(
	//	CC_CALLBACK_0(HelloWorld::MyFunction, this)
	//);
	//DelayTime* action11 = DelayTime::create(3.0f);
	//Sequence* action12 = Sequence::create(
	//	action11, action10, nullptr);

	//this->runAction(action12);

    return true;
}

// 継続的にやること
void HelloWorld::update(float delta)
{
	
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* unused_event)
{
	// タッチ座標
	Vec2 touch_pos = touch->getLocation();

	for (int i = 0; i < 10; i++)
	{
		if (spr[i] != nullptr)
		{
			// スプライトの矩形を取得
			Rect rect_spr = spr[i]->getBoundingBox();
			// スプライトとタッチ点の当たり判定
			bool hit = rect_spr.containsPoint(touch_pos);

			// スプライトをタッチした？
			if (hit)
			{
				log("touch sprite!!");
				// アクションを全て止める
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
	// 指定番号のアクションを止める
	//spr->stopActionByTag(100);
	// スプライトのアクションを全て止める
	//spr->stopAllActions();
}