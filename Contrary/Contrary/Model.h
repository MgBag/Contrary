#pragma once
#include <vector>
#include "Face.h"
#include "Coordinates.h"

using namespace std;

class Model
{
public:
	Model(vector<Coordinates> polygons, vector<Face> faces);
	~Model();
	Model();

	const vector<Coordinates>* Polygons();
	const vector<Face>* Faces();

private:
	vector<Coordinates> m_polygons;
	vector<Face> m_faces;
};

