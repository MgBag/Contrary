#include "Renderer.h"

Renderer::Renderer(entityid eid, Model* model, ALLEGRO_COLOR color)
{
	m_eid = eid;
	m_model = model;
	m_color = color;
}

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

Model* Renderer::GetModel()
{
	return m_model;
}

ALLEGRO_COLOR Renderer::GetColor()
{
	return m_color;
}

void Renderer::SetColor(ALLEGRO_COLOR color)
{
	m_color = color;
}