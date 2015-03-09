#include "Model.h"


Model::Model(vector<Coordinates> polygons, vector<Face> faces)
{
	m_polygons = polygons;
	m_faces = faces;
}

Model::~Model()
{
}

Model::Model()
{
	m_polygons = vector<Coordinates>();
	m_faces = vector<Face>();
}

const vector<Coordinates>* Model::Polygons()
{
	return &m_polygons;
}

const vector<Face>* Model::Faces()
{
	return &m_faces;
}