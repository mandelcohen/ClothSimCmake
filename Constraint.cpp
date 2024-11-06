#include "Constraint.h"

Constraint::Constraint(Particle* particle1, Particle* particle2, float length, float stiffness)
: p1(particle1), p2(particle2), restLength(length), stiffness(stiffness) {}