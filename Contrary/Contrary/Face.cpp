#include "Face.h"


Face::Face(Coordinates a, Coordinates b, Coordinates c)
{
	m_a = a;
	m_b = b;
	m_c = c;
}

Face::~Face()
{
}

Face::Face()
{
}

Coordinates* Face::A()
{
	return &m_a;
}

Coordinates* Face::B()
{
	return &m_b;
}

Coordinates* Face::C()
{
	return &m_c;
}