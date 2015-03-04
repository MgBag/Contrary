#pragma once
#include <vector>
#include "Face.h"
#include "Coordinates.h"

using namespace std;

class Model
{
public:
	Model();
	~Model();
private:
	vector<Coordinates> m_polygons;
	vector<Face> m_faces;
};

