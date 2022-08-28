#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"
#include "planet.h"

class Particle
{
public:
    glm::vec3 position, previous_position, acceleration, velocity;
    float attraction;
    int type;
    int planet_index;
    ofColor color;

    Particle(int type, glm::vec3 position, float attraction, int planet_index, ofColor palette[])
    {
        this->type = type;
        this->position = this->previous_position = position;
        this->attraction = attraction;
        this->planet_index = planet_index;
        float ran = ofRandom(0, TWO_PI);
        this->velocity = {ofRandom(cos(ran) * -2, cos(ran) * 2),
                          ofRandom(sin(ran) * -2, sin(ran) * 2),
                          ofRandom(sin(ran)*-2, sin(ran)*2)};
        this->position += velocity;

        int r;
        if (type)
        {
            r = (int)ofRandom(0, 2);
            color = palette[r];
        }
        else
        {
            r = (int)ofRandom(2, 4) % 3;
            color = palette[r];
        }
    };
    void update(vector<Particle> &particles, vector<Planet> planets)
    {
        glm::vec3 acceleration_summation;

        float distance_to_planet = MAX(glm::distance(position, planets[planet_index].position), 100);
        glm::vec3 direction_to_planet = glm::normalize(position - planets[planet_index].position);
        acceleration_summation +=
            -(direction_to_planet * distance_to_planet * planets[planet_index].attraction);

        for (Particle &p : particles)
        {
            if (&p != this && p.type == type)
            {
                float distance_to_particle = MAX(glm::distance(position, p.position), 100);
                glm::vec3 direction_to_particle = glm::normalize(position - p.position);
                acceleration_summation +=
                    -(direction_to_particle / distance_to_particle * p.attraction);
            }
        }
        float limit = 1;
        acceleration = acceleration_summation;
        velocity += acceleration;
        velocity.x = ofClamp(velocity.x, -limit, limit);
        velocity.y = ofClamp(velocity.y, -limit, limit);
        velocity.z = ofClamp(velocity.z, -limit, limit);
        previous_position = position;
        position += velocity;
    }
    void draw()
    {
        float distance = glm::distance(position, previous_position);
        glm::vec3 direction = glm::normalize(position - previous_position);

        ofNoFill();
        ofSetColor(color);
        for (int i = 0; i < distance * 1.f; i++)
        {
            ofDrawSphere(previous_position + direction * i / 1.f, 3);
        }
    }
};

#endif