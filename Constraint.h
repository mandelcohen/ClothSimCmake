#ifndef CLOTHSIMCMAKE_CONSTRAINT_H
#define CLOTHSIMCMAKE_CONSTRAINT_H


struct Constraint {
    int particleA;             // Index of the first particle
    int particleB;             // Index of the second particle
    float restLength;          // Rest length of the constraint
    float stiffness;           // Stiffness factor (how strictly the constraint is enforced)
};


#endif //CLOTHSIMCMAKE_CONSTRAINT_H
