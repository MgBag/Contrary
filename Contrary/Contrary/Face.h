#pragma once
class Face
{
public:
	Face(double a, double b, double c);
	~Face();
	double A();
	double B();
	double C();

private:
	double* m_a, m_b, m_c;
};

