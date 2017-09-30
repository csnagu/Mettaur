#include "fireworks.h"
#include <math.h>

Fireworks::Fireworks() {
    color.set(col);
    // 花火玉の初期座標。画面下からとびだせ！！
    position.set(ofRandom(ofGetWidth()), ofGetHeight(), 0);
    velocity.set(ofRandom(-10, 10), 100, 0);
    acceleration.set(ofRandom(-10, 10), 100, 0);
    r = 800;          // [cm]
    k = 0.21 / r;
    a = 100;          // 初期加速度。setup()以降は現在の加速度
}

void Fireworks::move() {
    dt = 0.05;
    a = -g - k * sqrt(pow(velocity.y, 2)) * velocity.z; // 加速度の更新
    velocity.y += a * dt;                               // 速度の更新
    position.y -= velocity.y * dt;                      // 花火玉の位置を更新

    if (position.y < 0 || position.y > ofGetHeight()) {
        position.y = ofGetHeight(); // ウィンドウ外へ飛び出たら下端へ固定する
    }
    if (velocity.y <= 0) {
        position.x += velocity.y * dt;
    }
}

void Fireworks::move_sparks() {
    acceleration.set(0, 0, 0);
    acceleration -= drag * velocity;
    velocity += acceleration * dt;
    for (int i=0; i<num; i++){
        alpha = ofRandom(-M_PI, M_PI);
        sparks_pos[i] -= sparks_v[i] * dt*20;
        sphere.set(2, 16);
        sphere.setPosition(sparks_pos[i]);
        sphere.drawWireframe();
    }
}

void Fireworks::draw() {
    ofBoxPrimitive box;
    ofDrawBitmapString("delta t : " + ofToString(dt), 20, 20);
    ofDrawBitmapString("accelaration :\t" + ofToString(a), 20, 80);
    ofDrawBitmapString("velocity :\t" + ofToString(velocity.y), 20, 40);
    ofDrawBitmapString("position : \t" + ofToString(position.y), 20, 60);
    ofSetColor(255);
    ofFill();

    if (velocity.y > 0) {
        sphere.set(10, 15);
        sphere.setPosition(position);
        sphere.drawWireframe();
    }
    if (velocity.y >= 0 && velocity.y <= 30) {
        for (int i=0; i<num; i++) {
            sparks_pos[i] = position;
            sparks_v[i].set(ofRandom(-1.0, 1.0), ofRandom(-1.0, 1.0), ofRandom(-1.0, 1.0));
        }
    }
    if (velocity.y < 0 && position.y < ofGetHeight() * 0.5) {
        // 爆発して欲しい
        ofDrawBitmapString("Boooomb!!!!!!", ofGetWidth() * 0.5, ofGetHeight() * 0.5);
        move_sparks();
    }
    ofSetColor(color);
    // ofCircle(position.x, position.y, 10.0);
}
