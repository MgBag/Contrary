#pragma once

#include "Coordinates.h"
#include <cmath>

class Physics
{
public:
	Physics();
	~Physics();

	Coordinates GetProjection(Coordinates* toProj, Coordinates* projTo);
	double Pyth(Coordinates* cod);
	double Pyth(double a, double b);
};

