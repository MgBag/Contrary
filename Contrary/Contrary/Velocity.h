#pragma once
class Velocity
{
public:
	Velocity(double x, double y);
	Velocity();
	~Velocity();
	double X();
	double Y();
	void SetX(double x);
	void SetY(double y);
private:
	double m_x, m_y;
};

