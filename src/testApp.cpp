#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    
    
    gui.setup();
    gui.add(color.setup("color",ofColor(100,100,140),ofColor(0,0),ofColor(255,255)));
    
    numFixtures = 2;
    
    //construct new supply
    supply = new PowerSupply(CK_HOST);
    
    //create fixtures (pay attention to fixture ID)
    for(size_t i = 1; i < numFixtures+1; i++)
    {
        
        ofLog() << "enters for loop" ;
        FixtureRGB *fixture = new FixtureRGB(i);
        fixtures.push_back(*fixture);
    }
    
    ofLog() << "number of fixtures at setup: " << fixtures.size();
    
    //attach fixtures to supply
    for(size_t i = 0; i < numFixtures; i++)
    {
        supply->addFixture(&fixtures[i]);
    }    
}

//--------------------------------------------------------------
void testApp::update(){
    ofColor tempCol = color;
    
    for(int i  = 1; i< fixtures.size()+1; i++)
    {
        fixtures[i].set_rgb(tempCol.r, tempCol.g, tempCol.b);
        
    }
    
    supply->go();
    

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(255);
    ofSetColor(0);

    //report
    info
    << "red: " << fixtures.at(0).get_red() << endl
    << "green: " << fixtures.at(0).get_green() << endl
    << "blue: " << fixtures.at(0).get_blue() << endl
    << "Number of Fixtures: "  << fixtures.size() << endl;
    ofDrawBitmapString(info.str(), 10, 200);
    
    
    gui.draw();

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
