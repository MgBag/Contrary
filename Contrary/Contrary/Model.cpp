#include "Model.h"

Model::Model(string path)
{
	std::ifstream ifs(path);
	string line;

	if (ifs.is_open())
	{
		while (getline(ifs, line))
		{
			vector<string> values;
			string item;

			stringstream lineStream(line);

			while (getline(lineStream, item, ' '))
			{
				if (!item.empty())
				{
					values.push_back(item);
				}
			}

			if (values.size())
			{
				if (values[0] == "v")
				{
					m_vertecies.push_back(Coordinates(stod(values[1]), stod(values[3])));
				}
				else if (values[0] == "f")
				{
					m_faces.push_back(Face(
						&m_vertecies[stoi(values[1].substr(0, values[1].find('/'))) - 1],
						&m_vertecies[stoi(values[2].substr(0, values[2].find('/'))) - 1],
						&m_vertecies[stoi(values[3].substr(0, values[3].find('/'))) - 1]
						));

					m_alVertecies;
				}
			}
		}
	}
}

Model::~Model()
{
}

Model::Model()
{
	m_vertecies = vector<Coordinates>();
	m_faces = vector<Face>();
}

const vector<Coordinates>* Model::Vertecies()
{
	return &m_vertecies;
}

const vector<Face>* Model::Faces()
{
	return &m_faces;
}

int Model::AlVerteciesLength()
{
	return m_faces.size();
}