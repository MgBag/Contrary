#pragma once
class Coordinates
{
public:
	Coordinates(double x, double y);
	~Coordinates();
	double X();
	double Y();
	void SetX(double x);
	void SetY(double y);
private:
	double m_x, m_y;
};

