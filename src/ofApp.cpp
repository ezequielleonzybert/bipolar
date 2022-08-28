#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    // planets.push_back(Planet(0, {w / 2, h / 2, 0}, -.1));
    particles.push_back(Particle(0, {200, 190, 0}, 5, 0.001, 0));
    particles.push_back(Particle(0, {400, 210, 0}, 5, 0.001, 0));
}

//--------------------------------------------------------------
void ofApp::update()
{
    for (Particle &p : particles)
    {
        p.update(particles);
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    for (Particle p : particles)
    {
        p.draw();
    }
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
