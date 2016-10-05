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

class Particle{
public:
    
    void setup();
    void setCenter(float x, float y);
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
