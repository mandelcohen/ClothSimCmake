#include "Cloth.h"
#include "Particle.h"

Cloth::Cloth(int clothWidth, int clothHeight, float particleSpacing)
        : width(clothWidth),
          height(clothHeight),
          spacing(particleSpacing) {
    initializeParticles();
    initializeConstraints();
}

void Cloth::initializeParticles() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            glm::vec2 position = glm::vec2(x * spacing, y * spacing);
            particles.push_back(Particle(position));
        }
    }
}

void Cloth::initializeConstraints() {
    // Structural Constraints
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int index = y * width + x;

            // Horizontal structural constraint
            if (x < width - 1) {
                constraints.push_back(Constraint(&particles[index], &particles[index + 1], spacing));
            }

            // Vertical structural constraint
            if (y < height - 1) {
                constraints.push_back(Constraint(&particles[index], &particles[index + width], spacing));
            }

            // Diagonal (shear) constraints and bending constraints can be added similarly.
        }
    }

    // Fix the top row of particles
    for (int x = 0; x < width; ++x) {
        particles[x].isFixed = true;
    }
}



