#include "Fabrica.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

bool iniciado = false;


Carro* Fabrica::crearCarroAlt() {
	int id = rand() % 500 + 1;
	string modelo = modeloAlt();
	int anio = rand() % 16 + 2010;
	string color = colorAlt();
	string estadoMotor = estadoMotorAlt();

	Carro* carro = new Carro(id, modelo, anio, color,estadoMotor);
	int defectuosoNum = rand() % 5;
	for (int i = 0; i < defectuosoNum; i++) {
		string descripcionDefecto = DefectosAlt();
		Defecto* defecto = new Defecto(descripcionDefecto);
		carro->agregarDefecto(defecto);
	}
	return carro;
}
string Fabrica::modeloAlt() {
	string modelo[] = { "Corolla", "Yaris", "Rav4", "Hilux", "Prius", "Camry" };
	int pos = rand() % 6;
	return modelo[pos];
}

string Fabrica::colorAlt() {
	string colores[] = { "Plateado", "Negro", "Gris", "Verde", "Blanco", "Rojo", "Azul" };
	int pos = rand() & 7;
	return colores[pos];
}

string Fabrica::estadoMotorAlt() {
	string estados[] = { "Defectuoso", "Bueno", "Regular", "Excelente" };
	int pos = rand() % 4;
	return estados[pos];
}

string Fabrica::DefectosAlt() {
	string defectos[] = { "Sensor dañado", "Problema electrico", "Fallo en frenos", "Fuga de aceite", "Bateria defectuosa", "Ruedas dañada"};
	int pos = rand() % 6;
	return defectos[pos];
}

Fabrica::Fabrica() {
	if (!iniciado) {
		srand(time(0));
		iniciado = true;
	}
}

Fabrica::~Fabrica() {
	for (int i = 0; i < carros.size(); i++) {
		delete carros[i];
	}
	carros.clear();
}

vector<Carro*> Fabrica::getCarros() const {
	return carros;
}

void Fabrica::agregarCarroNuevo() {
	Carro* carronuevo = crearCarroAlt();
	carros.push_back(carronuevo);
	cout << "Carro creado" << endl;

}

void Fabrica::listarTodos() const {
	if (carros.empty()) {
		cout << "No hay carros guardado" << endl;
		return;
	}
	cout << "--- TODOS LOS CARROS DISPONIBLES ---" << endl;
	for (int i = 0; i < carros.size(); i++) {
		cout << carros[i]->mostrarinformacion() << endl;
	}
}

void Fabrica::listarSinDefectos() const {
	vector <Carro*> sinDefectos;
	for (int i = 0; i < carros.size(); i++) {
		if (!carros[i]->defectoTiene()) {
			sinDefectos.push_back(carros[i]);
		}
	}
	if (sinDefectos.empty()) {
		cout << "No hay carros sin defectos" << endl;
		return;
	}

	// ordenando
	vector <Carro*> ordena = sinDefectos;
	Fabrica temporal;
	temporal.ordenar(ordena);
	cout << "--- Carros sin defectos ---" << endl;
	for (int i = 0; i < ordena.size(); i++) {
		cout << ordena[i]->mostrarinformacion() << endl;
	}
}

void Fabrica::listarConDefectos() const {
	vector <Carro*> conDefectos;
	for (int i = 0; i < carros.size(); i++) {
		if (carros[i]->defectoTiene()) {
			conDefectos.push_back(carros[i]);
		}
	}
	if (conDefectos.empty()) {
		cout << "No hay carros con defectos" << endl;
		return;
	}

	vector <Carro*> ordena = conDefectos;
	Fabrica temporal;
	temporal.ordenar(ordena);
	cout << "--- Carros con defectos ---" << endl;
	for (int i = 0; i < ordena.size(); i++) {
		cout << ordena[i]->mostrarinformacion() << endl;
	}
}

void Fabrica::guardarCarros() {
	if (carros.empty()) {
		cout << "No hay carros guardados" << endl;
		return;
	}
	
	ofstream archivo("Carros.txt");
	if (!archivo.is_open()) {
		cout << "No se pudo abrir el archivo" << endl;
		return;
	}
	vector <Carro*> sinDefectos;
	vector <Carro*> conDefectos;

	for (int i = 0; i < carros.size(); i++) {
		if (carros[i]->defectoTiene()) {
			conDefectos.push_back(carros[i]);
		}
		else {
			sinDefectos.push_back(carros[i]);
		}
	}
	archivo << "CARROS SIN DEFECTOS\n";
	for (int i = 0; i < sinDefectos.size(); i++) {
		archivo << sinDefectos[i]->informacionArchivo() << endl;
	}
	archivo << "\nCARROS CON DEFECTOS\n";
	for (int i = 0; i < conDefectos.size(); i++) {
		archivo << conDefectos[i]->informacionArchivo() << endl;
	}
	archivo.close();
	cout << endl;
	cout << "Carros guardados correctamente." << endl;
}

void Fabrica::cargarCarros() {
	ifstream archivo("Carros.txt");
	if (!archivo.is_open()) {
		cout << "No se puede abrir el archivo" << endl;
		return;
	}

	string linea;
	getline(archivo, linea);
	bool sinDefectos2 = false;
	bool conDefectos2 = false;
	int numCargados = 0;
	while (getline(archivo, linea)) {
		if (linea.empty()) {
			continue;
		}
		// para identificar las secciones del archivo 
		if (linea == "CARROS SIN DEFECTOS") {
			sinDefectos2 = true;
			conDefectos2 = false;
			continue;
		}
		else if (linea == "CARROS CON DEFECTOS") {
			sinDefectos2 = false;
			conDefectos2 = true;
			continue;
		}
		// procesando linea que contenga datos de un carro
		if (sinDefectos2 || conDefectos2) {
			stringstream ss(linea);
			string dato;
			vector <string> datos_carro;
			while (getline(ss, dato, ',')) {
				// En caso que haya espacios
				if (!dato.empty() && dato[0] == ' ') {
					dato = dato.substr(1);
				}
				datos_carro.push_back(dato);
			}
		}
	}
}

void Fabrica::ordenar(vector<Carro*>& carros2) {
	int num = carros2.size();
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - 1; j++) {
			if (carros2[j]->getModelo() > carros2[j + 1]->getModelo()) {
				Carro* tempo = carros2[j];
				carros2[j] = carros2[j + 1];
				carros2[j + 1] = tempo;
			}
		}
	}
}
