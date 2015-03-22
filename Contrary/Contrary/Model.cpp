#include "Model.h"

Model::Model(string path, double scale)
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
					// TODO : REMOVE THE OFFSET HERE!
					m_vertecies.push_back(Coordinates(stod(values[1]) * scale + 100, stod(values[3]) * scale + 100));
				}
				else if (values[0] == "f")
				{
					m_faces.push_back(Face(
						m_vertecies[stoi(values[1].substr(0, values[1].find('/'))) - 1],
						m_vertecies[stoi(values[2].substr(0, values[2].find('/'))) - 1],
						m_vertecies[stoi(values[3].substr(0, values[3].find('/'))) - 1]
						));

					m_alVertecies;
				}
			}
		}

		ifs.close();
	}

	m_alVertecies = new ALLEGRO_VERTEX[m_faces.size() * 3];

	for (int i = 0, j = 0; i < m_faces.size(); i++, j += 3)
	{
		m_alVertecies[j] = { m_faces[i].A()->X(), m_faces[i].A()->Y(), 0, m_faces[i].A()->X(), m_faces[i].A()->Y(), al_map_rgb(220, 20, 220) };
		m_alVertecies[j + 1] = { m_faces[i].B()->X(), m_faces[i].B()->Y(), 0, m_faces[i].B()->X(), m_faces[i].B()->Y(), al_map_rgb(220, 20, 220) };
		m_alVertecies[j + 2] = { m_faces[i].C()->X(), m_faces[i].C()->Y(), 0, m_faces[i].C()->X(), m_faces[i].C()->Y(), al_map_rgb(220, 20, 220) };
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

vector<Coordinates>* Model::Vertecies()
{
	return &m_vertecies;
}

vector<Face>* Model::Faces()
{
	return &m_faces;
}

int Model::AlVerteciesLength()
{
	return m_faces.size() * 3;
}

ALLEGRO_VERTEX** Model::AlVertecies()
{
	return &m_alVertecies;
}