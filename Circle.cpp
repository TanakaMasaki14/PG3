#include "Circle.h"

Circle::Circle(float r) :
	r(r) {};

float Circle::size()
{
	return r * r * pi;
}

void Circle::Draw()
{
	printf("â~:ñ êœ %f \n", size());
}
