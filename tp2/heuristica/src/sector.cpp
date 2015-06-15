#include "sector.h"

Sector::Sector(vector<int> posturasConflictos) {
	this->opcionesPosturasConflictos.push_back(posturasConflictos);
	this->resuelto = false;
	this->cantidadDeConflictosTotales = posturasConflictos.size();
	this->tieneVicepresidencia = false;
}

Sector::~Sector() {
}

bool Sector::getApoyo(vector<int>& conflictos) {
	if (tieneVicepresidencia) {
		return true;
	} else {
		bool apoyo = false;
		// Reviso por todas las distintas opciones que tengo para obtener el apoyo
		// Si ya con alguna opcion obtuve el apoyo, no hace falta seguir iterando
		// Si con NINGUNA opcion, obtuve el apoyo, recien ahi se que no tengo el apoyo del sector
		for(unsigned int j = 0; !apoyo and j < opcionesPosturasConflictos.size(); j++){
			apoyo = true;
			// Una vez que hay una postura distinta a la mia, no tiene el apoyo y no tiene sentido seguir comparando
			for(unsigned int i = 0; apoyo and i < conflictos.size(); i++){
				// Tiene el apoyo si en todos los conflictos se toma la misma postura que yo quiero (A menos que no me interese cual sea la postura en ese conflicto)
				if ( (opcionesPosturasConflictos[j][i] != -1) and (conflictos[i] != -1) ){
					apoyo = (conflictos[i] == opcionesPosturasConflictos[j][i]);
				}
			}
		}
		return apoyo;
	}
}

void Sector::agregarOpcion(vector<int> posturaConflictos) {
	this->opcionesPosturasConflictos.push_back(posturaConflictos);
}

int Sector::minimaCantidadDeConflictosASolucionar() {

	int minConflictos 	 = cantidadDeConflictosTotales;
	int contadorPosturas = 0;

	// Itero por todas las opciones
	for(unsigned int j = 0; j < opcionesPosturasConflictos.size(); j++){

		contadorPosturas = 0;
		// Cuento la cantidad de posturas frente a un conflicto, las cuales son distintas de -1
		for(unsigned int i = 0; i < opcionesPosturasConflictos[j].size(); i++){

			if(opcionesPosturasConflictos[j][i] >= 0){
				contadorPosturas++;
			}
		}

		// Si en esta opcion tengo que tomar menor cantidad de posturas que antes, me quedo con esta
		if(contadorPosturas < minConflictos) minConflictos = contadorPosturas;
	}

	return minConflictos;
}

bool Sector::sectorResuelto() {
	return resuelto;
}

void Sector::resolver() {
	resuelto = true;
}

void Sector::otorgarVicepresidencia() {
	tieneVicepresidencia = true;
}

vector<vector<int> > Sector::getPosturasConflictos() {
	return opcionesPosturasConflictos;
}
