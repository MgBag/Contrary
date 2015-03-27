#pragma once
#include "Entity.h"
#include "Coordinates.h"
#include "Velocity.h"

class Physical :
	protected Entity
{
public:
	Physical(entityid eid, bool moveable = true, double mass = 1.0, double friction = 1.0, double bounciness = 0.0, double angularVelocity = 0.0, double velX = 0.0, double velY = 0.0, double cenX = 0.0, double cenY = 0.0);
	~Physical();

	Coordinates* GetCenterOfMass();
	Velocity* GetVelocity();
	bool GetMoveable();
	double GetMass();
	double GetFriction();
	double GetBounciness();
	double GetAngularVelocity();

	void SetCenterOfMass(Coordinates centerOfMass);
	void SetVelocity(Velocity velocity);
	void SetMoveable(bool moveable);
	void SetMass(double mass);
	void SetFriction(double friction);
	void SetBounciness(double bounciness);
	void SetAngularVelocity(double angularVelocity);

private:
	entityid m_eid;
	Coordinates m_centerOfMass;
	Velocity m_velocity;
	bool m_moveable;
	double m_mass;
	double m_friction;
	double m_bounciness;
	double m_angularVelocity;
};

