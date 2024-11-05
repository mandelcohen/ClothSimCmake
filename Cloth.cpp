#include "Cloth.h"

void Cloth::initializeCloth(Cloth &cloth, int width, int height, float spacing) {
    cloth.width = width;
    cloth.height = height;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Particle p;
            p.position = glm::vec2(x * spacing, y * spacing);
            p.previousPosition = p.position;
            p.acceleration = glm::vec2(0.0f);
            p.inverseMass = 1.0f;  // Set to 0 for pins
            cloth.particles.push_back(p);
        }
    }

    // Create constraints between adjacent particles
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = y * width + x;
            if (x < width - 1) { // Horizontal constraint
                cloth.constraints.push_back({idx, idx + 1, spacing, 1.0f});
            }
            if (y < height - 1) { // Vertical constraint
                cloth.constraints.push_back({idx, idx + width, spacing, 1.0f});
            }
        }
    }
}