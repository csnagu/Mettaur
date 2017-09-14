#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  // 輪郭を滑らかにする
    ofEnableSmoothing();

  // フレームレートを設定する
    ofSetFrameRate(30);

  // ボールの初期Ｘ座標Ｙ座標
  // xPos = ofGetWindowWidth() * 0.5;
  // yPos = ofGetWindowHeight() * 0.5;
}

//--------------------------------------------------------------
void ofApp::update() {
  // xPos += ( mouseX - xPos ) * 0.1;
  // yPos += ( mouseY - yPos ) * 0.1;
  // theBall.x += ( mouseX - theBall.x);
  // theBall.y += ( mouseY - theBall.y);
    theBall.moveTo(mouseX, mouseY);
  // ボールのxとｙの距離をマウスの位置に設定する
  // ここでは，x,yの変数を調整する
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackgroundGradient(ofColor::gray, ofColor(30, 10, 30), OF_GRADIENT_CIRCULAR);

    theBall.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
    theBall.x = ofRandom(ofGetWindowWidth());
    theBall.y = ofRandom(ofGetWindowHeight());
    theBall.changeColor();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
