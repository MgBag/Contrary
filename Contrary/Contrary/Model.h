#pragma once
#include <vector>
#include <string>
#include <istream>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Face.h"
#include "Coordinates.h"

using namespace std;

class Model
{
public:
	Model(string path);
	~Model();
	Model();

	const vector<Coordinates>* Vertecies();
	const vector<Face>* Faces();

private:
	vector<Coordinates> m_vertecies;
	vector<Face> m_faces;
};

