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
    ofColor color;
};
#endif
