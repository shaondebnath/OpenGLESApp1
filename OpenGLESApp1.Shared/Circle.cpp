//#include "pch.h"
#include "Circle.h"


Circle::Circle()
{
}


Circle::~Circle()
{
}

void Circle::circle_draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 0.0);

	glVertex3f(0.1, 0.1, 0.0);
	glVertex3f(0.9, 0.1, 0.0);
	glVertex3f(0.9, 0.9, 0.0);
	glVertex3f(0.1, 0.9, 0.0);

	glEnd();

	glFlush();
}
