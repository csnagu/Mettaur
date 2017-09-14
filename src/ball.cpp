#include "ball.h"

Ball::Ball() {
    // 初期の色を設定する
    color.set( ofRandom(255), ofRandom(255), ofRandom(255));

    // 初期のＸ,Y座標を設定する
    x = ofRandom( ofGetWindowWidth() );
    y = ofRandom( ofGetWindowHeight() );
}

void Ball::moveTo(int _xDestiny, int _yDestiny){
    x += ( _xDestiny - x) * 0.1;
    y += ( _yDestiny - y) * 0.1;
}

void Ball::draw(){
    ofSetColor(color);
    ofFill();
    ofCircle(x, y, 30.0);
}

void Ball::changeColor() {
    color.set( ofRandom(255), ofRandom(255), ofRandom(255));
}
