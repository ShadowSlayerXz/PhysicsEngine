#include "collision.h"
#include "constants.h"

void HandleWindowCollisions(std::vector<Particle>& particles)
{
    for (auto& particle : particles)
    {
        // Bottom
        if (particle.position.y + particle.radius >= WINDOW_HEIGHT)
        {
            particle.position.y = WINDOW_HEIGHT - particle.radius;
            particle.velocity.y *= -RESTITUTION;
        }

        // Top
        if (particle.position.y - particle.radius <= 0)
        {
            particle.position.y = particle.radius;
            particle.velocity.y *= -RESTITUTION;
        }

        // Left
        if (particle.position.x - particle.radius <= 0)
        {
            particle.position.x = particle.radius;
            particle.velocity.x *= -RESTITUTION;
        }

        // Right
        if (particle.position.x + particle.radius >= WINDOW_WIDTH)
        {
            particle.position.x = WINDOW_WIDTH - particle.radius;
            particle.velocity.x *= -RESTITUTION;
        }
    }
}