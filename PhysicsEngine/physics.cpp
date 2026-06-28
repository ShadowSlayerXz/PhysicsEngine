#include "physics.h"
#include "constants.h"

void UpdatePhysics(std::vector<Particle>& particles)
{
    for (auto& particle : particles)
    {
        // Update velocity based on gravity
        particle.velocity.y += GRAVITY * DT;
        
        particle.position.x += particle.velocity.x * DT; // Update x position based on velocity
        particle.position.y += particle.velocity.y * DT; // Update y position based on velocity
    }
}