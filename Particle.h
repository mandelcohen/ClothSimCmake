#ifndef CLOTHSIMCMAKE_PARTICLE_H
#define CLOTHSIMCMAKE_PARTICLE_H

#include <glm/vec2.hpp>

struct Particle {
    glm::vec2 position;
    glm::vec2 previousPosition;
    glm::vec2 acceleration;
    float inverseMass;
};


#endif //CLOTHSIMCMAKE_PARTICLE_H
