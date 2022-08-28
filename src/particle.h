#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"
#include "planet.h"

class Particle
{
public:
    glm::vec3 position, acceleration, velocity;
    float radius;
    float attraction;
    int type;
    int planet_index;

    Particle(int type, glm::vec3 position, float radius, float atraction, int planet_index)
    {
        this->type = type;
        this->position = position;
        this->radius = radius;
        this->attraction = attraction;
        this->planet_index = planet_index;
    };
    void update(vector<Particle> &particles)
    {
        glm::vec3 acceleration_summation;
        for (Particle &p : particles)
        {
            if (&p != this)
            {
                float distance_to_particle = glm::distance(position, p.position);
                glm::vec3 direction_to_particle = position - p.position;
                acceleration_summation +=
                    direction_to_particle / distance_to_particle * p.attraction;
            }
        }
        acceleration = acceleration_summation;
        cout << velocity << " " << ofGetFrameNum() << endl;
        velocity += acceleration;
        position += velocity;
    }
    void draw()
    {
        ofDrawCircle(position, radius);
    }
};

#endif