#pragma once

#include "obstacle.h"

class MovingObstacle :
    public Obstacle
{
public:
    MovingObstacle(const sf::Texture& texture, int screenWidth, int screenHeight);

    void calculatePosition(float deltaTime) override;

    void setup() override;

private:
    float yVelocity;
};

