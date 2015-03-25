#pragma once
#include <allegro5\color.h>
#include "Entity.h"
#include "Model.h"

class Render : protected Entity
{
public:
	Render(entityid eid, Model* model, ALLEGRO_COLOR color);
	Render();
	~Render();

	const Model* GetModel();
	ALLEGRO_COLOR GetColor();
	void SetColor(ALLEGRO_COLOR color);
private:
	ALLEGRO_COLOR m_color;
	Model* m_model;
};
