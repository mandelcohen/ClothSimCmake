#ifndef CLOTHSIMCMAKE_SIMULATIONPARAMS_H
#define CLOTHSIMCMAKE_SIMULATIONPARAMS_H

#include <glm/glm.hpp>

struct SimulationParams {
    float timeStep;
    glm::vec2 gravity;
    float damping;         // Damping to slow down particles
    int solverIterations;  // Number of iterations for constraint satisfaction
};



#endif //CLOTHSIMCMAKE_SIMULATIONPARAMS_H
