#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>

#include "Constants.h"
#include "Model.h"

using namespace std;

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

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display)
	{
		cout << "Failed to initiate display \n";
		al_destroy_event_queue(eventQueue);
		system("pause");
		return -1;
	}

	////Regular drawing
	//Model m = Model("c:/temp/testobj.obj", 25);
	//
	//al_draw_prim((*m.AlVertecies()), NULL, NULL, 0, m.AlVerteciesLength(), ALLEGRO_PRIM_TRIANGLE_LIST);

	//// Wire frame
	//vector<Face>* faces = m.Faces();
	//
	//for (vector<Face>::iterator face = faces->begin(); face < faces->end(); ++face)
	//{
	//	al_draw_triangle(face->A()->X(), face->A()->Y(), face->B()->X(), face->B()->Y(), face->C()->X(), face->C()->Y(), al_map_rgb(20, 220, 20), 1.0);
	//}

	al_flip_display();

	system("pause");
 }