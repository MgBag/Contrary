#pragma once
#include "Entity.h"
#include "Coordinates.h"

class Transform :
	protected Entity
{
public:
	Transform(entityid eid, Coordinates position, Coordinates scale, double rotation);
	Transform();
	~Transform();

	Coordinates* GetPosition();
	Coordinates* GetScale();
	double GetRotation();
	void SetRotation(double rotation);

private:
	Coordinates m_position;
	Coordinates m_scale;
	double m_rotation;
};

