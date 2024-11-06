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
                constraints.push_back(Constraint(&particles[index], &particles[index + 1], spacing, 0.8f));
            }

            // Vertical
            if (y < height - 1) {
                constraints.push_back(Constraint(&particles[index], &particles[index + width], spacing, 0.8f));
            }
        }
    }
    // Bending Constraints
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = y * width + x;

            // Horizontal bending constraint
            if (x < width - 2) { // Two particles away horizontally
                constraints.push_back(Constraint(&particles[idx], &particles[idx + 2], spacing * 2, 0.3f));
            }

            // Vertical bending constraint
            if (y < height - 2) { // Two particles away vertically
                constraints.push_back(
                        Constraint(&particles[idx], &particles[idx + width * 2], spacing * 2, 0.3f));
            }
        }
    }

    // Pin top row
    for (int x = 0; x < width; ++x) {
        particles[x].isFixed = true;
    }
}

void Cloth::applyForces(float deltaTime) {
    const glm::vec2 gravity(0.0f, 50.0f); // Gravity pointing down
    for (auto& particle : particles) {
        if (!particle.isFixed) {
            particle.acceleration += gravity * deltaTime;
            std::cout << "Particle acceleration: " << particle.acceleration.y << std::endl;
        }
    }
}

void Cloth::integrateMotion(float deltaTime, int windowWidth, int windowHeight) {
    for (auto& particle : particles) {
        if (!particle.isFixed) {
            glm::vec2 tempPosition = particle.position;
            particle.position += (particle.position - particle.previousPosition) * dampingFactor
                                 + particle.acceleration * deltaTime * deltaTime;
            particle.previousPosition = tempPosition;

            std::cout << "Particle new position: " << particle.position.x << ", " << particle.position.y << std::endl;

            // Boundary collision detection
            if (particle.position.x < 0) particle.position.x = 0;
            if (particle.position.x > windowWidth) particle.position.x = windowWidth;
            if (particle.position.y < 0) particle.position.y = 0;
            if (particle.position.y > windowHeight) particle.position.y = windowHeight;

            particle.acceleration = glm::vec2(0.0f); // Reset acceleration
        }
    }
}


void Cloth::enforceConstraints(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        for (auto& constraint : constraints) {
            Particle* p1 = constraint.p1;
            Particle* p2 = constraint.p2;

            glm::vec2 delta = p2->position - p1->position;
            float currentDistance = glm::length(delta);
            float difference = (currentDistance - constraint.restLength) / currentDistance;

            // Apply the stiffness factor
            glm::vec2 adjustment = delta * 0.5f * difference * constraint.stiffness;
            std::cout << "Adjustment: " << adjustment.x << ", " << adjustment.y << std::endl;

            if (!p1->isFixed) p1->position += adjustment;
            if (!p2->isFixed) p2->position -= adjustment;
        }
    }
}

