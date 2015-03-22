#pragma once
#include <vector>
#include <string>
#include <istream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <allegro5/allegro_primitives.h>

#include "Face.h"
#include "Coordinates.h"


using namespace std;

class Model
{
public:
	Model(string path, double scale = 1);
	~Model();
	Model();

	vector<Coordinates>* Vertecies();
	vector<Face>* Faces();
	ALLEGRO_VERTEX** AlVertecies();
	int AlVerteciesLength();

private:
	vector<Coordinates> m_vertecies;
	vector<Face> m_faces;
	ALLEGRO_VERTEX* m_alVertecies;
};

