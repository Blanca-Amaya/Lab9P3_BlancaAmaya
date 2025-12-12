#pragma once
#include <vector>
#include <iostream>
#include "Carro.h"
using namespace std;

class Fabrica {
private:
	vector <Carro*> carros;

	// metodos extras
	Carro* crearCarroAlt(); // -> crea un carro con los atributos aleatorios
	string modeloAlt(); // genera un modelo aleatorio usando el arreglo con datos ya incluido
	string colorAlt(); // genera un color alt
	string estadoMotorAlt(); // genera el estado del motor (bueno, regular, etc)
	string DefectosAlt(); // descripcion aleatoria
	void ordenar(vector<Carro*>& carros2);

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

	

};