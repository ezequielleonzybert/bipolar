#pragma once

#include "ofMain.h"
#include "planet.h"
#include "particle.h"
#include "videoRecorder.h"

class ofApp : public ofBaseApp
{

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	void exit();

	float w = ofGetWidth();
	float h = ofGetHeight();

	vector<Planet> planets;
	vector<Particle> particles;
	ofEasyCam camera;
	ofLight light;
	ofFbo fbo;

	ofColor palette[3] = {
		ofColor::white,
		ofColor::red,
		ofColor::blue};

	bool trigger;

	VideoRecorder vr;
};
