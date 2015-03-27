#include "Collider.h"


Collider::Collider()
{
}


Collider::~Collider()
{
}

Collider::Collider(entityid eid, Model* collider)
{
	m_eid = eid;
	m_collider = collider;
}

const Model* Collider::GetCollider()
{
	return m_collider;
}
