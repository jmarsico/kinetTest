#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(255);
    
    
    gui.setup();
    gui.add(r.setup("red", 255, 0, 255));
    gui.add(g.setup("green", 255, 0, 255));
    gui.add(b.setup("blue", 255, 0, 255));
    gui.setPosition(10, 10);
    
    numFixtures = 2;
    
    //construct new supply
    supply = new PowerSupply(CK_HOST);
    
    //create fixtures (pay attention to fixture ID)
    for(size_t i = 0; i < numFixtures; i++)
    {
        
        FixtureRGB fixture = *new FixtureRGB(0);
        fixture.setAddress(i*3);
        fixtures.push_back(fixture);
    }
    
    ofLog() << "number of fixtures at setup: " << fixtures.size();
    
    //attach fixtures to supply
    for(size_t i = 0; i < numFixtures; i++)
    {
        supply->addFixture(&fixtures[i]);
    }
    
    //supply->connect(CK_HOST);
}

//--------------------------------------------------------------
void testApp::update(){
    //tempCol = color;
    uint8_t _r = r;
    uint8_t _g = g;
    uint8_t _b = b;
    
    
    for(int i  = 0; i < fixtures.size(); i++)
    {
        //fixtures[i].set_rgb(_r, _g, _b);
        fixtures[i].set_red(_r);
        fixtures[i].set_green(_g);
        fixtures[i].set_blue(_b);
        
        ofLog() << i <<  ": red: " << (int)fixtures[i].get_red();
        ofLog() << i <<  ": green: " << (int)fixtures[i].get_green();
        ofLog() << i <<  ": blue: " << (int)fixtures[i].get_blue();
        
    }
    
    supply->go();
    

}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(r, g, b);
    ofRect(0,0, ofGetWidth(), ofGetHeight());
    gui.draw();
    
    int _r = r;
    int _g = g;
    int _b = b;

    ofSetColor(0);
    //report
    stringstream info;
    info
    << "channel 1" << endl
    << "red: " << _r << endl
    << "green: " << _g << endl
    << "blue: " << _b << endl
    << "Number of Fixtures: "  << fixtures.size() << endl;
    ofDrawBitmapString(info.str(), 10, 200);
    
    
    

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
