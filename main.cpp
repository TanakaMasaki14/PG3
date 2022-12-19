
#include"Circle.h"
#include"Rectangle.h"

int main()
{
	IShape* iShape[2];
	iShape[0] = new Circle(20.0f);
	iShape[1] = new Rectangle(10.0f, 5.0f);

	for (IShape* iShapes : iShape)
	{
		iShapes->Draw();
	}

	return 0;
}