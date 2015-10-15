#pragma once

#include "ofMain.h"
#include "ofxSyphonServer.h"
#include "ofxXmlSettings.h"
#include "ofxNetwork.h"
#include "ofxJSONElement.h"
#include "ofxOsc.h"
#include "mutLight.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void writeSettings();
    void readSettings();
    void setLightOri(ofLight *light, ofVec3f rot);
    
    ofVec2f normalizedPointToScreenPoint(ofVec2f);
    void parseJSONString(string str);
    
    ofxXmlSettings settings;
    float width;
    float height;
    
    string syphonName;
    ofxSyphonServer syphonServer;
    
    ofImage markerImage;
    int markerId;
    float markerX;
    float markerY;
    float markerWidth;
    float markerHeight;
    
    ofPlanePrimitive plane;
    ofMaterial material;
    mutLight *lightPtr;
    deque<mutLight*> lights;
    
    int orientation;
    
    ofxOscReceiver receiver;
    
    int oscPort;
    
    ofVec3f planePosition;
    ofVec3f lightPosition;
    ofVec3f lightOrientation;
    
    bool markerOn;
    
    ofxTCPClient tcpClient;
    int connectTime;
    bool tcpConnected;
    string tcpServerIp;
    
    float lightWest_orientationX;
    float lightWest_orientationY;
    float lightWest_orientationZ;
    float lightFloor_orientationX;
    float lightFloor_orientationY;
    float lightFloor_orientationZ;
    float lightEast_orientationX;
    float lightEast_orientationY;
    float lightEast_orientationZ;
    
    
};
