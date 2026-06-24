#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

constexpr signed int isNegativeGravity = -1; // -1 for negative gravity, 1 for positive gravity
constexpr float GRAVITY =   9.81f;
constexpr float RESTITUTION = 0.8f;
constexpr float DT = 1.0f / 480.0f;
constexpr unsigned int WINDOW_WIDTH = 1000u;
constexpr unsigned int WINDOW_HEIGHT = 800u;


struct vector2
{
    float x;
    float y;
}; 

struct Particle
{
    vector2 position;
    vector2 velocity;
    float mass;
    float radius;
};

std::vector<Particle> particles;

int main()
{
    // Create a window for rendering 
    sf::RenderWindow window(
        sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "Physics Engine");

    // Create a particle representing a ball    
    Particle ball;
    ball.position = { 500.0f, 400.0f };
    ball.velocity = { 0.0f, 0.0f };
    ball.mass = 1.0f;
    ball.radius = 5.0f;

    particles.reserve(1000); // Reserve space for 1000 particles
    particles.push_back(ball); // Add the ball to the particles vector

    //Create a circle shape to represent the ball visually
    sf::CircleShape ballshape(ball.radius);
    ballshape.setFillColor(sf::Color::White);

    // Set origin to center for proper positioning
    ballshape.setOrigin(sf::Vector2f(ball.radius, ball.radius));



    cout << "Ball created at position: [" << ball.position.x << ", " << ball.position.y << "] with radius: " << ball.radius << endl;
    float logTimer = 0.0f;

    while (window.isOpen())
    {


        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
			// Mouse button pressed event
			else if (event->is<sf::Event::MouseButtonPressed>())
			{
				auto mouseEvent = event->getIf<sf::Event::MouseButtonPressed>;
				cout << "Mouse button pressed at position: [" << mouseEvent.position.x << ", " << mouseEvent.position.y << "]" << endl;
			}

        }

        // Physics simulation loop
		for (auto& particle : particles)
		{
			// Update velocity based on gravity
			particle.velocity.y += isNegativeGravity * GRAVITY * DT;
			// Update position based on velocity
			particle.position.x += particle.velocity.x * DT;
			particle.position.y += particle.velocity.y * DT;
		}

        // Check for collision with the ground
        if (ball.position.y + ball.radius >= WINDOW_HEIGHT)
        {
            ball.position.y = WINDOW_HEIGHT - ball.radius; // Reset position to ground level
            ball.velocity.y *= -RESTITUTION; // Reverse and reduce velocity based on restitution
            cout << "Ball reset to ground" << endl;
        }
		// Check for collision with the top of the window
        if (ball.position.y + ball.radius <= 0)
        {

                ball.position.y = isNegativeGravity * ball.radius; // Reset position to top level
                ball.velocity.y *= -RESTITUTION; // Reverse and reduce velocity based on restitution
                cout << "Ball hit the top of the window!" << endl;
        }
		// Check for collision with the left side of the window
        if (ball.position.x - ball.radius <= 0)
        {
            ball.position.x = ball.radius; // Reset position to left level
            ball.velocity.x *= -RESTITUTION; // Reverse and reduce velocity based on restitution
        }
		// Check for collision with the right side of the window
		if (ball.position.x + ball.radius >= WINDOW_WIDTH)
		{
			ball.position.x = WINDOW_WIDTH - ball.radius; // Reset position to right level
			ball.velocity.x *= -RESTITUTION; // Reverse and reduce velocity based on restitution
		}


        //sync the visual representation with the particle's position   
		for (const auto& particle : particles)
		{
			ballshape.setPosition(sf::Vector2f(particle.position.x, particle.position.y));
		}

        logTimer += DT;
        if (logTimer >= 1.0f && ball.position.y + ball.radius <= WINDOW_HEIGHT)
        {
            cout << "Ball position: [" << ball.position.x << ", " << ball.position.y << "]" << " Velocity: [" << ball.velocity.x << ", " << ball.velocity.y << "]" << endl;
            logTimer = 0.0f;
        }

        window.clear();
        window.draw(ballshape);
        window.display();
    }

    return 0;
}
