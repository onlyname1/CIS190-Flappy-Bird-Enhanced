#pragma once

#include "obstacle.h"

class BasicObstacle :
    public Obstacle
{
public:
    BasicObstacle(const sf::Texture& texture, int screenWidth, int screenHeight);

    void calculatePosition(float deltaTime) override;

    void setup() override;
};

