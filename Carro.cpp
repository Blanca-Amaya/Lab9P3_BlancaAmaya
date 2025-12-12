#include "Carro.h"
#include <sstream>

Carro::Carro(int id2, string modelo2, int anio2, string color2, string estadoMotor2) : id(id2), modelo(modelo2), anio(anio2), color(color2), estadoMotor(estadoMotor2){
}

Carro::~Carro() {
	for (int i = 0; i < defectos.size(); i++) {
		if (defectos[i] != nullptr) {
			delete defectos[i];
			defectos[i] = nullptr;
		}
	}
	defectos.clear();
}

int Carro::getId() {
	return id;
}

string Carro::getModelo() {
	return modelo;
}

int Carro::getAnio() {
	return anio;
}

string Carro::getColor() {
	return color;
}

string Carro::getEstadoMotor() {
	return estadoMotor;
}

vector<Defecto*> Carro::getDefectos() {
	return defectos;
}

void Carro::setId(int id2) {
	id = id2;
}

void Carro::setModelo(string modelo2) {
	modelo = modelo2;
}

void Carro::setAnio(int anio2) {
	anio = anio2;
}

void Carro::setColor(string color2) {
	color = color2;
}

void Carro::setEstadoMotor(string estadoMotor2) {
	estadoMotor = estadoMotor2;
}

void Carro::agregarDefecto(Defecto* defecto) {
	defectos.push_back(defecto);
}

string Carro::mostrarinformacion() const {
	stringstream s;
	s << "ID: " << id << ". Modelo: " << modelo << ", Año: " << anio << ", Color: " << color << ". Estado del Motor: " << estadoMotor;
	if (defectos.size() > 0) {
		s << ", Defectos: ";
		for (int i = 0; i < defectos.size(); i++) {
			s << defectos[i]->getDescripcion();
			if (i < defectos.size() - 1) {
				s << " | "; // separacion por defecto
			}
		}
	}
	return s.str(); // stringstream -> string
}

string Carro::informacionArchivo() const {
	stringstream s;
	s << id << ", " << modelo << ", " << anio << ", " << color << ", " << estadoMotor;
	
	
	if (defectos.size()) {
		s << ", ";
		for (int i = 0; i < defectos.size(); i++) {
			s << defectos[i]->getDescripcion();
			if (i < defectos.size() - 1) {
				s << " | "; // separador por defecto
			}
		}
	}
	return s.str();
}

bool Carro::defectoTiene() const {
	return defectos.size() > 0;
}
