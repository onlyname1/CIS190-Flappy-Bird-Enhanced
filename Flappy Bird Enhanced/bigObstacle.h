#pragma once

#include "obstacle.h"

class BigObstacle :
    public Obstacle
{
public:
    BigObstacle(const sf::Texture& texture, int screenWidth, int screenHeight);

    void calculatePosition(float deltaTime) override;

    void setup() override;
};

