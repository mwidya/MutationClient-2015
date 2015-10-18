#include "ofApp.h"
#include "constants.h"

#define TEST_ON false

void ofApp::writeSettings(){
    
    for (int i = 0; i<10; i++) {
        settings.setValue("settings:width", surfacesLong[i]);
        settings.setValue("settings:height", surfacesShort[i]);
        settings.setValue("settings:syphon_name", "f"+ofToString(i));
        settings.setValue("settings:markerId", markerIds[i]);
        settings.setValue("settings:markerX", markerXs[i]);
        settings.setValue("settings:markerY", markerYs[i]);
        settings.setValue("settings:markerWidth", markerWidths[i]);
        settings.setValue("settings:markerHeight", markerHeights[i]);
        settings.setValue("settings:oscPort", oscPorts[i]);
        settings.setValue("settings:orientation", orientations[i]);
        
        settings.saveFile("settings"+ofToString(i)+".xml"); //puts settings.xml file in the bin/data folder
        
    }
    
}

void ofApp::readSettings(){
    for (int i = 0; i<10; i++) {
        bool loaded = settings.loadFile("../../../../settings"+ofToString(i)+".xml");
        width = settings.getValue("settings:width", 100.0);
        height = settings.getValue("settings:height", 100.0);
        syphonName = settings.getValue("settings:syphon_name", "...");
        markerId = settings.getValue("settings:markerId", 0);
        markerX = settings.getValue("settings:markerX", 0);
        markerY = settings.getValue("settings:markerY", 0);
        markerWidth = settings.getValue("settings:markerWidth", 0);
        markerHeight = settings.getValue("settings:markerHeight", 0);
        oscPort = settings.getValue("settings:oscPort", 6999);
        orientation = settings.getValue("settings:orientation", -1);
        if (loaded) {
            break;
        }
    }
    
}

void ofApp::setLightOri(ofLight *light, ofVec3f rot){
    ofVec3f xax(1, 0, 0);
    ofVec3f yax(0, 1, 0);
    ofVec3f zax(0, 0, 1);
    ofQuaternion q;
    q.makeRotate(rot.x, xax, rot.y, yax, rot.z, zax);
    light->setOrientation(q);
}

//--------------------------------------------------------------
void ofApp::setup(){
    
    if (TEST_ON) {
        tcpServerIp = "localhost";
        tcpConnected = tcpClient.setup(tcpServerIp, 12333);
        tcpClient.setMessageDelimiter("\n");
    }
    
    
    ofSetDataPathRoot("../Resources/data/");
    
    if (TEST_ON) {
        markerOn = false;
        infoOn = false;
    }else
    {
        markerOn = false;
        infoOn = true;
    }
    
    writeSettings();
    readSettings();
    
    ofSetWindowShape(width, height);
    
    syphonServer.setName(syphonName);
    
    ofSetVerticalSync(true);
    
    receiver.setup(oscPort);
    
    string path = "images/marker_" + ofToString(markerId) + ".png";
    markerImage.loadImage(path);
    
    ofSetGlobalAmbientColor(ofFloatColor(0.0f));
    
    ofSetSmoothLighting(true);
    
    material.setShininess(128);
    material.setSpecularColor(ofFloatColor(1.0f, 1.0f, 1.0f));
    
    
    
    plane.set(width, height);
    plane.setColumns(200);
    
    
    for (int i = 0; i < 8; i++) {
        mutLight *light = (mutLight*)new ofLight;
        light->setSpotlight();
        switch (orientation) {
            case FLOOR:
                //
                lightFloor_orientationX = -90;
                lightFloor_orientationY = 0;
                lightFloor_orientationZ = 0;
                break;
            case EAST:
                lightEast_orientationX = 0;
                lightEast_orientationY = -90;
                lightEast_orientationZ = 0;
                break;
            case WEST:
                lightWest_orientationX = 0;
                lightWest_orientationY = 90;
                lightWest_orientationZ = 0;
                break;
                
            default:
                break;
        }
        
        light->mutLightID = i;
        light->active = false;
        lights.push_back(light);
    }
}

void ofApp::update(){
    
    while(receiver.hasWaitingMessages()){
        
        ofxOscMessage m;
        receiver.getNextMessage(&m);
        
        string s = syphonName+"/position";
        if(m.getAddress() == s){
            planePosition = ofVec3f(m.getArgAsFloat(0), m.getArgAsFloat(1), m.getArgAsFloat(2));
            plane.setPosition(planePosition);
        }
        
        if(m.getAddress() == "/light/position"){
            
            for (int i = 0; i<lights.size(); i++) {
                mutLight *l = lights[i];
                if (l->mutLightID == m.getArgAsInt64(8)) {
                    switch (orientation) {
                        case FLOOR:
                            lightPosition = ofVec3f(planePosition.x-m.getArgAsFloat(2), -(m.getArgAsFloat(0)-planePosition.x)+planePosition.y, -(m.getArgAsFloat(1)-planePosition.y));
                            lightOrientation = ofVec3f(lightFloor_orientationX + m.getArgAsFloat(10), lightFloor_orientationY + m.getArgAsFloat(11), lightFloor_orientationZ + m.getArgAsFloat(12));
                            break;
                        case EAST:
                            lightPosition = ofVec3f(planePosition.x-m.getArgAsFloat(2), -(m.getArgAsFloat(1))+planePosition.y*2, m.getArgAsFloat(0)-planePosition.x);
                            lightOrientation = ofVec3f(lightEast_orientationX + m.getArgAsFloat(10), lightEast_orientationY + m.getArgAsFloat(11), lightEast_orientationZ + m.getArgAsFloat(12));
                            break;
                        case WEST:
                            if (syphonName=="f3") {
                                lightPosition = ofVec3f(planePosition.x+m.getArgAsFloat(2)-planePosition.z, -(m.getArgAsFloat(1))+planePosition.y*2, -(m.getArgAsFloat(0)-planePosition.x));
                            }else{
                                lightPosition = ofVec3f(planePosition.x+m.getArgAsFloat(2), -(m.getArgAsFloat(1))+planePosition.y*2, -(m.getArgAsFloat(0)-planePosition.x));
                            }
                            lightOrientation = ofVec3f(lightWest_orientationX + m.getArgAsFloat(10), lightWest_orientationY + m.getArgAsFloat(11), lightWest_orientationZ + m.getArgAsFloat(12));
                            break;
                            
                        default:
                            break;
                    }
                    
                    l->setDiffuseColor(ofFloatColor(m.getArgAsFloat(3), m.getArgAsFloat(4), m.getArgAsFloat(5)));
                    l->setSpecularColor(ofFloatColor(1));
                    l->setSpotlightCutOff(m.getArgAsFloat(6));
                    l->setSpotConcentration(m.getArgAsFloat(7));
                    l->setPosition(lightPosition);
                    setLightOri(l, lightOrientation);
                    l->active = m.getArgAsInt32(9);
                    
                }
            }
        }
        
        
        for (int i = 0; i<lights.size(); i++) {
            mutLight *lightPtr = lights[i];
            if(m.getAddress() == "/light"+ofToString(i)+"/position"){
                
                
            }
        }
        
        if(m.getAddress() == "/marker/on"){
            markerOn = (bool)(m.getArgAsInt32(0));
            cout << "markerOn = " << markerOn << endl;
        }
        if(m.getAddress() == "/info/on"){
            infoOn = (bool)(m.getArgAsInt32(0));
            cout << "infoOn = " << infoOn << endl;
        }
    }
    
    if (TEST_ON) {
        if(tcpClient.isConnected())
        {
            
        }else
        {
            //if we are not connected lets try and reconnect every 5 seconds
            deltaTime = ofGetElapsedTimeMillis() - connectTime;
            if( deltaTime > 3000 ){
                ofLog(OF_LOG_WARNING, "trying to connect to tcp");
                tcpConnected = tcpClient.setup(tcpServerIp, 12333);
                connectTime = ofGetElapsedTimeMillis();
            }
        }
    }
    
}

void ofApp::draw(){
    
    ofClear(0);
    
    ofPushMatrix();
    
    ofEnableDepthTest();
    ofEnableLighting();
    material.begin();
    
    if (syphonName=="f3") {
        ofTranslate(width*.5f-planePosition.x, height*.5f-planePosition.y, -planePosition.z);
    }else{
        ofTranslate(width*.5f-planePosition.x, height*.5f-planePosition.y);
        
    }
    
    for (int i = 0; i<lights.size(); i++) {
        if (lights[i]->active) {
            lights[i]->enable();
            //            lights[i]->draw();
        }
    }
    plane.draw();
    
    ofPopMatrix();
    
    material.end();
    ofDisableLighting();
    ofDisableDepthTest();
    
    
    if (markerOn) {
        ofSetColor(255, 255, 255);
        float frame = 80*factor;
        ofRect(markerX-(frame/2), markerY-(frame/2), markerWidth+frame, markerHeight+frame);
        markerImage.draw(markerX, markerY, markerWidth, markerHeight);
    }
    
    
    
    syphonServer.publishScreen();
    
    if (infoOn) {
        int linePitch = 20;
        
        for (int i = 0; i<lights.size(); i++) {
            ofDrawBitmapString("ID: "+ofToString(lights[i]->mutLightID)+
                               " | RGB: " + ofToString(lights[i]->getDiffuseColor().r)+", "+ofToString(lights[i]->getDiffuseColor().g)+", "+ofToString(lights[i]->getDiffuseColor().b) +
                               " | Pos: " + ofToString(lights[i]->getPosition().x)+", "+ofToString(lights[i]->getPosition().y)+", "+ofToString(lights[i]->getPosition().z) +
                               " | Orientation: " + ofToString(lights[i]->getOrientationEuler().x)+", "+ofToString(lights[i]->getOrientationEuler().y)+", "+ofToString(lights[i]->getOrientationEuler().z),  10, height-(linePitch*(5+i)));
        }
        ofDrawBitmapString("Plane Pos: " + ofToString(plane.getPosition().x)+", "+ofToString(plane.getPosition().y)+", "+ofToString(plane.getPosition().z),  10, height-(linePitch*4));
        ofDrawBitmapString("Syphon Server: " + syphonName + " | Orientation: " + ofToString(orientation) +" | OSC Port: "+ofToString(oscPort), 10, height-(linePitch*3));
        
        ofDrawBitmapString("fps: " + ofToString(ofGetFrameRate()), 10, height-(linePitch*2));
        if (TEST_ON) {
            if (tcpClient.isConnected())
            {
                ofDrawBitmapString("TCP is connected to IP " + ofToString(tcpServerIp) + " on port " + ofToString(PORT) , 10, height-linePitch);
            }
            else
            {
                ofDrawBitmapString("TCP is NOT connected to IP " + ofToString(tcpServerIp) + " on port " + ofToString(PORT) , 10, height-linePitch);
            }
        }
    }
}

void ofApp::mousePressed(int x, int y, int button){
    if (TEST_ON) {
        ofVec2f pc = ofVec2f(x, y);
        Json::Value root;
        root["x"] = pc.x / width;
        root["y"] = pc.y / height;
        root["id"] = markerId;
        root["event"] = "press";
        //    ofLog(OF_LOG_WARNING, "hit " + ofToString(markerId) + " " + ofToString(pc));
        Json::FastWriter jwrite;
        ofLog(OF_LOG_NOTICE, "pc.x = " + ofToString(pc.x));
        ofLog(OF_LOG_NOTICE, "pc.y = " + ofToString(pc.y));
        ofLog(OF_LOG_NOTICE, "width = " + ofToString(pc.x / width));
        ofLog(OF_LOG_NOTICE, "height = " + ofToString(pc.y / height));
        ofLog(OF_LOG_WARNING, jwrite.write(root));
        tcpClient.sendRaw(jwrite.write(root));
    }
}

