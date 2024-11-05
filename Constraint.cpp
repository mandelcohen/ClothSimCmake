#include "Constraint.h"

Constraint::Constraint(Particle* particle1, Particle* particle2, float length)
: p1(particle1), p2(particle2), restLength(length) {}