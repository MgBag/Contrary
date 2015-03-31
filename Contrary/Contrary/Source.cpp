#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <thread>
#include <map>
#include <math.h>

#include "Constants.h"
#include "Model.h"
#include "Renderer.h"
#include "Collider.h"
#include "Physical.h"
#include "Transform.h"

using namespace std;

void Physics(map<entityid, Collider>* colliderMap, map<entityid, Transform>* transformMap, map<entityid, Physical>* physicalMap);
void Display(map<entityid, Renderer>* renderMap, map<entityid, Transform>* transformMap);
void InitEntities(vector<Model>& models, map<entityid, Renderer>& renderMap, map<entityid, Collider>& colliderMap, map<entityid, Transform>& transformMap, map<entityid, Physical>& physicalMap);
void InitModels(vector<Model>& models);

bool Quit = false;

int main()
{
	ALLEGRO_EVENT_QUEUE* eventQueue = 0;
	// Initialze Allegro and her pluggins
	if (!al_init())
	{
		cout << "Allegro failed to initiate\n";
		system("pause");
		return -1;
	}

	if (!al_install_keyboard())
	{
		cout << "Allegro install keyboard\n";
		system("pause");
		return -1;
	}

	if (!al_install_mouse())
	{
		cout << "Allegro install mouse\n";
		system("pause");
		return -1;
	}

	if (!al_init_primitives_addon())
	{
		cout << "Failed to initiate primitives addon\n";
		system("pause");
		return -1;
	}

	eventQueue = al_create_event_queue();
	if (!eventQueue)
	{
		cout << "Failed to initiate event queue\n";
		system("pause");
		return -1;
	}

	vector<Model> models;
	map<entityid, Renderer> renderMap;
	map<entityid, Collider> colliderMap;
	map<entityid, Transform> transformMap;
	map<entityid, Physical> physicalMap;

	InitModels(models);
	InitEntities(models, renderMap, colliderMap, transformMap, physicalMap);

	thread display(Display, &renderMap, &transformMap);
	thread physics(Physics, &colliderMap, &transformMap, &physicalMap);

	system("pause");
}

void Physics(map<entityid, Collider>* colliderMap, map<entityid, Transform>* transformMap, map<entityid, Physical>* physicalMap)
{
}

void Display(map<entityid, Renderer>* renderMap, map<entityid, Transform>* transformMap)
{
	ALLEGRO_DISPLAY* display = 0;

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display)
	{
		cout << "Failed to initiate display \n";
		system("pause");
	}

	while (!Quit)
	{
		al_clear_to_color(al_map_rgb(220, 220, 220));

		for (map<entityid, Renderer>::iterator renderer = renderMap->begin(); renderer != renderMap->end(); ++renderer)
		{
			////Regular drawing
			////Make sure this only gets called once (big collection of arrays needed in that case)
			//al_draw_prim((*m.AlVertecies()), NULL, NULL, 0, m.AlVerteciesLength(), ALLEGRO_PRIM_TRIANGLE_LIST);

			// Wire frame
			vector<Face>* faces = renderer->second.GetModel()->Faces();
			Transform* transform = &(*transformMap)[renderer->first];

			transform->SetRotation(transform->GetRotation() + 0.01);

			for (vector<Face>::iterator face = faces->begin(); face < faces->end(); ++face)
			{
				// x: (x * scalex * cos roation - y * scaley * sin rotation) + posx
				// y: (x * scalex * sin roation + y * scaley * cos rotation) + posy
				// Three times for the traingle
				al_draw_filled_triangle(
					(face->A()->X() * transform->GetScale()->X() * cos(transform->GetRotation()) - face->A()->Y() * transform->GetScale()->Y() * sin(transform->GetRotation())) + transform->GetPosition()->X(),
					(face->A()->X() * transform->GetScale()->X() * sin(transform->GetRotation()) + face->A()->Y() * transform->GetScale()->Y() * cos(transform->GetRotation())) + transform->GetPosition()->Y(),

					(face->B()->X() * transform->GetScale()->X() * cos(transform->GetRotation()) - face->B()->Y() * transform->GetScale()->Y() * sin(transform->GetRotation())) + transform->GetPosition()->X(),
					(face->B()->X() * transform->GetScale()->X() * sin(transform->GetRotation()) + face->B()->Y() * transform->GetScale()->Y() * cos(transform->GetRotation())) + transform->GetPosition()->Y(),

					(face->C()->X() * transform->GetScale()->X() * cos(transform->GetRotation()) - face->C()->Y() * transform->GetScale()->Y() * sin(transform->GetRotation())) + transform->GetPosition()->X(),
					(face->C()->X() * transform->GetScale()->X() * sin(transform->GetRotation()) + face->C()->Y() * transform->GetScale()->Y() * cos(transform->GetRotation())) + transform->GetPosition()->Y(),

					renderer->second.GetColor());
			}
		}

		al_flip_display();
	}
}

void InitEntities(vector<Model>& models, map<entityid, Renderer>& renderMap, map<entityid, Collider>& colliderMap, map<entityid, Transform>& transformMap, map<entityid, Physical>& physicalMap)
{
	entityid eid = 0;
	Model* m = &models[0];

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(100, 100), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(200, 100), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(300, 100), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(400, 100), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(500, 100), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(600, 100), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(700, 100), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(800, 100), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(900, 100), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(1000, 100), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(1100, 100), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(1200, 100), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(100, 200), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(200, 200), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(300, 200), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(400, 200), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(500, 200), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(600, 200), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(700, 200), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(800, 200), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(900, 200), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(1000, 200), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(1100, 200), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(1200, 200), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(100, 300), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(200, 300), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(300, 300), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(400, 300), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(500, 300), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(600, 300), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(700, 300), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(800, 300), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(900, 300), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(1000, 300), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(1100, 300), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(1200, 300), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(100, 400), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(200, 400), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(300, 400), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(400, 400), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(500, 400), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(600, 400), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(700, 400), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(800, 400), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(900, 400), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(1000, 400), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(1100, 400), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(1200, 400), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(100, 500), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(200, 500), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(300, 500), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(400, 500), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(500, 500), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(600, 500), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(700, 500), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(800, 500), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(900, 500), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(1000, 500), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(1100, 500), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(1200, 500), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(100, 600), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(200, 600), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(300, 600), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(400, 600), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(500, 600), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(600, 600), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(700, 600), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(800, 600), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(900, 600), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(1000, 600), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(1100, 600), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;

	renderMap[eid] = Renderer(eid, m, al_map_rgb(20, 220, 20));
	transformMap[eid] = Transform(eid, Coordinates(1200, 600), Coordinates(10, 10), 0);
	physicalMap[eid] = Physical(eid, false);
	++eid;
}

void InitModels(vector<Model>& models)
{
	models.push_back(Model("C:/temp/testobj.obj"));
}