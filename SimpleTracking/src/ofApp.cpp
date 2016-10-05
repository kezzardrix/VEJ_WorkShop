#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    w = 640;
    h = 480;
    
    //webカムの初期化
    grabber.initGrabber(w, h);
    
    //cvクラス群の初期化
    colorImage.allocate(w, h);
    grayImage.allocate(w, h);
    grayPreFrameImage.allocate(w, h);
    diffImage.allocate(w, h);
    
    threshold = 50.0;
    
    particle.setup();
    
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    grabber.update();
    
    // もしwebカムの映像に新しいフレームが入ってきたときだけ処理する
    // webカムの映像のフレームレートがアプリと同じとは限らない
    if(grabber.isFrameNew()){
        
        // webカムのピクセルをcvクラスにコピー
        colorImage.setFromPixels(grabber.getPixels());
        
        // カラー画像をグレースケールに
        grayImage = colorImage;
        
        //前のフレームと現在のフレームの差分を抽出
        diffImage.absDiff(grayImage, grayPreFrameImage);
        
        //閾値で2値化する
        diffImage.threshold(threshold);
        
        //輪郭検出クラスに2値化した画像を渡す。
        //blobと呼ばれる映像の中で塊になっている部分を検出して輪郭を出す
        //引数は、検出する最小領域、最大領域、検出するblobの最大数、結果に穴を含むかどうか
        contourFinder.findContours(diffImage, 1, (w * h) / 3, 10, true);
        
        // 現在のフレームを一時保存
        grayPreFrameImage = grayImage;
    }
    
    //パーティクルクラスに輪郭検出器を渡してパーティクルを発生
    particle.setFromContourFinder(contourFinder);
    particle.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    grabber.draw(0, 0);
    diffImage.draw(640,0);
    contourFinder.draw();
    particle.draw();
    
  

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
