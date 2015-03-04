#pragma once
#include "Model.h"
#include "Coordinates.h"
#include <allegro5\color.h>

using namespace std;

class Entity
{
public:
	Entity();
	~Entity();
private:
	Model m_model;
	ALLEGRO_COLOR m_color;
	double m_mass;
	double m_friction;
	Coordinates m_centerOfMass;
	double m_bounciness;
};

