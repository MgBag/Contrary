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

void Physics::Collide(map<entityid, Collider>* colliderMap, map<entityid, Transform>* transformMap, map<entityid, Physical>* physicalMap)
{
	for (map<entityid, Collider>::iterator colA = colliderMap->begin(); colA != prev(colliderMap->end()); ++colA)
	{
		Model* colModelA = colA->second.GetCollider();
		Transform* transA = &(*transformMap)[colA->first];

		for (map<entityid, Collider>::iterator colB = next(colA); colB != colliderMap->end(); ++colB)
		{
			Model* colModelB = colA->second.GetCollider();
			Transform* transB = &(*transformMap)[colB->first];

			for (vector<vector<Coordinates>>::iterator faceA = colModelA->Faces()->begin(); faceA != colModelA->Faces()->end(); ++faceA)
			{
				vector<Coordinates> transFaceA(3);
				vector<Coordinates> faceNormals(6);
				vector<Coordinates> transFacePosA(3);
				vector<Coordinates> transFaceDeltaA(3);

				for (int i = 0; i < faceA->size(); ++i)
				{
					transFaceA[i] = Coordinates(
						(*faceA)[i].X() * transA->GetScale()->X() * cos(transA->GetRotation()) - (*faceA)[i].Y() * transA->GetScale()->Y() * sin(transA->GetRotation()),
						(*faceA)[i].X() * transA->GetScale()->X() * sin(transA->GetRotation()) + (*faceA)[i].Y() * transA->GetScale()->Y() * cos(transA->GetRotation()));

					transFacePosA[i] = (*transA->GetPosition()) + &transFaceA[i];
				}

				transFaceDeltaA[0] = transFaceA[1] - &transFaceA[0];
				transFaceDeltaA[1] = transFaceA[2] - &transFaceA[1];
				transFaceDeltaA[2] = transFaceA[0] - &transFaceA[2];

				for (int i = 0; i < faceA->size(); ++i)
				{
					faceNormals[i] = Coordinates(-transFaceDeltaA[i].Y(), transFaceDeltaA[i].X());
				}

				for (vector<vector<Coordinates>>::iterator faceB = colModelB->Faces()->begin(); faceB != colModelB->Faces()->end(); ++faceB)
				{
					vector<Coordinates> transFaceB(3);
					vector<Coordinates> transFacePosB(3);
					vector<Coordinates> transFaceDeltaB(3);

					for (int i = 0; i < faceB->size(); ++i)
					{
						transFaceB[i] = Coordinates(
							(*faceB)[i].X() * transB->GetScale()->X() * cos(transB->GetRotation()) - (*faceB)[i].Y() * transB->GetScale()->Y() * sin(transB->GetRotation()),
							(*faceB)[i].X() * transB->GetScale()->X() * sin(transB->GetRotation()) + (*faceB)[i].Y() * transB->GetScale()->Y() * cos(transB->GetRotation()));

						transFacePosB[i] = (*transB->GetPosition()) + &transFaceB[i];
					}

					transFaceDeltaB[0] = transFaceB[1] - &transFaceB[0];
					transFaceDeltaB[1] = transFaceB[2] - &transFaceB[1];
					transFaceDeltaB[2] = transFaceB[0] - &transFaceB[2];

					for (int i = 0; i < faceB->size(); ++i)
					{
						faceNormals[i + 3] = Coordinates(-transFaceDeltaB[i].Y(), transFaceDeltaB[i].X());
					}

					al_clear_to_color(al_map_rgb(20, 20, 20));
					al_draw_line(0, SCREEN_H / 2, SCREEN_W, SCREEN_H / 2, al_map_rgb(120, 120, 120), 1);
					al_draw_line(SCREEN_W / 2, 0, SCREEN_W / 2, SCREEN_H, al_map_rgb(120, 120, 120), 1);

					for (vector<Coordinates>::iterator normal = faceNormals.begin(); normal != faceNormals.end(); ++normal)
					{
						Coordinates minA;
						Coordinates maxA;
						Coordinates minB;
						Coordinates maxB;
						
						// faceA
						for (int i = 0; i < transFaceA.size(); ++i)
						{
							if (!i)
							{
								minA = GetProjection(&transFacePosA[i], &*normal);
								maxA = GetProjection(&transFacePosA[i], &*normal);
							}
							else
							{
								Coordinates	temp(GetProjection(&transFacePosA[i], &*normal));

								if (Pyth(&temp) < Pyth(&minA))
								{
									minA = temp;
								}
								else if (Pyth(&temp) > Pyth(&maxA))
								{
									maxA = temp;
								}
							}
						}

						// faceB
						for (int i = 0; i < transFaceB.size(); ++i)
						{
							if (!i)
							{
								minB = GetProjection(&transFacePosB[i], &*normal);
								maxB = GetProjection(&transFacePosB[i], &*normal);
							}
							else
							{
								Coordinates	temp(GetProjection(&transFacePosB[i], &*normal));

								if (Pyth(&temp) < Pyth(&minB))
								{
									minB = temp;
								}
								else if (Pyth(&temp) > Pyth(&maxB))
								{
									maxB = temp;
								}
							}
						}
						
						al_draw_line(
							minA.X() / 2 + SCREEN_W / 2,
							minA.Y() / 2 + SCREEN_H / 2,
							maxA.X() / 2 + SCREEN_W / 2,
							maxA.Y() / 2 + SCREEN_H / 2,
							al_map_rgb(220, 20, 220), 1);

						al_draw_line(
							minB.X() / 2 + SCREEN_W / 2,
							minB.Y() / 2 + SCREEN_H / 2,
							maxB.X() / 2 + SCREEN_W / 2,
							maxB.Y() / 2 + SCREEN_H / 2,
							al_map_rgb(220, 220, 20), 1);

						// See if they are overlapping, break if not
					}

					al_flip_display();
				}
			}
		}
	}

	al_flip_display();
}