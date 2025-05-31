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
    gui.add(gEnableAutoClear.set("Enable Auto Clear Canvas", true));
    gui.add(gEnableRotation.set("Enable Canvas Rotation", false));
    gui.add(gDisableInteraction.set("Disable Interaction", true));
    gui.add(gDistanceThres.set("Distance Threshold", 150, 5, 1000));
    gui.add(gLineW.set("Line Width", 2, 1, 4));
    gui.add(gNoiseVals.set("Noise Multipliers", glm::vec3(0.002), glm::vec3(0.00001, 0.00001, 0.00001), glm::vec3(20)));
    gui.add(gEnableDepthTest.set("Enable Depth Test", true));
    gui.add(gEnableLight.set("Enable Lighting", true));
    gui.add(gShowLight.set("Show Light", true));
    gui.add(gLightPos.set("Object Light Position", glm::vec3(0), glm::vec3(-3000), glm::vec3(3000)));
    gui.add(gLightAreaPos.set("Area Light Position", glm::vec3(0), glm::vec3(-5000), glm::vec3(5000)));
    gui.add(gAnimationSpeed.set("Animation Speed", 0.2, 0.01, 3));
    gui.add(gRotationSpeed.set("Rotation Speed", 6, 1, 30));
    gui.add(gPathColor.set("Path Color", ofColor(255), ofColor(0), ofColor(255)));
    gui.add(gConnectionColor.set("Connection Color", ofColor(255), ofColor(0), ofColor(255)));
    gui.setPosition(0, 0);
    gui.loadFromFile(xmlSettingsPath);

    // Set background color
    ofBackground(0);
    count = 0;

    lightArea.setAreaLight(ofGetWidth(), ofGetWidth());
    lightArea.setSpecularColor(ofFloatColor(1.0, 1.0, 1.0));
    lightArea.setDiffuseColor(ofFloatColor(0.8, 0.8, 0.8));
    lightArea.setAmbientColor(ofFloatColor(0.2, 0.2, 0.2));
    lightArea.enable();
    rad = 4;
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
void ofApp::clearCanvas(){
    meshConnection.clear();
    meshPrimary.clear();
    points.clear();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'f')
        ofToggleFullscreen();
    else if(key == 'c')
        clearCanvas();
    else if(key == 'd')
        isDebug ^= true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if(!gDisableInteraction)
        stroke(x, y, 0);
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