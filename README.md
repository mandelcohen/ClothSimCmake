# Exam Project

## Pitch Statment:
> In my exam project, I aim to build an in-depth understanding of Position-Based Dynamics (PBD) and cloth simulation by creating a custom physics engine that produces realistic, visually engaging cloth behaviour in real-time. Drawing on my background in textiles, I will focus on capturing the nuanced “feel” and drape of various fabric types, closely managing the data for optimal performance.
> 
> To enhance the simulation’s realism, I plan to explore shader techniques and material properties, with the ultimate goal of showcasing an interactive demo that brings cloth to life through both physical accuracy and aesthetic detail.


## Milestones (draft)
| Week | Content                                                       |
|--------|--------------------------------------------------------------|
| 1 | Test-project setup in SDL; initial exploration of PBD fundamentals and simulation requirements alongside research. |
| 2 | Start up raylib project. Research and create simple compute shaders. Decide on what to present in final demo.|
| 3 | Implement core PBD algorithms as a compute shader, create initial constraints and log tests for stability and structure. |
| 4 | Introduce cloth-specific constraints like structural and bending, begin investigating damping and integration methods for smoother motion. |
| 5 | Experiment with basic material properties to influence cloth look and feel. |
| 6 | Optimise performance for real-time interaction, test appearance and response with varied cloth properties. |
| 7 | Prepare for interactive demo; finalise adjustments to physical accuracy, visual fidelity, and responsiveness. |

## Key Features:
1. **Custom Physics Engine**: Built to support real-time, life-like cloth simulation through Position-Based Dynamics.
2. **Textile-Inspired Constraints**: Including structural and bending constraints to mimic real fabric behaviours.
3. **Interactive Cloth Demo**: Designed to showcase simulation under various conditions, emphasising realism.
4. **Shader-Driven Material Properties**: Enhances cloth appearance through draping effects, translucency, and texture.
5. **Optimisation for Real-Time Use**: Data and code structures fine-tuned for responsiveness and efficiency.


## Class/Struct dependencies:
```mermaid
classDiagram
    class Particle {
        glm::vec2 position
        glm::vec2 previousPosition
        glm::vec2 velocity
        glm::vec2 acceleration
        float mass
        bool isFixed
    }

    class Constraint {
        Particle* p1
        Particle* p2
        float restLength
        float stiffness
    }

    class Cloth {
        std::vector~Particle~ particles
        std::vector~Constraint~ constraints
        int width
        int height
        float spacing
        float dampingFactor
    }

    Constraint --> Particle : p1, p2
    Cloth --> Particle : particles
    Cloth --> Constraint : constraints
```

## Main loop outline:
```mermaid
flowchart TD
    Start([Start Program]) --> InitWindow["Initialize SDLWindow"]
    InitWindow --> InitCloth["Initialize Cloth (width*height, spacing, damping)"]
    InitCloth --> SetDeltaTime["Set deltaTime"]
    SetDeltaTime --> MainLoop{"Main Loop: while (running)"}

    MainLoop --> HandleEvents["window.handleEvents()"]
    HandleEvents -->|running = true| ApplyForces["cloth.applyForces(deltaTime)"]
    ApplyForces --> IntegrateMotion["cloth.integrateMotion(deltaTime, window.width, window.heigt)"]
    IntegrateMotion --> EnforceConstraints["cloth.enforceConstraints(iterations)"]
    EnforceConstraints --> Render["window.Render(cloth)"]

    Render --> Delay["Delay to cap frame rate"]
    Delay --> MainLoop
    MainLoop -->|running = false| End([End Program])
```







 
