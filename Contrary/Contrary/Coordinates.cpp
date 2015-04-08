#include "Coordinates.h"


Coordinates::Coordinates(double x, double y)
{
	m_x = x;
	m_y = y;
}

Coordinates::Coordinates()
{
	m_x = 0.0;
	m_y = 0.0;
}

Coordinates::~Coordinates()
{
}

double Coordinates::X()
{
	return m_x;
}

double Coordinates::Y()
{
	return m_y;
}

void Coordinates::SetX(double x)
{
	m_x = x;
}

void Coordinates::SetY(double y)
{
	m_y = y;
}

Coordinates Coordinates::operator-(Coordinates* sub)
{
	return Coordinates(this->m_x - sub->m_x, this->m_y - sub->m_y);
}

Coordinates Coordinates::operator+(Coordinates* sub)
{
	return Coordinates(this->m_x + sub->m_x, this->m_y + sub->m_y);
}