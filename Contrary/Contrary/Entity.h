#pragma once
#include "Constants.h"

using namespace std;

class Entity
{
public:
	Entity(entityid eid) : m_eid(eid) {};
	Entity();
	~Entity();

	entityid Eid();

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

protected:
	entityid m_eid;
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

