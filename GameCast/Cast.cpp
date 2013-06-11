//
//  Cast.cpp
//  GameCast
//
//
//

#include "Cast.h"

using namespace std;
using namespace cocos2d;

// Fish *obj = new Fish("a",1);
Cast::Cast()
{
    
}

Cast::Cast(int color,float duritionmove)
{
    this->color=color;
    this->duritionMove=duritionmove;
}

int Cast::getPoint()
{
    return this->point;
}
void Cast::setPoint(int point)
{
    this->point=point;
}

int Cast::getDirection()
{
    return this->direction;
}
void Cast::setDirection(int direction)
{
    this->direction = direction;
}

int Cast::getHuongDiChuyen()
{
    return this->huongDiChuyen;
}
void Cast::setHuongDiChuyen(int direction)
{
    this->huongDiChuyen = direction;
}

CCPoint Cast::getViTri()
{
    return this->vitri;
}
void Cast::setViTri(cocos2d::CCPoint p)
{
    this->vitri = p;
}
void Cast::move()
{
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    CCPoint p1 = ccp((float)(rand() % (int)size.width/2 + size.width/2+300),(float) (rand() % (int)size.height/3));
    CCPoint p2 = ccp((float)(rand() % (int)size.width/2 - 700),(float) (rand() % (int)size.height/3));
    CCPoint p3 = ccp((float)(rand() % (int)size.width/2 + 800),(float) (rand() % (int)size.height/3));
    CCPoint p4 = ccp((float)(rand() % (int)size.width/2 - 700),(float) (rand() % (int)size.height/3));
    CCPoint p5 = ccp((float)(size.width/2 + 200),(float) (rand() % (int)size.height/3));
    
    CCMoveTo *move1 = CCMoveTo::create(this->getDuritionMove()/(rand() % 4 +1 ), p1);
    CCMoveTo *move2 = CCMoveTo::create(this->getDuritionMove()/(rand() % 4 +1 ), p2);
    CCMoveTo *move3 = CCMoveTo::create(this->getDuritionMove()/(rand() % 4 +1 ), p3);
    CCMoveTo *move4 = CCMoveTo::create(this->getDuritionMove()/(rand() % 4 +1 ), p4);
    CCMoveTo *move5 = CCMoveTo::create(this->getDuritionMove()/(rand() % 4 +5 ), p5);
    CCCallFuncN *remove = CCCallFuncN::create(this, callfuncN_selector(Cast::removeCast));
    CCArray *armv= new CCArray();
    armv->addObject(move1);
    armv->addObject(move2);
    armv->addObject(move3);
    armv->addObject(move4);
    armv->addObject(move5);
    armv->addObject(remove);
    CCSequence *sq  =CCSequence::create(armv);
    CCRepeatForever *re= CCRepeatForever::create(sq);
    this->runAction(re);
    if (this->getColorCast()==0) {//color black
        
        CCSpriteFrameCache *catRight = CCSpriteFrameCache::sharedSpriteFrameCache();
        catRight->addSpriteFramesWithFile("orangeCatRight.plist");
        CCArray *catRightFrames = CCArray::createWithCapacity(4);
        char str[100];
        for (int i = 5; i<= 8; i++) {
            sprintf(str, "CatSide%d.png", i);
            CCSpriteFrame *catRightFrame = catRight->spriteFrameByName(str);
            catRightFrames->addObject(catRightFrame);
        }
        
        CCAnimation *catRightAnim =CCAnimation::createWithSpriteFrames(catRightFrames, 0.1f);
        CCFiniteTimeAction *catRightAnimate =CCRepeatForever::create(CCAnimate::create(catRightAnim));
        catRightAnimate->setTag(11);
        this->setScale(3);
        this->setColor(ccc3(0, 0, 0));
        this->runAction(catRightAnimate);
        
    }
    else if (this->getColorCast()==1) //color Green
    {
        CCSpriteFrameCache *catRight = CCSpriteFrameCache::sharedSpriteFrameCache();
        catRight->addSpriteFramesWithFile("orangeCatRight.plist");
        CCArray *catRightFrames = CCArray::createWithCapacity(4);
        char str[100];
        for (int i = 5; i<= 8; i++) {
            sprintf(str, "CatSide%d.png", i);
            CCSpriteFrame *catRightFrame = catRight->spriteFrameByName(str);
            catRightFrames->addObject(catRightFrame);
        }
        
        CCAnimation *catRightAnim =CCAnimation::createWithSpriteFrames(catRightFrames, 0.1f);
        CCFiniteTimeAction *catRightAnimate =CCRepeatForever::create(CCAnimate::create(catRightAnim));
        catRightAnimate->setTag(11);
        this->setScale(3);
        this->setColor(ccc3(0, 255, 0));
        this->runAction(catRightAnimate);
    }
    else if (this->getColorCast()==2) // color Orange
    {
        CCSpriteFrameCache *catRight = CCSpriteFrameCache::sharedSpriteFrameCache();
        catRight->addSpriteFramesWithFile("orangeCatRight.plist");
        CCArray *catRightFrames = CCArray::createWithCapacity(4);
        char str[100];
        for (int i = 5; i<= 8; i++) {
            sprintf(str, "CatSide%d.png", i);
            CCSpriteFrame *catRightFrame = catRight->spriteFrameByName(str);
            catRightFrames->addObject(catRightFrame);
        }
        
        CCAnimation *catRightAnim =CCAnimation::createWithSpriteFrames(catRightFrames, 0.1f);
        CCFiniteTimeAction *catRightAnimate =CCRepeatForever::create(CCAnimate::create(catRightAnim));
        catRightAnimate->setTag(11);
        this->setScale(3);
        //this->setColor(ccc3(0, 255, 0));
        this->runAction(catRightAnimate);
    }
    else if (this->getColorCast()==3) // color Red
    {
        CCSpriteFrameCache *catRight = CCSpriteFrameCache::sharedSpriteFrameCache();
        catRight->addSpriteFramesWithFile("orangeCatRight.plist");
        CCArray *catRightFrames = CCArray::createWithCapacity(4);
        char str[100];
        for (int i = 5; i<= 8; i++) {
            sprintf(str, "CatSide%d.png", i);
            CCSpriteFrame *catRightFrame = catRight->spriteFrameByName(str);
            catRightFrames->addObject(catRightFrame);
        }
        
        CCAnimation *catRightAnim =CCAnimation::createWithSpriteFrames(catRightFrames, 0.1f);
        CCFiniteTimeAction *catRightAnimate =CCRepeatForever::create(CCAnimate::create(catRightAnim));
        catRightAnimate->setTag(11);
        this->setScale(3);
        this->setColor(ccc3(255, 0, 0));
        this->runAction(catRightAnimate);
    }
    else if (this->getColorCast()==4) // color White
    {
        CCSpriteFrameCache *catRight = CCSpriteFrameCache::sharedSpriteFrameCache();
        catRight->addSpriteFramesWithFile("orangeCatRight.plist");
        CCArray *catRightFrames = CCArray::createWithCapacity(4);
        char str[100];
        for (int i = 5; i<= 8; i++) {
            sprintf(str, "CatSide%d.png", i);
            CCSpriteFrame *catRightFrame = catRight->spriteFrameByName(str);
            catRightFrames->addObject(catRightFrame);
        }
        
        CCAnimation *catRightAnim =CCAnimation::createWithSpriteFrames(catRightFrames, 0.1f);
        CCFiniteTimeAction *catRightAnimate =CCRepeatForever::create(CCAnimate::create(catRightAnim));
        catRightAnimate->setTag(11);
        this->setScale(3);
        this->setColor(ccc3(255, 255, 0));
        this->runAction(catRightAnimate);
    }
    

}
void Cast::moveDown()
{
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    CCPoint p = CCPoint(this->getViTri().x,rand() % 100);
    CCPoint p1 = ccp((float)(rand() % (int)size.width/2 + size.width/2+300),(float) (rand() % (int)size.height/3));
    CCPoint p2 = ccp((float)(rand() % (int)size.width/2 - 700),(float) (rand() % (int)size.height/3));
    CCPoint p3 = ccp((float)(rand() % (int)size.width/2 + 800),(float) (rand() % (int)size.height/3));
    CCPoint p4 = ccp((float)(rand() % (int)size.width/2 - 700),(float) (rand() % (int)size.height/3));
    CCPoint p5 = ccp((float)(size.width/2 + 200),(float) (rand() % (int)size.height/3));
    
    CCMoveTo *move = CCMoveTo::create(0.8, p);
    CCMoveTo *move1 = CCMoveTo::create(this->getDuritionMove()/(rand() % 4 +1 ), p1);
    CCMoveTo *move2 = CCMoveTo::create(this->getDuritionMove()/(rand() % 4 +1 ), p2);
    CCMoveTo *move3 = CCMoveTo::create(this->getDuritionMove()/(rand() % 4 +1 ), p3);
    CCMoveTo *move4 = CCMoveTo::create(this->getDuritionMove()/(rand() % 4 +1 ), p4);
    CCMoveTo *move5 = CCMoveTo::create(this->getDuritionMove()/(rand() % 4 +5 ), p5);
    CCCallFuncN *remove = CCCallFuncN::create(this, callfuncN_selector(Cast::removeCast));
    CCArray *armv= new CCArray();
    armv->addObject(move);
    armv->addObject(move1);
    armv->addObject(move2);
    armv->addObject(move3);
    armv->addObject(move4);
    armv->addObject(move5);
    armv->addObject(remove);
    CCSequence *sq  =CCSequence::create(armv);
    CCRepeatForever *re= CCRepeatForever::create(sq);
    this->runAction(re);
    if (this->getColorCast()==0) {//color black
        
        CCSpriteFrameCache *catRight = CCSpriteFrameCache::sharedSpriteFrameCache();
        catRight->addSpriteFramesWithFile("orangeCatRight.plist");
        CCArray *catRightFrames = CCArray::createWithCapacity(4);
        char str[100];
        for (int i = 5; i<= 8; i++) {
            sprintf(str, "CatSide%d.png", i);
            CCSpriteFrame *catRightFrame = catRight->spriteFrameByName(str);
            catRightFrames->addObject(catRightFrame);
        }
        
        CCAnimation *catRightAnim =CCAnimation::createWithSpriteFrames(catRightFrames, 0.1f);
        CCFiniteTimeAction *catRightAnimate =CCRepeatForever::create(CCAnimate::create(catRightAnim));
        catRightAnimate->setTag(11);
        this->setScale(3);
        this->setColor(ccc3(0, 0, 0));
        this->runAction(catRightAnimate);
        
    }
    else if (this->getColorCast()==1) //color Green
    {
        CCSpriteFrameCache *catRight = CCSpriteFrameCache::sharedSpriteFrameCache();
        catRight->addSpriteFramesWithFile("orangeCatRight.plist");
        CCArray *catRightFrames = CCArray::createWithCapacity(4);
        char str[100];
        for (int i = 5; i<= 8; i++) {
            sprintf(str, "CatSide%d.png", i);
            CCSpriteFrame *catRightFrame = catRight->spriteFrameByName(str);
            catRightFrames->addObject(catRightFrame);
        }
        
        CCAnimation *catRightAnim =CCAnimation::createWithSpriteFrames(catRightFrames, 0.1f);
        CCFiniteTimeAction *catRightAnimate =CCRepeatForever::create(CCAnimate::create(catRightAnim));
        catRightAnimate->setTag(11);
        this->setScale(3);
        this->setColor(ccc3(0, 255, 0));
        this->runAction(catRightAnimate);
    }
    else if (this->getColorCast()==2) // color Orange
    {
        CCSpriteFrameCache *catRight = CCSpriteFrameCache::sharedSpriteFrameCache();
        catRight->addSpriteFramesWithFile("orangeCatRight.plist");
        CCArray *catRightFrames = CCArray::createWithCapacity(4);
        char str[100];
        for (int i = 5; i<= 8; i++) {
            sprintf(str, "CatSide%d.png", i);
            CCSpriteFrame *catRightFrame = catRight->spriteFrameByName(str);
            catRightFrames->addObject(catRightFrame);
        }
        
        CCAnimation *catRightAnim =CCAnimation::createWithSpriteFrames(catRightFrames, 0.1f);
        CCFiniteTimeAction *catRightAnimate =CCRepeatForever::create(CCAnimate::create(catRightAnim));
        catRightAnimate->setTag(11);
        this->setScale(3);
        //this->setColor(ccc3(0, 255, 0));
        this->runAction(catRightAnimate);
    }
    else if (this->getColorCast()==3) // color Red
    {
        CCSpriteFrameCache *catRight = CCSpriteFrameCache::sharedSpriteFrameCache();
        catRight->addSpriteFramesWithFile("orangeCatRight.plist");
        CCArray *catRightFrames = CCArray::createWithCapacity(4);
        char str[100];
        for (int i = 5; i<= 8; i++) {
            sprintf(str, "CatSide%d.png", i);
            CCSpriteFrame *catRightFrame = catRight->spriteFrameByName(str);
            catRightFrames->addObject(catRightFrame);
        }
        
        CCAnimation *catRightAnim =CCAnimation::createWithSpriteFrames(catRightFrames, 0.1f);
        CCFiniteTimeAction *catRightAnimate =CCRepeatForever::create(CCAnimate::create(catRightAnim));
        catRightAnimate->setTag(11);
        this->setScale(3);
        this->setColor(ccc3(255, 0, 0));
        this->runAction(catRightAnimate);
    }
    else if (this->getColorCast()==4) // color White
    {
        CCSpriteFrameCache *catRight = CCSpriteFrameCache::sharedSpriteFrameCache();
        catRight->addSpriteFramesWithFile("orangeCatRight.plist");
        CCArray *catRightFrames = CCArray::createWithCapacity(4);
        char str[100];
        for (int i = 5; i<= 8; i++) {
            sprintf(str, "CatSide%d.png", i);
            CCSpriteFrame *catRightFrame = catRight->spriteFrameByName(str);
            catRightFrames->addObject(catRightFrame);
        }
        
        CCAnimation *catRightAnim =CCAnimation::createWithSpriteFrames(catRightFrames, 0.1f);
        CCFiniteTimeAction *catRightAnimate =CCRepeatForever::create(CCAnimate::create(catRightAnim));
        catRightAnimate->setTag(11);
        this->setScale(3);
        this->setColor(ccc3(255, 255, 0));
        this->runAction(catRightAnimate);
    }
    
}
bool Cast::getDeleted()
{
    return this->deleted;
}
void Cast::setDeleted(bool deleted)
{
    this->deleted = deleted;
}

bool Cast::getCatched()
{
    return this->catched;
}
void Cast::setCatched(bool deleted)
{
    this->catched = deleted;
}


void Cast::removeCast(cocos2d::CCNode *node)
{
    Cast *e = (Cast*)node;
    e->setDeleted(true);
}
float Cast::getDuritionMove()
{
    return this->duritionMove;
}
void Cast::setDuritionMove(float dt)
{
    this->duritionMove = dt;
}
int Cast::getColorCast()
{
    return this->color;
}
void Cast::setColorCast(int color)
{
    this->color=color;
}
bool Cast::getFlip()
{
    return this->getFlip();
}
void Cast::setFlip(bool fl)
{
    this->flip = fl;
}
void Cast::doiChieu(cocos2d::CCNode *node)
{
    Cast *cat = (Cast*)node;
    if (this->flip == true) {
        cat->setFlipX(true);
    }
}