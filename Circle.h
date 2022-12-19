#pragma once
#include "IShape.h"

static const float pi = 3.14f;

class Circle :
    public IShape
{
private:
    float r = 0;

public:
    Circle(float r);

    float size() override;

    void Draw() override;
};

