#pragma once

#include "ofMain.h"

//ofxOpenCVを読み込む
#include "ofxOpenCv.h"

//Particleを読み込む
#include "Particle.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        ofVideoGrabber grabber;
    
        int w;
        int h;
    
        //映像をcvクラスで使いやすくするためのクラス
        ofxCvColorImage			colorImage;
    
        //cvのグレイスケールクラス
        ofxCvGrayscaleImage 	grayImage;
        ofxCvGrayscaleImage 	grayPreFrameImage;
        ofxCvGrayscaleImage 	diffImage;
    
        // 2値化する閾値
        float threshold;
    
        // 輪郭検出器
        ofxCvContourFinder contourFinder;
    
        // パーティクルクラス
        Particle particle;
};
