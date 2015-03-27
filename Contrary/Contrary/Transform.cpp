#include "Transform.h"


Transform::Transform()
{
}


Transform::~Transform()
{
}

Transform::Transform(entityid eid, Coordinates position, Coordinates scale, double rotation)
{
	m_eid = eid;
	m_position = position;
	m_scale = scale;
	m_rotation = rotation;
}

Coordinates* Transform::GetPosition()
{
	return &m_position;
}

Coordinates* Transform::GetScale()
{
	return &m_scale;
}

double Transform::GetRotation()
{
	return m_rotation;
}

void Transform::SetRotation(double rotation)
{
	m_rotation = rotation;
}