#pragma once
#include <string>
#include <vector>
#include "Defecto.h"
#include <iostream>
using namespace std;

class Carro {
private:
	int id;
	string modelo;
	int anio;
	string color;
	string estadoMotor;
	vector <Defecto*> defectos;
public:
	Carro(int id2, string modelo2, int anio2, string color2, string estadoMotor2);
	~Carro();

	// Getters
	int getId();
	string getModelo();
	int getAnio();
	string getColor();
	string getEstadoMotor();
	vector <Defecto*> getDefectos();

	// Setters
	void setId(int id2);
	void setModelo(string modelo2);
	void setAnio(int anio2);
	void setColor(string color2);
	void setEstadoMotor(string estadoMotor2);

	// Metodos
	void agregarDefecto(Defecto* defecto);
	string mostrarinformacion() const;
	string informacionArchivo() const;

	bool defectoTiene() const;
};

