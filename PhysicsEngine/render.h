#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "particle.h"

void DrawParticles(
    sf::RenderWindow& window,
    const std::vector<Particle>& particles);