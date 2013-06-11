//
//  Bar.h
//  GameCast
//
//
//

#ifndef GameCast_Bar_h
#define GameCast_Bar_h

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace std;
class Bar : public cocos2d::CCSprite
{
private:
    int color;
    bool deleted;//dung de xoa bar di
	float duritionMove;
    int numberCat;
public:
	Bar();
	Bar(int  color);// ham tao co doi so
    
    
    int getColorBar();
	void setColorBar(int color );
    
    int getNumberCat();
	void setNumberCat(int color );
    
    
    void removeBar(cocos2d::CCNode * node);
    
    void move(cocos2d::CCPoint point1);
    
    bool getDeleted();
    void setDeleted(bool deleted);
    
    float getDuritionMove();
    void setDuritionMove(float dt);
    
};


#endif
