#include "Physics.h"


Physics::Physics()
{
}


Physics::~Physics()
{
}


Coordinates Physics::GetProjection(Coordinates* toProj, Coordinates* projTo)
{
	// Get the three vectors counterclockwise (get the delta's)
	// Project them over a given vector [1,3] for example
	// Draw them all with an offset

	// Proj a onto b.
	// dp = a.x*b.x + a.y*b.y; 
	// proj.x = (dp / (b.x*b.x + b.y*b.y)) * b.x;
	// proj.y = (dp / (b.x*b.x + b.y*b.y)) * b.y;

	double dp = toProj->X() * projTo->X() + toProj->Y() * projTo->Y();

	return Coordinates(
		dp / (projTo->X() * projTo->X() + projTo->Y() * projTo->Y()) * projTo->X(),
		dp / (projTo->X() * projTo->X() + projTo->Y() * projTo->Y()) * projTo->Y());

	//// Sides
	//// TODO : Maybe intergrade this
	//Coordinates deltaA = (*face->B()) - face->A();
	//Coordinates deltaB = (*face->C()) - face->B();
	//Coordinates deltaC = (*face->A()) - face->C();

	//double dpA = (deltaA.X() * transform->GetScale()->X()) * toProj.X() + (deltaA.Y() * transform->GetScale()->Y()) * toProj.Y();
	//double dpB = (deltaB.X() * transform->GetScale()->X()) * toProj.X() + (deltaB.Y() * transform->GetScale()->Y()) * toProj.Y();
	//double dpC = (deltaC.X() * transform->GetScale()->X()) * toProj.X() + (deltaC.Y() * transform->GetScale()->Y()) * toProj.Y();

	//Coordinates projA(
	//	dpA / (toProj.X() * toProj.X() + toProj.Y() * toProj.Y()) * toProj.X(),
	//	dpA / (toProj.X() * toProj.X() + toProj.Y() * toProj.Y()) * toProj.Y());

	//Coordinates projB(
	//	dpB / (toProj.X() * toProj.X() + toProj.Y() * toProj.Y()) * toProj.X(),
	//	dpB / (toProj.X() * toProj.X() + toProj.Y() * toProj.Y()) * toProj.Y());

	//Coordinates projC(
	//	dpC / (toProj.X() * toProj.X() + toProj.Y() * toProj.Y()) * toProj.X(),
	//	dpC / (toProj.X() * toProj.X() + toProj.Y() * toProj.Y()) * toProj.Y());


	//// Offsets
	//Coordinates OffsetA(transform->GetPosition()->X() + face->A()->X() * transform->GetScale()->X(), transform->GetPosition()->Y() + face->A()->Y() * transform->GetScale()->Y());
	//Coordinates OffsetB(transform->GetPosition()->X() + face->B()->X() * transform->GetScale()->X(), transform->GetPosition()->Y() + face->B()->Y() * transform->GetScale()->Y());
	//Coordinates OffsetC(transform->GetPosition()->X() + face->C()->X() * transform->GetScale()->X(), transform->GetPosition()->Y() + face->C()->Y() * transform->GetScale()->Y());

	//double dpOA = OffsetA.X() * toProj.X() + OffsetA.Y() * toProj.Y();
	//double dpOB = OffsetB.X() * toProj.X() + OffsetB.Y() * toProj.Y();
	//double dpOC = OffsetC.X() * toProj.X() + OffsetC.Y() * toProj.Y();

	//Coordinates offsetProjA(
	//	dpOA / (toProj.X() * toProj.X() + toProj.Y() * toProj.Y()) * toProj.X(),
	//	dpOA / (toProj.X() * toProj.X() + toProj.Y() * toProj.Y()) * toProj.Y());

	//Coordinates offsetprojB(
	//	dpOB / (toProj.X() * toProj.X() + toProj.Y() * toProj.Y()) * toProj.X(),
	//	dpOB / (toProj.X() * toProj.X() + toProj.Y() * toProj.Y()) * toProj.Y());

	//Coordinates offsetprojC(
	//	dpOC / (toProj.X() * toProj.X() + toProj.Y() * toProj.Y()) * toProj.X(),
	//	dpOC / (toProj.X() * toProj.X() + toProj.Y() * toProj.Y()) * toProj.Y());



	//al_draw_line(offsetProjA.X(), offsetProjA.Y(), offsetProjA.X() + projA.X(), offsetProjA.Y() + projA.Y(), al_map_rgb(220, 20, 20), 1);

	//al_draw_line(offsetProjA.X(), offsetProjA.Y(), OffsetA.X(), OffsetA.Y(), al_map_rgb(220, 220, 220), 1);
	//al_draw_line(offsetProjA.X() + projA.X(), offsetProjA.Y() + projA.Y(), OffsetB.X(), OffsetB.Y(), al_map_rgb(220, 220, 220), 1);


	//al_draw_line(offsetprojB.X(), offsetprojB.Y(), offsetprojB.X() + projB.X(), offsetprojB.Y() + projB.Y(), al_map_rgb(220, 220, 20), 1);

	//al_draw_line(offsetprojB.X(), offsetprojB.Y(), OffsetB.X(), OffsetB.Y(), al_map_rgb(220, 220, 220), 1);
	//al_draw_line(offsetprojB.X() + projB.X(), offsetprojB.Y() + projB.Y(), OffsetC.X(), OffsetC.Y(), al_map_rgb(220, 220, 220), 1);


	//al_draw_line(offsetprojC.X(), offsetprojC.Y(), offsetprojC.X() + projC.X(), offsetprojC.Y() + projC.Y(), al_map_rgb(220, 20, 220), 1);

	//al_draw_line(offsetprojC.X(), offsetprojC.Y(), OffsetC.X(), OffsetC.Y(), al_map_rgb(220, 220, 220), 1);
	//al_draw_line(offsetprojC.X() + projC.X(), offsetprojC.Y() + projC.Y(), OffsetA.X(), OffsetA.Y(), al_map_rgb(220, 220, 220), 1);

	////al_draw_line(																	// Normal offset
	////	transform->GetPosition()->X() + face->A()->X() * transform->GetScale()->X() - toProj.Y() * 10,
	////	transform->GetPosition()->Y() + face->A()->Y() * transform->GetScale()->Y() + toProj.X() * 10,
	////	(projA.X() * -1) + transform->GetPosition()->X() + face->A()->X() * transform->GetScale()->X() - toProj.Y() * 10,
	////	(projA.Y() * -1) + transform->GetPosition()->Y() + face->A()->Y() * transform->GetScale()->Y() + toProj.X() * 10,
	////	al_map_rgb(20, 220, 20), 1);

	////al_draw_line(
	////	transform->GetPosition()->X() + face->B()->X() * transform->GetScale()->X() - toProj.Y() * 10,
	////	transform->GetPosition()->Y() + face->B()->Y() * transform->GetScale()->Y() + toProj.X() * 10,
	////	(projB.X() * -1) + transform->GetPosition()->X() + face->B()->X() * transform->GetScale()->X() - toProj.Y() * 10,
	////	(projB.Y() * -1) + transform->GetPosition()->Y() + face->B()->Y() * transform->GetScale()->Y() + toProj.X() * 10,
	////	al_map_rgb(20, 220, 220), 1);

	////al_draw_line(
	////	transform->GetPosition()->X() + face->C()->X() * transform->GetScale()->X() - toProj.Y() * 10,
	////	transform->GetPosition()->Y() + face->C()->Y() * transform->GetScale()->Y() + toProj.X() * 10,
	////	(projC.X() * -1) + transform->GetPosition()->X() + face->C()->X() * transform->GetScale()->X() - toProj.Y() * 10,
	////	(projC.Y() * -1) + transform->GetPosition()->Y() + face->C()->Y() * transform->GetScale()->Y() + toProj.X() * 10,
	////	al_map_rgb(220, 220, 20), 1);

	///*	al_draw_line(
	//transform->GetPosition()->X() + o2,
	//transform->GetPosition()->Y(),
	//projB.X() + transform->GetPosition()->X() + o2,
	//projB.Y() + transform->GetPosition()->Y(),
	//al_map_rgb(20, 220, 20), 1);

	//al_draw_line(
	//transform->GetPosition()->X() + o3,
	//transform->GetPosition()->Y(),
	//projC.X() + transform->GetPosition()->X() + o3,
	//projC.Y() + transform->GetPosition()->Y(),
	//al_map_rgb(20, 220, 20), 1);*/

}

double Physics::Pyth(Coordinates* cod)
{
	return sqrt(pow(cod->X(), 2) + pow(cod->Y(), 2));
}

double Physics::Pyth(double a, double b)
{
	return sqrt(pow(a, 2) + pow(b, 2));
}