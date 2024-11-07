#ifndef CLOTHSIMCMAKE_PARTICLE_H
#define CLOTHSIMCMAKE_PARTICLE_H

#include <glm/glm.hpp>

struct Particle {
    glm::vec2 position;
    glm::vec2 previousPosition;
    glm::vec2 velocity;
    glm::vec2 acceleration;
    float mass;
    bool isFixed;

    Particle(const glm::vec2& startPosition);
};


#endif //CLOTHSIMCMAKE_PARTICLE_H
