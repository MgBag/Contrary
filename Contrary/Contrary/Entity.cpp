#include "Entity.h"

Entity::Entity(Model model, ALLEGRO_COLOR color, double x, double y, double mass, double friction, double bounciness, double rotation)
{
	m_model = model;
	m_color = color;
	m_position = Coordinates(x, y);
	m_mass = mass;
	m_friction = friction;
	m_bounciness = bounciness;
	m_rotation = rotation;

	m_centerOfMass = Coordinates(0.0, 0.0);
	m_velocity = Velocity(0.0, 0.0);
	m_angularVelocity = 0.0;
}

Entity::Entity()
{
	// TODO : Make standard model function;
	// m_model = ;
	m_color = al_map_rgb(220, 220, 220);
	m_position = Coordinates(0.0, 0.0);
	m_mass = 10.0;
	m_friction = 1.0;
	m_bounciness = 0.0;
	m_rotation = 0.0;
	m_centerOfMass = Coordinates(0.0, 0.0);
	m_velocity = Velocity(0.0, 0.0);
	m_angularVelocity = 0.0;
}


Entity::~Entity()
{
}

void Entity::SetModel(Model model)
{
	m_model = model;
}

void Entity::SetColor(ALLEGRO_COLOR color)
{
	m_color = color;
}

void Entity::SetCenterOfMass(Coordinates coordinates)
{
	m_centerOfMass = coordinates;
}

void Entity::SetPosition(Coordinates position)
{
	m_position = position;
}

void Entity::SetVelocity(Velocity velocity)
{
	m_velocity = velocity;
}

void Entity::SetMass(double mass)
{
	m_mass = mass;
}

void Entity::SetFriction(double friction)
{
	m_friction = friction;
}

void Entity::SetBounciness(double bounciness)
{
	m_bounciness = bounciness;
}

void Entity::SetRotation(double rotation)
{
	m_rotation = rotation;
}

void Entity::SetAngularVelocity(double angularVelocity)
{
	m_angularVelocity = angularVelocity;
}

Model* Entity::GetModel()
{
	return &m_model;
}

ALLEGRO_COLOR Entity::Color()
{
	return m_color;
}

Coordinates* Entity::CenterOfMass()
{
	return &m_centerOfMass;
}

Coordinates* Entity::Position()
{
	return &m_position;
}

Velocity* Entity::GetVelocity()
{
	return &m_velocity;
}

double Entity::Mass()
{
	return m_mass;
}

double Entity::Friction()
{
	return m_friction;
}

double Entity::Bounciness()
{
	return m_bounciness;
}

double Entity::Rotation()
{
	return m_rotation;
}

double Entity::AngularVelocity()
{
	return m_angularVelocity;
}