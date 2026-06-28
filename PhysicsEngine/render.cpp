#include "render.h"

void DrawParticles(
    sf::RenderWindow& window,
    const std::vector<Particle>& particles)
{
    for (const auto& particle : particles)
    {
        sf::CircleShape circle(particle.radius);

        circle.setOrigin(
            sf::Vector2f(particle.radius, particle.radius));

        circle.setFillColor(sf::Color::White);

        circle.setPosition(
            sf::Vector2f(
                particle.position.x,
                particle.position.y));

        window.draw(circle);
    }
}