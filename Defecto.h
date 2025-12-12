#pragma once
#include <string>
#include <iostream>
using namespace std;

class Defecto {
private:
	string descripcion;
public:
	Defecto();
	Defecto(string descripcion2);
	~Defecto();

	// Getters
	string getDescripcion();

	// Setters
	void setDescripcion(string descripcion2);
};

