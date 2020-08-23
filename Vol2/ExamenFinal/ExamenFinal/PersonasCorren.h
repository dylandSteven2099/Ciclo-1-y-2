#pragma once
#include"Entidad.h"
#include<vector>
class PersonasCorren :public::Entidad
{
public:
	PersonasCorren() {

		x = rand() % 400;
		y = rand() % 300;

		dx = rand() % 11 - 5;
		

		ancho = alto = 0;

		indiceX = 0;

	}

	void Mover(Graphics^ g)
	{
		if (x + dx < 0 || x + ancho + dx >= g->VisibleClipBounds.Width)
			dx *= -1;
		if (dx > 0) {
			indiceY = 1;

		}
		else {
			indiceY = 0;
		}
		x += dx;
		indiceX++;
		if (indiceX > 6)indiceX = 0;

	}


	void dibujar(Graphics^ g, Bitmap^ bmp) {

		ancho = bmp->Width / 7;
		alto = bmp->Height / 2;
		g->DrawImage(bmp, Zoom(), AreaVisible(), GraphicsUnit::Pixel);

	}


};


class PersoCorrenS {

	std::vector<PersonasCorren*>personass;

public:

	void agregarEnemigo(PersonasCorren* enemigos)
	{
		personass.push_back(enemigos);
	}

	void EliminarEnemigo(int pos)
	{
		personass.erase(personass.begin() + pos);
	}

	int getCantidad()
	{
		return personass.size();
	}

	PersonasCorren* getPersonanCorren(int i)
	{
		return personass[i];
	}

	void mover(Graphics^ g)
	{
		for each (PersonasCorren * E in personass)
			E->Mover(g);
	}

	void Mostrar(Graphics^ g, Bitmap^ bmp)
	{
		for each (PersonasCorren * E in personass)
			E->dibujar(g, bmp);
	}


};