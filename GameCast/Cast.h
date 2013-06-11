//
//  Cast.h
//  GameCast
//
//
//

#ifndef GameCast_Cast_h
#define GameCast_Cast_h

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace std;
class Cast : public cocos2d::CCSprite
{
private:
	
	int point;
    int color;
    int direction;//de biet xem con meo chay tu ben trai hay ben phai sang
    bool deleted;//dung de xoa con meo di
    float duritionMove;//thoi gian di chuyen quy dinh toc do chay cua con meo
    bool flip;
    cocos2d::CCPoint vitri;
    int huongDiChuyen; // 0 = left 1 = right
    bool catched; // xet xem da bi bat hay chua
	
public:
	Cast();
	Cast(int  color,float duritionMove);// ham tao co doi so
    
	int getPoint();
	void setPoint(int point );
    bool getFlip();
	void setFlip(bool fl );
    
    bool getCatched();
	void setCatched(bool fl );
    
    int getColorCast();
	void setColorCast(int color );
    
    int getHuongDiChuyen();
	void setHuongDiChuyen(int color );
    
    int getDirection();
	void setDirection(int point );
    void removeCast(cocos2d::CCNode * node);
    void doiChieu(cocos2d::CCNode *node);
    
    void move();
    void moveDown();
    bool getDeleted();
    void setDeleted(bool deleted);
	float getDuritionMove();
    void setDuritionMove(float dt);
    
    cocos2d::CCPoint getViTri();
    void setViTri(cocos2d::CCPoint p);

};


#endif
