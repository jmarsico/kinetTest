#pragma once

#include "ofMain.h"
#include "kinet.h"
#include "ofxGui.h"
#define CK_HOST "128.2.103.177"

class testApp : public ofBaseApp{

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
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);


    PowerSupply* supply;
    size_t numFixtures;
    vector<FixtureRGB> fixtures;


    ofxPanel gui;

    ofxIntSlider r;
    ofxIntSlider g;
    ofxIntSlider b;
    
    ofColor tempCol;

    
        
		
};
