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

const int POS_ARRAY_NUM = 8;

// 出現位置リスト
Vec2 pos_array[POS_ARRAY_NUM] =
{
	Vec2(-100,720.0f / 3 * 1),
	Vec2(-100,720.0f / 3 * 2),
	Vec2(1280+100,720.0f / 3 * 1),
	Vec2(1280+100,720.0f / 3 * 2),
	Vec2(1280.0f / 3 * 1,-100),
	Vec2(1280.0f / 3 * 2,-100),
	Vec2(1280.0f / 3 * 1,720+100),
	Vec2(1280.0f / 3 * 2,720+100),
};

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
	
	// 背景
	Sprite* spr_bg = Sprite::create("fence.png");
	spr_bg->setScale(2.5f);
	spr_bg->setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 2.0f));
	addChild(spr_bg);

	for (int i = 0; i < FLY_NUM; i++)
	{
		// スプライトを作る
		spr[i] = Sprite::create("fly.png");
		addChild(spr[i]);
		// 位置を設定する
		Vec2 startpos, endpos;
		int pos_index = rand() % POS_ARRAY_NUM;
		startpos = pos_array[pos_index];
		pos_index = rand() % POS_ARRAY_NUM;
		endpos = pos_array[pos_index];
		Vec2 direction = endpos - startpos;
		float angle = atan2f(direction.y, direction.x);
		spr[i]->setRotation(-CC_RADIANS_TO_DEGREES(angle)+90);

		spr[i]->setPosition(startpos);
		spr[i]->setScale(0.2f);

		// 待機アクション
		DelayTime* actionDelay = DelayTime::create((float)i);
		// 移動アクション
		MoveTo* actionMove = MoveTo::create(5.0f, endpos);

		Sequence* actionSeq = Sequence::create(actionDelay, actionMove, nullptr);

		spr[i]->runAction(actionSeq);

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

	for (int i = 0; i < FLY_NUM; i++)
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
				spr[i]->stopAllActions();
				//spr[i]->stopActionByTag(100);
				spr[i]->setTexture("fly_death.png");

				MoveBy* action = MoveBy::create(1.0f, Vec2(0, -1000));
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