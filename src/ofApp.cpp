#include "ofApp.h"
#include "utils.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetBackgroundAuto(false);

    for (int i = 0; i < 100; i++)
    {
        particles.push_back(Particle(0, {ofRandom(h / 3 + w / 4, h * 2 / 3 + w / 4), ofRandom(h / 3, h * 2 / 3), ofRandom(-100, 100)}, .1, 0));
    }
    planets.push_back(Planet(0, {w / 2, h / 2, 0}, .001));

    // ofEnableLighting();
    // light.setDirectional();
    // light.setDiffuseColor(ofColor::white);
    // light.setSpecularColor(ofColor::white);
    // light.setOrientation({180, 0, 0});
    // light.enable();

    fbo.allocate(w, h, GL_RGBA, 8);
}

//--------------------------------------------------------------
void ofApp::update()
{
    planets[0].position.x = cos(ofGetElapsedTimef() * .5) * w / 4 + w / 2;
    planets[0].position.y = sin(ofGetElapsedTimef() * .5) * h / 4 + h / 2;
    for (Particle &p : particles)
    {
        p.update(particles, planets);
    }

    showFps();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    // camera.begin();

    fbo.begin();

    fbo.clear();
    fbo.clearDepthBuffer(1.f);
    ofEnableDepthTest();
    ofSetColor(255);
    for (Particle p : particles)
    {
        p.draw();
    }
    // for (Planet p : planets)
    // {
    //     p.draw();
    // }
    ofDisableDepthTest();
    fbo.end();

    ofSetColor(ofColor::black, 10);
    ofDrawRectangle(0, 0, w, h);

    ofSetColor(ofColor::white);
    fbo.draw(0, 0);
    // camera.end();
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
    planets[0].position = {x, h - y, 0};
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
