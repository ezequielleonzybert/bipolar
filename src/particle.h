#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"
#include "planet.h"

class Particle
{
public:
    glm::vec3 position, acceleration, velocity;
    float attraction;
    int type;
    int planet_index;

    Particle(int type, glm::vec3 position, float attraction, int planet_index)
    {
        this->type = type;
        this->position = position;
        this->attraction = attraction;
        this->planet_index = planet_index;
    };
    void update(vector<Particle> &particles, vector<Planet> planets)
    {
        glm::vec3 acceleration_summation;

        float distance_to_planet = MAX(glm::distance(position, planets[planet_index].position), 100);
        glm::vec3 direction_to_planet = glm::normalize(position - planets[planet_index].position);
        acceleration_summation +=
            -(direction_to_planet / distance_to_planet * planets[planet_index].attraction);

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
        acceleration = acceleration_summation;
        velocity += acceleration;
        position += velocity;
    }
    void draw()
    {
        ofSetColor(ofColor::white);
        ofDrawSphere(position, 5);
    }
};

#endif