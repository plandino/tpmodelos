#include <iostream>
#include <vector>
#include "sector.h"

using namespace std;

int main(int argc, char* argv[]){

	const int CANTIDAD_CONFLICTOS = 3;
	const int CANTIDAD_SECTORES = 4;
	int vicepresidencia;

	/* Tengo todos los sectores
	 * 1: tengo el apoyo del sector
	 * 0: NO tengo el apoyo del sector 	*/
	vector<Sector* > apoyoSectores;

	// Si el conflicto esta en -1 significa que todavia no se resolvio una postura a tomar
	vector<int> conflictos;

	// Relleno el vector de los conflictos con -1, indica que todavia no tome ninguna postura sobre los conflictos
	for(int i = 0; i < CANTIDAD_CONFLICTOS; i++){
		conflictos.push_back(-1);
	}

	/*
	 * 1° conflicto es la huelga de Campana
	 * 2° conflicto son las bancas de diputados
	 * 3° conflicto es la ley de importaciones
	 */

	/*
	 * Huelga de Campana: 	1 a favor de los sindicatos
	 * 						0 a favor de los empresarios
	 */

	/*
	 * Bancas de diputados: 1 a favor de los corriente historica
	 * 						0 a favor de la juventud
	 */

	/*
	 * Ley de importaciones: 1 a favor de la ley de importaciones
	 * 						 0 en contra de la ley de importaciones
	 */

	///////////// CORRIENTE HISTORICA ///////////////////////////////////////////////////////////////

	// Opcion 1
	vector<int> opcionUnoCorrienteHistorica;
	opcionUnoCorrienteHistorica.push_back(1);	// Gana el apoyo si apoya a los sindicatos en la huelga de Campana
	opcionUnoCorrienteHistorica.push_back(-1);	// En esta opcion no importa la banca de diputados
	opcionUnoCorrienteHistorica.push_back(-1);	// En esta opcion no importa la banca de diputados
	Sector *corrienteHistorica = new Sector(opcionUnoCorrienteHistorica);

	// Opcion 2
	vector<int> opcionDosCorrienteHistorica;
	opcionDosCorrienteHistorica.push_back(-1);	// En esta opcion no importa la banca de diputados
	opcionDosCorrienteHistorica.push_back(1);	// Gana el apoyo si le da la banca de diputados a la corriente historica
	opcionDosCorrienteHistorica.push_back(-1);	// En esta opcion no importa la banca de diputados
	corrienteHistorica->agregarOpcion(opcionDosCorrienteHistorica);

	// Opcion 3
	vector<int> opcionTresCorrienteHistorica;
	opcionTresCorrienteHistorica.push_back(-1);	// En esta opcion no importa la banca de diputados
	opcionTresCorrienteHistorica.push_back(-1);	// En esta opcion no importa la banca de diputados
	opcionTresCorrienteHistorica.push_back(0);	// Gana el apoyo si no esta a favor de la ley de importaciones
	corrienteHistorica->agregarOpcion(opcionTresCorrienteHistorica);


	///////////// JUVENTUD ///////////////////////////////////////////////////////////////

	vector<int> posturasJuventud;
	posturasJuventud.push_back(0);	// Quiere la huelga de Campana para los empresarios
	posturasJuventud.push_back(0);	// Quiere las bancas de los diputados
	posturasJuventud.push_back(-1);	// No le importa la ley de importaciones
	Sector *juventud = new Sector(posturasJuventud);


	///////////// EMPRESARIOS ///////////////////////////////////////////////////////////////

	// Opcion 1
	vector<int> opcionUnoEmpresarios;
	opcionUnoEmpresarios.push_back(0);	// Quieren la huelga de Campana para los empresarios
	opcionUnoEmpresarios.push_back(-1);	// No les importa las bancas de diputados
	opcionUnoEmpresarios.push_back(-1);	// En una opcion no les importa la ley de importaciones
	Sector *empresarios = new Sector(opcionUnoEmpresarios);

	// Opcion 2
	vector<int> opcionDosEmpresarios;
	opcionDosEmpresarios.push_back(-1);	// En una opcion no les importa la huelga de Campana
	opcionDosEmpresarios.push_back(-1);	// No les importa las bancas de diputados
	opcionDosEmpresarios.push_back(1);	// Quieren la ley de importaciones
	empresarios->agregarOpcion(opcionDosEmpresarios);

	///////////// SINDICATOS ///////////////////////////////////////////////////////////////

	vector<int> posturasSindicatos;
	posturasSindicatos.push_back(1);	// Quieren la huelga de Campana para los sindicatos
	posturasSindicatos.push_back(-1);	// No les importa las bancas de diputados
	posturasSindicatos.push_back(0);	// No quieren la ley de importaciones
	Sector *sindicatos = new Sector(posturasSindicatos);


	///////////// TERMINE DE CARGAR LOS DATOS ///////////////////////////////////////////////////////////////

	// Agrego los sectores al vector que los contiene
	apoyoSectores.push_back(corrienteHistorica);
	apoyoSectores.push_back(juventud);
	apoyoSectores.push_back(empresarios);
	apoyoSectores.push_back(sindicatos);

	int sectorAResolver = -1;
	int minimaCantidad = CANTIDAD_CONFLICTOS;

	// Reviso por todos los sectores sin analizar cual es el que requiere solucionar menor cantidad de conflictos para obtener su apoyo
	for(int i = 0; i < CANTIDAD_SECTORES; i++){
		if( (apoyoSectores[i]->minimaCantidadDeConflictosASolucionar() < minimaCantidad) and ( !apoyoSectores[i]->sectorResuelto()) ){
			minimaCantidad = apoyoSectores[i]->minimaCantidadDeConflictosASolucionar();
			sectorAResolver = i;
		}
	}

	int cantidadDeConflictosEncontrados = 0;
	int minCantidadConflictosEncontrados = CANTIDAD_CONFLICTOS;
	int opcionAResolver = -1;


	vector<vector<int> > posturasSectorAResolver = apoyoSectores[sectorAResolver]->getPosturasConflictos();

	// Con esto obtengo la opcion(de conflictos en los cuales tomar una decision) que me genera menor perdida de apoyo de otros sectores
	// No te recomiendo seguir el hilo de los for, pero si te animas, adelante


	// NO ESTOY SEGURO, LO HICE Y NO LO REVISE


	for(int i = 0; i != sectorAResolver and i < CANTIDAD_SECTORES; i++){
		vector<vector<int> > conflictosSector = apoyoSectores[i]->getPosturasConflictos();

		// Tengo que iterar comparando las distintas opciones para ganar el apoyo de un sector
		// Tengo mas opciones en la que voy a comparar
		if( posturasSectorAResolver.size() <= conflictosSector.size() ){
			for(unsigned int j = 0; j < posturasSectorAResolver.size(); j++){
				for(unsigned int l = 0; l < conflictosSector.size(); l++){
					for(int k = 0; k < CANTIDAD_CONFLICTOS; k++){
						if( (posturasSectorAResolver[j][k] != conflictosSector[l][k]) and (posturasSectorAResolver[j][k] >= 0) and (conflictosSector[l][k] >= 0) ){
							cantidadDeConflictosEncontrados++;
						}
					}
					if(cantidadDeConflictosEncontrados < minCantidadConflictosEncontrados ){
						minCantidadConflictosEncontrados = cantidadDeConflictosEncontrados;
						opcionAResolver = j;
					}
				}
			}

		} else {	// Tengo mas opciones en el sector en el que voy a resolver los conflictos
			for(unsigned int j = 0; j < conflictosSector.size(); j++){
				for(unsigned int l = 0; l < posturasSectorAResolver.size(); l++){
					for(int k = 0; k < CANTIDAD_CONFLICTOS; k++){
						if( (posturasSectorAResolver[l][k] != conflictosSector[j][k]) and (posturasSectorAResolver[l][k] >= 0) and (conflictosSector[j][k] >= 0) ){
							cantidadDeConflictosEncontrados++;
						}
					}
					if(cantidadDeConflictosEncontrados < minCantidadConflictosEncontrados ){
						minCantidadConflictosEncontrados = cantidadDeConflictosEncontrados;
						opcionAResolver = l;
					}
				}
			}
		}
	}


	return 0;
}
