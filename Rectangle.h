#pragma once
#include "IShape.h"

class Rectangle :
    public IShape
{
private:
    float width = 0;
    float height = 0;

public:
    Rectangle(float width, float height);

    float size() override;

    void Draw() override;
};

