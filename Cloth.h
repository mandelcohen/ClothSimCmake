#ifndef CLOTHSIMCMAKE_CLOTH_H
#define CLOTHSIMCMAKE_CLOTH_H

#pragma once
#include <vector>
#include "Particle.h"
#include "Constraint.h"

class Cloth {
public:
    std::vector<Particle> particles;
    std::vector<Constraint> constraints;
    int width, height;
    float spacing;

    Cloth(int width, int height, float spacing);

    void initializeParticles();
    void initializeConstraints();
};

#endif //CLOTHSIMCMAKE_CLOTH_H
