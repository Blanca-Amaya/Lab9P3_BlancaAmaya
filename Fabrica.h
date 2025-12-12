#pragma once
#include <vector>
#include <iostream>
#include "Carro.h"
using namespace std;

class Fabrica {
private:
	vector <Carro*> carros;

	// metodos
	Carro* crearCarroAlt();
	string modeloAlt();
	string colorAlt();
	string estadoMotorAlt();
	string DefectosAlt();

public:
	Fabrica();
	~Fabrica();

	// getters
	vector<Carro*> getCarros() const;

	// metodos
	void agregarCarroNuevo();
	void listarTodos() const;
	void listarSinDefectos() const;
	void listarConDefectos() const;
	void guardarCarros();
	void cargarCarros();

	void ordenar(vector<Carro*>& carros2);

};