#include "Particle.h"

Particle::Particle(const glm::vec2& startPosition)
        : position(startPosition),
          previousPosition(startPosition),
          velocity(glm::vec2(0.0f, 0.0f)),
          acceleration(glm::vec2(0.0f, 0.0f)),
          inverseMass(1.0f),
          isFixed(false) {}

