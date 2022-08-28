#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    // planets.push_back(Planet(0, {w / 2, h / 2, 0}, -.1));
    for (int i = 0; i < 5; i++)
    {
        particles.push_back(Particle(0, {ofRandom(0, w / 2), ofRandom(0, h), ofRandom(0, 100)}, 10, 0));
    }
    planets.push_back(Planet(0, {0, 0, 0}, 50));

    ofEnableDepthTest();
    ofEnableLighting();
    light.setDirectional();
    light.setDiffuseColor(ofColor::white);
    light.setSpecularColor(ofColor::white);
    light.setOrientation({180, 0, 0});
    light.enable();
}

//--------------------------------------------------------------
void ofApp::update()
{
    for (Particle &p : particles)
    {
        p.update(particles, planets);
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    camera.begin();
    for (Particle p : particles)
    {
        p.draw();
    }
    for (Planet p : planets)
    {
        p.draw();
    }
    camera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
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
