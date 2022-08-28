#include "ofApp.h"
#include "utils.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetBackgroundAuto(false);

    planets.push_back(Planet(0, {w / 2, h / 2, 0}, .0001));
    planets.push_back(Planet(1, {w / 2, h / 2, 0}, .0001));

    for (int i = 0; i < 100; i++)
    {
        particles.push_back(Particle(0, {w / 2, h / 2, 0}, .001, 0, palette));
        particles.push_back(Particle(1, {w / 2, h / 2, 0}, .001, 1, palette));
    }

    ofEnableLighting();
    light.setDirectional();
    light.setDiffuseColor(ofColor::white);
    light.setSpecularColor(ofColor::white);
    light.setOrientation({180, 0, 0});
    light.enable();

    fbo.allocate(w, h, GL_RGBA, 8);
}

//--------------------------------------------------------------
void ofApp::update()
{
    if (ofGetFrameNum() > 30 && !trigger)
    {
        planets[0].position.x = cos(ofGetElapsedTimef() * .1) * w / 4 + w / 2;
        planets[0].position.y = sin(ofGetElapsedTimef() * .1) * h / 4 + h / 2;
        planets[1].position.x = cos(ofGetElapsedTimef() * .1 + PI) * w / 4 + w / 2;
        planets[1].position.y = sin(ofGetElapsedTimef() * .1 + PI) * h / 4 + h / 2;
    }
    else
    {
        planets[0].position = {w / 2, h / 2, 0};
        planets[1].position = {w / 2, h / 2, 0};
    }

    for (Particle &p : particles)
    {
        p.update(particles, planets);
    }

    showFps();
    vr.record("/home/ezequiel/Videos/bipolar", 18, 3);
}

//--------------------------------------------------------------
void ofApp::draw()
{
    fbo.begin();
    fbo.clear();
    fbo.clearDepthBuffer(1.f);
    ofEnableDepthTest();
    ofEnableSmoothing();
    for (Particle p : particles)
    {
        p.draw();
    }
    ofDisableDepthTest();
    ofDisableSmoothing();
    fbo.end();

    ofSetColor(ofColor::black, 10);
    ofDrawRectangle(0, 0, w, h);

    ofSetColor(ofColor::white);
    fbo.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::exit()
{
    vr.stopRecording();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == ' ')
    {
        trigger = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
