//
//  Bar.cpp
//  GameCast
//
//
//

#include "Bar.h"
using namespace std;
using namespace cocos2d;

// Fish *obj = new Fish("a",1);
Bar::Bar()
{
    
}

Bar::Bar(int color)
{
    this->color=color;
}
int Bar::getNumberCat()
{
    return this->numberCat;
}
void Bar::setNumberCat(int color)
{
    this->numberCat = color;
}
void Bar::move(cocos2d::CCPoint point)
{
    float durtion = this->getDuritionMove();
    CCMoveTo *move = CCMoveTo::create(durtion, point);
    CCCallFuncN *remove = CCCallFuncN::create(this, callfuncN_selector(Bar::removeBar));
    CCArray *ar = new CCArray();
    ar->addObject(move);
    ar->addObject(remove);
    CCSequence *sq1 = CCSequence::create(ar);
    this->runAction(sq1);
}
float Bar::getDuritionMove()
{
    return this->duritionMove;
}
void Bar::setDuritionMove(float dt)
{
    this->duritionMove = dt;
}

bool Bar::getDeleted()
{
    return this->deleted;
}
void Bar::setDeleted(bool deleted)
{
    this->deleted = deleted;
}
void Bar::removeBar(cocos2d::CCNode *node)
{
    Bar *e = (Bar*)node;
    e->removeAllChildren();
    e->setDeleted(true);
}

int Bar::getColorBar()
{
    return this->color;
}
void Bar::setColorBar(int color)
{
    this->color=color;
}