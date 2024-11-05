#ifndef CLOTHSIMCMAKE_CONSTRAINT_H
#define CLOTHSIMCMAKE_CONSTRAINT_H

#pragma once

class Particle;

struct Constraint {
    Particle* p1;
    Particle* p2;
    float restLength;

    Constraint(Particle* particle1, Particle* particle2, float length);
};


#endif //CLOTHSIMCMAKE_CONSTRAINT_H
