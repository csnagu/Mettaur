#ifndef fireworks_h
#define fireworks_h

#include "ofMain.h"

class Fireworks {
public:
    Fireworks();

    void draw();
    void move();

    ofVec2f position;
    ofVec2f velocity;
    const float g = 9.8;     // 重力加速度
    float r;                 // 玉の半径
    double k, a, dt;
    ofColor color;
};
#endif
