#ifndef PLANET_H
#define PLANET_H

#include "ofMain.h"

class Planet
{
public:
    int index;
    glm::vec3 position;
    float attraction;

    Planet(int index, glm::vec3 position, float attraction)
    {
        this->index = index;
        this->position = position;
        this->attraction = attraction;
    };
    void update()
    {
        position = {ofGetMouseX(), ofGetMouseY(), 0};
    }
    void draw()
    {
        ofSetColor(ofColor::red);
        ofDrawSphere(position, 10);
    }
};

#endif