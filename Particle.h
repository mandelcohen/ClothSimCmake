#ifndef CLOTHSIMCMAKE_PARTICLE_H
#define CLOTHSIMCMAKE_PARTICLE_H

#pragma once
#include <glm/glm.hpp>

struct Particle {
    glm::vec2 position;
    glm::vec2 previousPosition;
    glm::vec2 velocity;
    glm::vec2 acceleration;
    float inverseMass;
    bool isFixed;

    Particle(const glm::vec2& startPosition);
};


#endif //CLOTHSIMCMAKE_PARTICLE_H
