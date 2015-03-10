#pragma once
#include "Model.h"
#include "Coordinates.h"
#include "Velocity.h"
#include <allegro5\color.h>

using namespace std;

class Entity
{
private:
	Model m_model;
	Coordinates m_centerOfMass;
	ALLEGRO_COLOR m_color;
	Coordinates m_position;
	Velocity m_velocity;
	double m_mass;
	double m_friction;
	double m_bounciness;
	double m_rotation;
	// In r/s
	double m_angularVelocity;

public:
	Entity(Model model, ALLEGRO_COLOR color, double x, double y, double mass = 10.0, double friction = 1.0, double bounciness = 0.0, double rotation = 0.0);
	Entity();
	~Entity();

	void SetModel(Model model);
	void SetColor(ALLEGRO_COLOR color);
	void SetCenterOfMass(Coordinates coordinates);
	void SetPosition(Coordinates position);
	void SetVelocity(Velocity velocity);
	void SetMass(double mass);
	void SetFriction(double friction);
	void SetBounciness(double bounciness);
	void SetRotation(double rotation);
	void SetAngularVelocity(double angularVelocity);

	// Naming this Model breaks because model is also a class.
	Model* GetModel();
	ALLEGRO_COLOR Color();
	Coordinates* CenterOfMass();
	Coordinates* Position();
	// Naming this Velocity breaks because Velocity is also a class.
	Velocity* GetVelocity();
	double Mass();
	double Friction();
	double Bounciness();
	double Rotation();
	double AngularVelocity();
};

