#include "Face.h"


Face::Face(Coordinates* a, Coordinates* b, Coordinates* c)
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
	m_a = 0;
	m_b = 0;
	m_c = 0;
}

const Coordinates* Face::A()
{
	return m_a;
}

const Coordinates* Face::B()
{
	return m_b;
}

const Coordinates* Face::C()
{
	return m_c;
}