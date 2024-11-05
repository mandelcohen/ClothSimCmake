#ifndef CLOTHSIMCMAKE_PARTICLE_H
#define CLOTHSIMCMAKE_PARTICLE_H

#include <glm/vec2.hpp>

struct Particle {
    glm::vec2 position;
    glm::vec2 previousPosition;
    glm::vec2 velocity;
    glm::vec2 acceleration;
    float inverseMass;

    Particle(const glm::vec2& startPosition, float mass)
            : position(startPosition),
              previousPosition(startPosition),
              velocity(glm::vec2(0.0f, 0.0f)),
              acceleration(glm::vec2(0.0f, 0.0f)),
              inverseMass(mass > 0.0f ? 1.0f / mass : 0.0f) {}
};


#endif //CLOTHSIMCMAKE_PARTICLE_H
