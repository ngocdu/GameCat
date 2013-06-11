#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Bar.h"
#include "Cast.h"
using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    this->setTouchEnabled(true);
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);


    // ask director the window size
    CCSize size = CCDirector::sharedDirector()->getWinSize();


    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("background.jpg");

    // position the sprite on the center of the screen
    pSprite->setPosition( ccp(size.width/2, size.height/2) );
    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    //-----------------khoi tao --------------
    sumPoint =0;
    sumCats=0;
    arrayBar =new CCArray();
    arrayCast=new CCArray();
    
    
    CCLabelTTF *lbPoint=CCLabelTTF::create("Point: ", "Times New Roman",24);
    lbPoint->setPosition(ccp(35,size.height/2));
    this->addChild(lbPoint,5);
    
    CCTexture2D *txPoint=new CCTexture2D();
    char strPoint[20] ={0};
    sprintf(strPoint, "%i",sumPoint);
    txPoint->initWithString(strPoint,"Times New Roman",24);
    
    textSumPoint=CCSprite::createWithTexture(txPoint);
    textSumPoint->setPosition(ccp(70,size.height/2));
    this->addChild(textSumPoint);

    //---------------update-------------------
    this->schedule(schedule_selector(HelloWorld::gamelogicAddBar),1);
    this->schedule(schedule_selector(HelloWorld::gamelogicAddCat),2);
    this->schedule(schedule_selector(HelloWorld::updateViTri),0.1);
    this->schedule(schedule_selector(HelloWorld::update),1/50);
    

        
    return true;
}
void HelloWorld::ccTouchesBegan(cocos2d::CCSet * touch,cocos2d::CCEvent* event)
{
	CCTouch *touch1 = (CCTouch*)(touch->anyObject());
	CCPoint p2 = touch1->getLocationInView();
	touchLocation=CCDirector::sharedDirector()->convertToGL(p2);
    
    int kcmin=1000;
    Cast *catmin =NULL;
    CCObject *i;
    CCARRAY_FOREACH(arrayCast, i )
    {
        Cast *cat = (Cast*)i;
        int kc = ccpDistance(this->touchLocation, cat->getPosition());
        if (kc < kcmin && kc < cat->getContentSize().width/2) {
            kcmin=kc;
            catCatched = cat;
        }
    }
    if (catmin != NULL) {
        catCatched->setCatched(true);
    }
    
    
}
void HelloWorld::ccTouchesMoved(cocos2d::CCSet* touch,cocos2d::CCEvent* event)
{
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    CCTouch *touch1 = (CCTouch*)(touch->anyObject());
	CCPoint p2 = touch1->getLocationInView();
	touchLocation=CCDirector::sharedDirector()->convertToGL(p2);
    
    if (catCatched != NULL) {
        catCatched->stopAllActions();
        catCatched->setPosition(touchLocation);
    }
    
    
}
void HelloWorld::ccTouchesEnded(cocos2d::CCSet* touches,cocos2d::CCEvent* event)
{
    if (catCatched != NULL ) {
        
        int d =0;
        CCObject *i;
        CCARRAY_FOREACH(arrayBar, i)
        {
            Bar *bar = (Bar*)i;
            int kc = ccpDistance(catCatched->getPosition(), bar->getPosition());
            if (kc < bar->getContentSize().width/3 && bar->getColorBar()==catCatched->getColorCast() && bar->getNumberCat()<1) {
                Cast *ca = new Cast(catCatched->getColorCast(),catCatched->getDuritionMove());
                ca->initWithFile("Cats_01.png");
                if (catCatched->getColorCast() ==0) {
                    ca->setColor(ccc3(0, 0, 0));
                }
                else if (catCatched->getColorCast()==1)
                {
                    ca->setColor(ccc3(0, 255, 0));
                }
                else if (catCatched->getColorCast()==2)
                {
                    
                }
                else if (catCatched->getColorCast()==3)
                {
                    ca->setColor(ccc3(255, 0, 0));
                }
                else if (catCatched->getColorCast()==4)
                {
                    ca->setColor(ccc3(255, 255, 0));
                }
                bar->setNumberCat(1);
                ca->setHuongDiChuyen(catCatched->getHuongDiChuyen());
                ca->setScale(catCatched->getScale());
                ca->setPosition(ccp(bar->getContentSize().width/2,bar->getContentSize().height/2));
                
                CCRotateTo *rotate1 = CCRotateTo::create(0.3, 45);
                CCRotateTo *rotate2 = CCRotateTo::create(0.3, -45);
                
                CCArray *array = new CCArray();
                array->addObject(rotate1);
                array->addObject(rotate2);
                CCSequence *sq = CCSequence::create(array);
                CCRepeatForever *re = CCRepeatForever::create(sq);
                
                ca->runAction(re);
                bar->addChild(ca);
                
                
                arrayCast->removeObject(catCatched);
                this->removeChild(catCatched, true);
                sumCats--;
                sumPoint++;
                
                d++;
                break;
            }
            
        }
        
        if (d==0) {
            catCatched->moveDown();
            catCatched->setCatched(false);
        }
        
    }
	
}
void HelloWorld::addBars()
{
    CCSize size=CCDirector::sharedDirector()->getWinSize();
    int color = rand() % 5;
    Bar *bar;
    bar =new Bar(color);
    if (color==0) {
        
        bar->initWithFile("LongBlack2.png");
    }
    else if (color==1)
    {
        bar->initWithFile("LongGreen2.png");
    }
    else if (color==2)
    {
        bar->initWithFile("LongOrange2.png");
    }
    else if (color==3)
    {
        bar->initWithFile("LongRed2.png");
    }
    else if (color==4)
    {
        bar->initWithFile("LongWhite2.png");
        bar->setColor(ccc3(255, 255, 0));
    }
    bar->setNumberCat(0);
    bar->setDuritionMove(10);
    bar->setPosition(ccp(-30,size.height - size.height/4));
    bar->move(ccp(size.width + size.width/4, size.height - size.height/4));
    
    arrayBar->addObject(bar);
    this->addChild(bar,1);
}
void HelloWorld::addCats()
{
    CCSize size =CCDirector::sharedDirector()->getWinSize();
    int color = rand() % 5;
    int duritionmove = rand() % 5 +15;
    Cast *cat = new Cast(color ,duritionmove);
    cat->setPosition(ccp(-100,(float)(rand()%(int)size.height/3 + 50)));
    cat->setViTri(cat->getPosition());
    cat->initWithFile("Cats_01.png");
    cat->move();
    cat->setHuongDiChuyen(0);
    cat->setScale((rand() % 5)/10 + 2.7);
    cat->setCatched(false);
    arrayCast->addObject(cat);
    this->addChild(cat, 2);
    this->sumCats ++;
}
void HelloWorld::gamelogicAddCat(float dt)
{
    if (sumCats < 10) {
        this->addCats();
    }
    
}
void HelloWorld::gamelogicAddBar(float dt)
{
    this->addBars();
}
void HelloWorld::updateViTri(float dt)
{
    CCObject *i;
    CCARRAY_FOREACH(arrayCast, i)
    {
        Cast *cat =(Cast*)i;
        cat->setViTri(cat->getPosition());
    }
}
void HelloWorld::update(float dt)
{
    CCObject *i;
    CCARRAY_FOREACH(arrayCast, i)
    {
        Cast *cat = (Cast*)i;
        if (cat->getPosition().x < cat->getViTri().x && cat->getHuongDiChuyen()==1) {
            cat->setFlipX(true);
            cat->setHuongDiChuyen(0);
        }
        else if(cat->getPosition().x > cat->getViTri().x && cat->getHuongDiChuyen()==0)
        {
            cat->setFlipX(false);
            cat->setHuongDiChuyen(1);
        }
    }
    
    
    CCTexture2D *txPoint=new CCTexture2D();
    char strPoint[20] ={0};
    sprintf(strPoint, "%i",sumPoint);
    txPoint->initWithString(strPoint,"Times New Roman",24);
    textSumPoint->setTexture(txPoint);
}
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
