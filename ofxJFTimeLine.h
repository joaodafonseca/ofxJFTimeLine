//
//  ofxJFTimeLine.h
//  Intel_Swarm
//
//  Created by João Fonseca on 03/08/15.
//
//

#pragma once
#include "ofMain.h"

#define TIME_MILLIS 0
#define TIME_MILLIS_FRAMERATE 1

class ofxJFTimeLine {
    
public:
    
    long currentMillis;
    long oldMillis;
    int timeMode;
    float frameNum;
    float frameRate;
    
    
    ofxJFTimeLine(){
        
        currentMillis=0;
        oldMillis=ofGetElapsedTimeMillis();
        timeMode = TIME_MILLIS;
    
    }

    
    ofxJFTimeLine(float _frameRate){
        
        currentMillis=0;
        oldMillis=ofGetElapsedTimeMillis();
        timeMode = TIME_MILLIS_FRAMERATE;
        frameRate=_frameRate;
        frameNum=0;
        
    }

    
    
    void setTimeMode(int _tmeMode){
    
        timeMode = _tmeMode;
    
    }
    
    
    void update(){
    
        if((timeMode=TIME_MILLIS)){
        currentMillis+=ABS(ofGetElapsedTimeMillis()-oldMillis);
        oldMillis=ofGetElapsedTimeMillis();
        
        }else if((timeMode=TIME_MILLIS_FRAMERATE)){
        
            currentMillis=float(frameNum/frameRate)*1000;
            //cout<<ofGetFrameNum()/frameRate<<endl;
        }
        
        frameNum++;
    }
    
    
    bool bangAtMillis(long _millis){
        
        if(currentMillis==_millis){
        
            return true;
            
        }else return false;
    
    
    }
   
    
    long getMillis(){
        
        
        return currentMillis;
    }

    
    
    float getSeconds(){
        
        return currentMillis/1000.0f;
    }

    
    int getFrameNum(){
        
        return frameNum;
    }

    
    void reset(){
        
        currentMillis=0;
        oldMillis=ofGetElapsedTimeMillis();

    }
    
};