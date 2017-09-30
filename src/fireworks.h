#ifndef fireworks_h
#define fireworks_h

#include "ofMain.h"

class Fireworks {
public:
    Fireworks();

    void draw();
    void move();
    void move_sparks();

    const float g = 9.8;     // 重力加速度
    static const int num = 600; // 爆発後の小玉の数

    ofVec3f sparks_pos[num];
    ofVec3f sparks_v[num];
    ofVec3f sparks_a[num];
    ofVec3f position;
    ofVec3f velocity;
    ofVec3f acceleration;
    float drag = 0.3;        // 空気抵抗 
    float r;                 // 玉の半径
    float alpha, beta;       // 花火粒子の単位速度ベクトルの角度
    double k, a, dt;
    ofColor color;
    unsigned short col = 255;

    ofSpherePrimitive sphere;
};
#endif
