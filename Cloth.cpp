#include "Cloth.h"
#include "Particle.h"
#include <iostream>

Cloth::Cloth(int clothWidth, int clothHeight, float particleSpacing, float damping)
        : width(clothWidth),
          height(clothHeight),
          spacing(particleSpacing),
          dampingFactor(damping){
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

            // Horizontal
            if (x < width - 1) {
                constraints.push_back(Constraint(&particles[index], &particles[index + 1], spacing));
            }

            // Vertical
            if (y < height - 1) {
                constraints.push_back(Constraint(&particles[index], &particles[index + width], spacing));
            }

            // Shear?
        }
    }

    /*
    // Pin top row
    for (int x = 0; x < width; ++x) {
        particles[x].isFixed = true;
    }
     */
}

void Cloth::applyForces(float deltaTime) {
    const glm::vec2 gravity(0.0f, 98.0f); // Gravity pointing down
    for (auto& particle : particles) {
        if (!particle.isFixed) {
            particle.acceleration += gravity * deltaTime;
        }
    }
}

void Cloth::integrateMotion(float deltaTime) {
    for (auto& particle : particles) {
        if (!particle.isFixed) {
            // Verlet integration formula
            glm::vec2 tempPosition = particle.position;
            particle.position += (particle.position - particle.previousPosition) * dampingFactor
                                 + particle.acceleration * deltaTime * deltaTime;
            particle.previousPosition = tempPosition;

            // Reset acceleration after applying it
            particle.acceleration = glm::vec2(0.0f);
        }
    }
}

void Cloth::enforceConstraints(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        for (auto& constraint : constraints) {
            Particle* p1 = constraint.p1;
            Particle* p2 = constraint.p2;

            // Calculate the vector between the two particles
            glm::vec2 delta = p2->position - p1->position;
            float currentDistance = glm::length(delta);

            // Calculate how much the distance is off from the rest length
            float difference = (currentDistance - constraint.restLength) / currentDistance;

            // Adjust positions to satisfy the constraint
            if (!p1->isFixed) {
                p1->position += delta * 0.5f * difference;
            }
            if (!p2->isFixed) {
                p2->position -= delta * 0.5f * difference;
            }
        }
    }
}
