#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <thread>
#include <map>

#include "Constants.h"
#include "Model.h"
#include "Renderer.h"
#include "Collider.h"
#include "Physical.h"
#include "Transform.h"

using namespace std;

void Physics(map<entityid, Collider> colliderMap, map<entityid, Transform> transformMap, map<entityid, Physical> physicalMap);
void Output(map<entityid, Renderer>* renderMap, map<entityid, Transform>* transformMap);

int main()
{
	ALLEGRO_DISPLAY* display = 0;
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

	display = al_create_display(10, 10);
	if (!display)
	{
		cout << "Failed to initiate display \n";
		al_destroy_event_queue(eventQueue);
		system("pause");
		return -1;
	}

	Model m = Model("c:/temp/testobj.obj");

	map<entityid, Renderer> renderMap;
	map<entityid, Collider> colliderMap;
	map<entityid, Transform> transformMap;
	map<entityid, Physical> physicalMap;

	renderMap[0] = Renderer(0, &m, al_map_rgb(20, 220, 20));
	transformMap[0] = Transform(0, Coordinates(100, 100), Coordinates(1, 1), 0);
	physicalMap[0] = Physical(0, false);

	thread output(Output, &renderMap, &transformMap);
	thread physics(Physics, &colliderMap, &transformMap, &physicalMap);

	output.join();
	physics.join();

	system("pause");
}

void Physics(map<entityid, Collider> colliderMap, map<entityid, Transform> transformMap, map<entityid, Physical> physicalMap)
{
}

void Output(map<entityid, Renderer>* renderMap, map<entityid, Transform>* transformMap)
{
	for (map<entityid, Renderer>::iterator renderer = renderMap->begin(); renderer != renderMap->end(); ++renderer)
	{
		////Regular drawing
		////Make sure this only gets called once (big collection of arrays needed in that case)
		//al_draw_prim((*m.AlVertecies()), NULL, NULL, 0, m.AlVerteciesLength(), ALLEGRO_PRIM_TRIANGLE_LIST);
		
		// Wire frame
		vector<Face>* faces = renderer->second.GetModel()->Faces();

		for (vector<Face>::iterator face = faces->begin(); face < faces->end(); ++face)
		{
			al_draw_triangle(
				face->A()->X(), face->A()->Y(),
				face->B()->X(), face->B()->Y(),
				face->C()->X(), face->C()->Y(),
				al_map_rgb(20, 220, 20), 1.0);
		}
	}

	al_flip_display();
}