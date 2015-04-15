#pragma once
class Coordinates
{
public:
	Coordinates();
	Coordinates(double x, double y);
	~Coordinates();
	double X();
	double Y();
	void SetX(double x);
	void SetY(double y);

	Coordinates operator-(Coordinates* sub);
	Coordinates operator+(Coordinates* sub);

private:
	double m_x, m_y;
};
