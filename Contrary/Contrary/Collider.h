#pragma once
#include "Entity.h"
#include "Model.h"

class Collider :
	protected Entity
{
public:
	Collider(entityid eid, Model* collider);
	Collider();
	~Collider();

	const Model* GetCollider();
private:
	Model* m_collider;
};

