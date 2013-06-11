#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Cast.h"

class HelloWorld : public cocos2d::CCLayer
{
private:
    cocos2d::CCArray *arrayBar;
    cocos2d::CCArray *arrayCast;
    int sumPoint;
    int sumCats;
    cocos2d::CCPoint touchLocation;
    Cast *catCatched;
    cocos2d:: CCSprite * textSumPoint;
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();

    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    void addBars();
    void gamelogicAddBar(float dt);
    
    void addCats();
    void gamelogicAddCat(float dt);
    
    void updateViTri(float dt);
    void update(float dt);
    
    virtual void ccTouchesBegan(cocos2d::CCSet * touch,cocos2d::CCEvent* event);
	virtual void ccTouchesMoved(cocos2d::CCSet* touch,cocos2d::CCEvent* event);
	virtual void ccTouchesEnded(cocos2d::CCSet* touches,cocos2d::CCEvent* event);

    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
