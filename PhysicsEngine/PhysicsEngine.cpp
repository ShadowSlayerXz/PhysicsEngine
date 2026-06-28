#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "particle.h"
#include "vector2.h"

#include "constants.h"
#include "physics.h"
#include "collision.h"
#include "render.h"
#include "input.h"

std::vector<Particle> particles;

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Physics Engine");

    Particle ball;

    ball.position = {500.f,400.f};
    ball.velocity = {0.f,0.f};
    ball.mass = 1.f;
    ball.radius = 5.f;

    particles.reserve(1000);
    particles.push_back(ball);

    while (window.isOpen())
    {
        ProcessInput(window);

        UpdatePhysics(particles);

        HandleWindowCollisions(particles);

        window.clear();

        DrawParticles(window, particles);

        window.display();
    }

    return 0;
}