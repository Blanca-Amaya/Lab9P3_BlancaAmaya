#pragma once
#include <vector>
#include <iostream>
#include "Carro.h"
using namespace std;

class Fabrica {
private:
	vector <Carro*> carros;
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

};