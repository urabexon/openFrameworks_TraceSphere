#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofLogToConsole();
    ofEnableAntiAliasing();
    ofEnableSmoothing();
    ofSetSmoothLighting(true);

    // do not forget to replace the following path your own ttf/otf font file path
    ofxGuiSetFont( "../../../../../../assets/DIN.otf", 8 );
    ofxGuiSetDefaultWidth( 300 );
    ofxGuiSetFillColor(ofColor(255,204,0,200));

    string xmlSettingsPath = "generativeDrawing_settings.xml";
    gui.setup( "Drawing Parameters", xmlSettingsPath );
    gui.add(gDrawingMode.set("Drawing Mode", 0, 0, 4)); // Number of Tentacles
    gui.add(gEnableCameraTracking.set("Enable Target Tracking", false));
    gui.add(gCameraTrackingOff.set("Camera Target Offset", glm::vec3(0,0,260), glm::vec3(-1000), glm::vec3(1000)));
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetLineWidth(gLineW);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    ofLog() << meshPrimary.getCentroid();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    // points.push_back(glm::vec3(x, y, 0));
    if(!gDisableInteraction) {
        pMx = x;
        pMy = y;
    }
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