#include "Velocity.h"


Velocity::Velocity()
{
	m_x = 0.0;
	m_y = 0.0;
}

Velocity::Velocity(double x, double y)
{
	m_x = x;
	m_y = y;
}


Velocity::~Velocity()
{
}

double Velocity::X()
{
	return m_x;
}

double Velocity::Y()
{
	return m_y;
}

void Velocity::SetX(double x)
{
	m_x = x;
}

void Velocity::SetY(double y)
{
	m_y = y;
}