#ifndef CLOTHSIMCMAKE_CLOTH_H
#define CLOTHSIMCMAKE_CLOTH_H

#include <vector>
#include "Particle.h"
#include "Constraint.h"

class Cloth {
public:
    std::vector<Particle> particles;
    std::vector<Constraint> constraints;
    int width, height;
    float spacing;
    float dampingFactor;

    Cloth(int width, int height, float spacing, float damping);

    void initializeParticles();
    void initializeConstraints();
    void applyForces(float deltaTime);
    void integrateMotion(float deltaTime, int windowWidth, int windowHeight);
    void enforceConstraints(int iterations);
};

#endif //CLOTHSIMCMAKE_CLOTH_H
