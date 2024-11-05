#ifndef CLOTHSIMCMAKE_CLOTH_H
#define CLOTHSIMCMAKE_CLOTH_H

#include <vector>
#include "Particle.h"
#include "Constraint.h"

struct Cloth {
    std::vector<Particle> particles;
    std::vector<Constraint> constraints;
    int width, height;

    void initializeCloth(Cloth &cloth, int width, int height, float spacing);
};

#endif //CLOTHSIMCMAKE_CLOTH_H
