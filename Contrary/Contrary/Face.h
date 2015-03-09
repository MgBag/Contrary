#pragma once

#include "Coordinates.h"

class Face
{
public:
	Face();
	Face(Coordinates* a, Coordinates* b, Coordinates* c);
	~Face();
	const Coordinates* A();
	const Coordinates* B();
	const Coordinates* C();

private:
	Coordinates* m_a, * m_b, * m_c;
};

