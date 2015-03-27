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
protected:
	entityid m_eid;
};

