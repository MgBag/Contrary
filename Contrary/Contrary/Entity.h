#pragma once
#include "Constants.h"
#include "Model.h"
#include "Coordinates.h"
#include "Velocity.h"
#include <allegro5\color.h>

using namespace std;

class Entity
{
public:
	Entity(objectid oid) : m_oid(oid) {};
	Entity();
	~Entity();

	objectid Oid();

	//Model* GetModel();
	//ALLEGRO_COLOR Color();
	//Coordinates* CenterOfMass();
	//double Mass();
	//double Friction();
	//double Bounciness();
	//double Rotation();
	//Coordinates* Position();
	//Velocity* GetVelocity();
	//double AngularVelocity();

	//void SetModel(Model model);
	//void SetColor(ALLEGRO_COLOR color);
	//void SetCenterOfMass(Coordinates coordinates);
	//void SetMass(double mass);
	//void SetFriction(double friction);
	//void SetBounciness(double bounciness);
	//void SetRotation(double rotation);
	//void SetPosition(Coordinates position);
	//void SetVelocity(Velocity velocity);
	//void SetAngularVelocity(double angularVelocity);

private:
	objectid m_oid;
	//Model m_model;
	//ALLEGRO_COLOR m_color;
	//Coordinates m_centerOfMass;
	//double m_mass;
	//double m_friction;
	//double m_bounciness;
	//double m_rotation;
	//Coordinates m_position;
	//Velocity m_velocity;
	//double m_angularVelocity;
};

