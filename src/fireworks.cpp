#include "fireworks.h"
#include <math.h>

Fireworks::Fireworks() {
  color.set(255);
  // 花火玉の初期座標。画面下からとびだせ！！
  position.x = ofRandom(ofGetWidth());
  position.y = ofGetHeight();
  velocity.x = ofRandom(-10, 10);
  velocity.y = 100; // 初速度。setup()以降は現在の速度
  r = 800;          // [cm]
  k = 0.21 / r;
  a = 100;          // 初期加速度。setup()以降は現在の加速度
}

void Fireworks::move() {
  dt = 0.05;
  a = -g - k * sqrt(pow(velocity.y, 2)) * velocity.y; // 加速度の更新
  velocity.y += a * dt;                               // 速度の更新
  position.y -= velocity.y * dt;                      // 花火玉の位置を更新

  if (position.y < 0 || position.y > ofGetHeight()) {
    position.y = ofGetHeight(); // ウィンドウ外へ飛び出たら下端へ固定する
  }
}

void Fireworks::draw() {
  if (velocity.y <= 0) {
    // 爆発して欲しい
    ofDrawBitmapString("Boooomb!!!!!!", ofGetWidth() * 0.5,
                       ofGetHeight() * 0.5);
  }
  ofDrawBitmapString("⊿t : " + ofToString(dt), 20, 20);
  ofDrawBitmapString("accelaration :\t" + ofToString(a), 20, 80);
  ofDrawBitmapString("velocity :\t" + ofToString(velocity.y), 20, 40);
  ofDrawBitmapString("position : \t" + ofToString(position.y), 20, 60);
  ofSetColor(color);
  ofFill();
  ofCircle(position.x, position.y, 10.0);
}
