//
//  Particle.cpp
//  SimpleParticle
//
//  Created by kezzardrix2 on 2016/10/03.
//
//

#include "Particle.hpp"

void Particle::setup(){
    
    for(int i = 0; i < NUM_PARTICLES; i++){
        verts.push_back(ofVec2f(0, 0));
        vecs.push_back(ofVec2f(0, 0));
        
        ofFloatColor color;
        color.setHsb(0.1, 1.0, 1.0);
        color.a = 0.0;
        colors.push_back(color);
    }
    
    //ofVboはGPUにパーティクルや線やメッシュをまとめて描画させるクラス
    //drawCircleなどで書くより高速な描画が可能

    vbo.setVertexData(&verts[0], NUM_PARTICLES, GL_DYNAMIC_DRAW);
    vbo.setColorData(&colors[0], NUM_PARTICLES, GL_DYNAMIC_DRAW);
    
    counter = 0;
    
    thresh = 1.0;
};

void Particle::setCenter(float x, float y){
    
    //前回の座標と今回の座標でベクトルを作る
    ofVec2f vec = prePos - ofVec2f(x,y);
    
    //十分座標が動いていたら動かす(ベクトルの長さを見る)
    if(vec.length() > thresh){
        
        // 毎回ランダムな数のパーティクルが発生
        int rep = ofRandom(3, 6);
    
        for(int i = 0; i < rep; i++){

            //現在のパーティクルの座標をセット
            verts[counter].set(x, y);
            
            //現在のパーティクルの透明度を1に
            colors[counter].a = 1.0;
            
            //動きの加速度を三角関数でランダムに決める
            float rad = ofRandom(1.0,4.0);
            float theta = ofRandom(-TWO_PI, TWO_PI);
            float x = cos(theta) * rad;
            float y = sin(theta) * rad;
            
            //加速度をセット
            vecs[counter].set(x,y);
            
            //counterを動かして次のパーティクルに
            counter++;
            
            //パーティクルの最大数までいったらcounterを0に
            counter %= NUM_PARTICLES;
        }
    }
    
    //前回の座標を今回の座標に
    prePos.set(x,y);
};

void Particle::update(){
    for(int i = 0; i < NUM_PARTICLES; i++){
        verts[i] += vecs[i]; //加速度を毎フレーム足す
        colors[i].a -= 0.01; //パーティクルを少しずつ透明に
    }
    
    //vboに値をセット
    vbo.updateVertexData(&verts[0], NUM_PARTICLES);
    vbo.updateColorData(&colors[0], NUM_PARTICLES);
    
};
void Particle::draw(){
    
    //ポイントサイズを変更
    glPointSize(8);
    
    //ブレンドモードを加算合成に
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    //ポイント表示で描画
    vbo.draw(GL_POINTS, 0, NUM_PARTICLES);
    
};