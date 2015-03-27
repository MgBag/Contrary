#include "Physical.h"


Physical::Physical(entityid eid, bool moveable, double mass, double friction, double bounciness, double angularVelocity, double velX, double velY, double cenX, double cenY)
{
	m_eid = eid;
	m_moveable = moveable;
	m_mass = mass;
	m_friction = friction;
	m_bounciness = bounciness;
	m_angularVelocity = angularVelocity;
	m_velocity = Velocity(velX, velY);
	m_centerOfMass = Coordinates(cenX, cenY);
}


Physical::~Physical()
{
}

Coordinates* Physical::GetCenterOfMass()
{
	return &m_centerOfMass;
}

Velocity* Physical::GetVelocity()
{
	return &m_velocity;
}

bool Physical::GetMoveable()
{
	return m_moveable;
}

double Physical::GetMass()
{
	return m_mass;
}

double Physical::GetFriction()
{
	return m_friction;
}

double Physical::GetBounciness()
{
	return m_bounciness;
}

double Physical::GetAngularVelocity()
{
	return m_angularVelocity;
}


void Physical::SetCenterOfMass(Coordinates centerOfMass)
{
	m_centerOfMass = centerOfMass;
}

void Physical::SetVelocity(Velocity velocity)
{
	m_velocity = velocity;
}

void Physical::SetMoveable(bool moveable)
{
	m_moveable = moveable;
}

void Physical::SetMass(double mass)
{
	m_mass = mass;
}

void Physical::SetFriction(double friction)
{
	m_friction = friction;
}

void Physical::SetBounciness(double bounciness)
{
	m_bounciness = bounciness;
}

void Physical::SetAngularVelocity(double angularVelocity)
{
	m_angularVelocity = angularVelocity;
}
