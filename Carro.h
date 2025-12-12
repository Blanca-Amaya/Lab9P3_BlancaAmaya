#pragma once
#include <string>
#include <vector>
#include "Defecto.h"
#include <iostream>
using namespace std;

class Carro {
private:
	int id; // 1-500
	string modelo; // corolla, yaris, etc
	int anio; // 2010-2025
	string color;
	string estadoMotor; // excelente, bueno, regular, defectuoso
	vector <Defecto*> defectos; // lista de defectos del carro; puede quedarse vacia
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

