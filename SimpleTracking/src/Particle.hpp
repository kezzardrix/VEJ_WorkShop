//
//  Particle.hpp
//  SimpleParticle
//
//  Created by kezzardrix2 on 2016/10/03.
//
//

#ifndef Particle_hpp
#define Particle_hpp

#include "ofMain.h"
#include "ofxOpenCv.h"

//setCenter関数に渡されたx,y座標が、前のフレームより一定以上動いていたら
//パーティクルを発生させるクラス
//ofxContourFinderの説明を簡略化するために、
//contourFinderを渡したら使えるようにもなっている

class Particle{
public:
    
    void setup();
    void setCenter(float x, float y);
    void setFromContourFinder(ofxCvContourFinder &contourFinder);
    void update();
    void draw();
    
private:
    
    ofVbo vbo;
    
    //配列を扱うためのSTL。詳しくはググろう
    vector<ofVec2f>verts;
    vector<ofVec2f>vecs;
    vector<ofFloatColor>colors;
    
    static const int NUM_PARTICLES = 1000;
    int counter;
    
    ofPoint prePos;
    
    float thresh;
    
};

#endif /* Particle_hpp */
