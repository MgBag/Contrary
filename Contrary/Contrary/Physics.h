#pragma once

#include "Coordinates.h"
#include "Constants.h"
#include "Collider.h"
#include "Transform.h"
#include "Physical.h"
#include <cmath>
#include <map>

class Physics
{
public:
	Physics();
	~Physics();

	Coordinates GetProjection(Coordinates* toProj, Coordinates* projTo);
	double Pyth(Coordinates* cod);
	double Pyth(double a, double b);

	void Collide(map<entityid, Collider>* colliderMap, map<entityid, Transform>* transformMap, map<entityid, Physical>* physicalMap);
};

