#include "fireworks.h"

Fireworks::Fireworks() {
    color.set(255);
    position.x = ofRandom(ofGetWidth());
    position.y = ofGetHeight();
    velocity.x = ofRandom(-10, 10);
    velocity.y = -10;
}

void Fireworks::move() {
    position.y += velocity.y;

    if(position.y < 0){
        position.y = ofGetHeight();
    }
}

void Fireworks::draw() {
    ofSetColor(color);
    ofFill();
    ofCircle(position.x, position.y, 20.0);
}
