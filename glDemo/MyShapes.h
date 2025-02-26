#pragma once

#include "core.h"
#include <cmath>

class MyShapes
{
public:
	// Pi
	static const float M_PI;

	// Function prototypes
	void drawPolygon(float _x, float _y, int _sides, float _radius);
	void drawStar(float _atX, float _atY, float _innerRadius, float _outerRadius, int _points);
	void drawTank(float _atX, float _atY, float _orientation, float r, float g, float b);
	void drawBlendedRectangles();
	static void drawSemiCircleStudio();
};

