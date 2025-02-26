#include "MyShapes.h"
#include "core.h"

void MyShapes::drawPolygon(float _x, float _y, int _sides, float _radius)
{
	const float M_PI = 3.14f;
	if (_sides < 3) return;

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(_x, _y);

	for (int i = 0; i <= _sides; i++)
	{
		float angle = (2.0f * M_PI * i) / _sides;
		float x = _x + cos(angle) * _radius;
		float y = _y + sin(angle) * _radius;
		glVertex2f(x, y);
	}
	glEnd();
}

void MyShapes::drawStar(float _atX, float _atY, float _innerRadius, float _outerRadius, int _points)
{
	const float M_PI = 3.14f;
	float angStep = M_PI / _points;

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(_atX, _atY); // Star center

	for (int i = 0; i <= 2 * _points; i++)
	{
		float a = i * angStep;
		float rad = (i % 2 == 0) ? _outerRadius : _innerRadius;
		float x = _atX + rad * cos(a);
		float y = _atY + rad * sin(a);
		glVertex2f(x, y);
	}
	glEnd();
}

void MyShapes::drawTank(float _atX, float _atY, float _orientation, float r, float g, float b)
{
	glPushMatrix(); // Saves current matrix
	glTranslatef(_atX, _atY, 0.0f); // Move to stated pos
	glRotatef(_orientation, 0.0f, 0.0f, 1.0f); // Rotate tank

	// Set tank colour
	glColor3f(r, g, b);

	// Draw tank base
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.75f, 0.4f);
	glVertex2f(0.75f, 0.4f);
	glVertex2f(0.75f, -0.4f);
	glVertex2f(-0.75f, -0.4f);
	glEnd();

	// Draw tank gun
	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.5f, 0.3f);
	glVertex2f(0.5f, 0.0f);
	glVertex2f(-0.5f, -0.3f);
	glEnd();

	glPopMatrix(); // Restore transformation matrix
}

void MyShapes::drawBlendedRectangles()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);

	// Blue rectangle
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(-0.5f, 0.0f);
	glEnd();

	// Green rectangle
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
	glVertex2f(-0.25f, 0.75f);
	glVertex2f(0.25f, 0.75f);
	glVertex2f(0.25f, 0.25f);
	glVertex2f(-0.25f, 0.25f);
	glEnd();

	// Red rectangle
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(0.5f, 0.0f);
	glVertex2f(0.0f, 0.0f);
	glEnd();

	glDisable(GL_BLEND);
}

void MyShapes::drawSemiCircleStudio()
{
	const float M_PI = 3.14f;
	glShadeModel(GL_FLAT);
	glBegin(GL_TRIANGLE_FAN);

	const float rad = 0.8f;
	const int numTriangles = 6;
	const float angleStep = M_PI / numTriangles;

	float colours[numTriangles + 1][3] =
	{
		{1.0f, 0.0f, 1.0f}, //start with purple
		{1.0f, 0.0f, 1.0f}, //Purple
		{0.0f, 0.0f, 1.0f}, //Blue
		{0.0f, 1.0f, 1.0f}, //Light Blue
		{0.0f, 1.0f, 0.0f}, //Green
		{1.0f, 1.0f, 0.0f}, //Yellow
		{1.0f, 0.0f, 0.0f} //Close with Red
	};

	glVertex2f(0.0f, 0.0f);
	glColor3f(colours[0][0], colours[0][1], colours[0][2]);

	for (int i = 0; i <= numTriangles; i++)
	{
		float ori = i * angleStep;
		float x = rad * cos(ori);
		float y = rad * sin(ori);

		glColor3f(colours[i][0], colours[i][1], colours[i][2]);
		glVertex2f(x, y);
	}
	glEnd();
}
