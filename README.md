# PhysicsEngine

A 2D particle physics simulation built with C++20 and SFML 3.1.0.

## Build

**Prerequisites:**
- Visual Studio 2022 (PlatformToolset v145)
- C++20 standard
- SFML 3.1.0 placed at `External/SFML-3.1.0/`

**Steps:**
1. Open `PhysicsEngine.slnx` in Visual Studio 2022.
2. Select a configuration (Debug/Release) and platform (x64/x86).
3. Build and run.

## Usage

A window opens showing particles falling under gravity and bouncing off the edges. Click anywhere in the window to log coordinates to the console.

## Features

- Particle simulation with gravity and Euler integration
- Window boundary collision with restitution
- Multiple particle support (spawning via code)
- Fixed timestep physics loop (480 Hz)
- Event handling (close, mouse click)

## Project Structure

```
PhysicsEngine.cpp   Entry point & game loop
constants.h         Global constants (gravity, restitution, timestep, window size)
vector2.h           2D vector struct
particle.h          Particle struct (position, velocity, mass, radius)
input.h/.cpp        SFML event handling (close, mouse)
physics.h/.cpp      Gravity & Euler integration
collision.h/.cpp    Window boundary collision detection & response
render.h/.cpp       Particle rendering (SFML circle shapes)
```

## Controls

| Input | Action |
|---|---|
| Close window | Exit |
| Mouse click | Log coordinates to console |

## Roadmap

See [docs/physics_engine_roadmap.html](docs/physics_engine_roadmap.html) for planned features: particle-particle collisions, rigid bodies, constraints, broadphase optimization, and 3D extension.
