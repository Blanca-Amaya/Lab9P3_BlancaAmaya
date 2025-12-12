#include "Defecto.h"

Defecto::Defecto() {
	descripcion = "";
}

Defecto::Defecto(string descripcion2) : descripcion(descripcion2) {}

Defecto::~Defecto() {}

string Defecto::getDescripcion() {
	return descripcion;
}

void Defecto::setDescripcion(string descripcion2) {
	descripcion = descripcion2;
}