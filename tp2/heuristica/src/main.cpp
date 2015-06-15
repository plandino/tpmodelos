#include <iostream>
#include <vector>
#include <algorithm>
#include "sector.h"

using namespace std;

int main(int argc, char* argv[]){

	const int CANTIDAD_CONFLICTOS = 3;
	const int CANTIDAD_SECTORES = 4;
	int vicepresidencia;

	/* Tengo todos los sectores
	 * 1: tengo el apoyo del sector
	 * 0: NO tengo el apoyo del sector 	*/
	vector<Sector*> sectores;

	// Si el conflicto esta en -1 significa que todavia no se resolvio una postura a tomar
	vector<int> conflictos;

	// Relleno el vector de los conflictos con -1, lo que indica que todavia no tome ninguna postura sobre los conflictos
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
	opcionUnoCorrienteHistorica.push_back(-1);	// En esta opcion no importa la ley de importaciones
	Sector *corrienteHistorica = new Sector(opcionUnoCorrienteHistorica);

	// Opcion 2
	vector<int> opcionDosCorrienteHistorica;
	opcionDosCorrienteHistorica.push_back(-1);	// En esta opcion no importa la huelga en Campana
	opcionDosCorrienteHistorica.push_back(1);	// Gana el apoyo si le da la banca de diputados a la corriente historica
	opcionDosCorrienteHistorica.push_back(-1);	// En esta opcion no importa la ley de importaciones
	corrienteHistorica->agregarOpcion(opcionDosCorrienteHistorica);

	// Opcion 3
	vector<int> opcionTresCorrienteHistorica;
	opcionTresCorrienteHistorica.push_back(-1);	// En esta opcion no importa la huelga en Campana
	opcionTresCorrienteHistorica.push_back(-1);	// En esta opcion no importa la banca de diputados
	opcionTresCorrienteHistorica.push_back(0);	// Gana el apoyo si no esta a favor de la ley de importaciones
	corrienteHistorica->agregarOpcion(opcionTresCorrienteHistorica);


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


	///////////// JUVENTUD ///////////////////////////////////////////////////////////////

	vector<int> posturasJuventud;
	posturasJuventud.push_back(0);	// Quiere la huelga de Campana para los empresarios
	posturasJuventud.push_back(0);	// Quiere las bancas de los diputados
	posturasJuventud.push_back(-1);	// No le importa la ley de importaciones
	Sector *juventud = new Sector(posturasJuventud);


	///////////// SINDICATOS ///////////////////////////////////////////////////////////////

	vector<int> posturasSindicatos;
	posturasSindicatos.push_back(1);	// Quieren la huelga de Campana para los sindicatos
	posturasSindicatos.push_back(-1);	// No les importa las bancas de diputados
	posturasSindicatos.push_back(0);	// No quieren la ley de importaciones
	Sector *sindicatos = new Sector(posturasSindicatos);


	///////////// TERMINE DE CARGAR LOS DATOS ///////////////////////////////////////////////////////////////

	// Agrego los sectores al vector que los contiene. Se deben ingresar en orden alfabetico.
	sectores.push_back(corrienteHistorica);
	sectores.push_back(empresarios);
	sectores.push_back(juventud);
	sectores.push_back(sindicatos);


	// Itero hasta resolver todos los sectores
	for (int p = 0; p < CANTIDAD_SECTORES; p++){
		int sectorAResolver = -1;
		int minimaCantidad = CANTIDAD_CONFLICTOS;

		// Reviso por todos los sectores sin analizar cual es el que requiere solucionar menor cantidad de conflictos para obtener su apoyo
		for(int i = 0; i < CANTIDAD_SECTORES; i++){
			// Como los ingrese por orden alfabetico y se quedara con el primero que encuentre con esa cantidad de conflictos, resuelve el caso del empate
			if( (sectores[i]->minimaCantidadDeConflictosASolucionar() < minimaCantidad) and ( !sectores[i]->sectorResuelto()) ){
				minimaCantidad = sectores[i]->minimaCantidadDeConflictosASolucionar();
				sectorAResolver = i;
			}
		}
		cout << "--------En esta vuelta voy a resolver el sector " << sectorAResolver << "--------" << endl;
		vector<vector<int> > opcionesPosturasSectorAResolver = sectores[sectorAResolver]->getPosturasConflictos();
		int cantidadOpciones = opcionesPosturasSectorAResolver.size();


		// Me fijo si con cuales opciones puedo obtener el apoyo primero que nada. Si hay 1 o no hay, no aplico el desempate.
		vector<int> opcionesPosibles;
		int opcionAResolver = -1;

		for (int i = 0; i < cantidadOpciones; i++){
			vector<int> posturaAResolverDelSector = opcionesPosturasSectorAResolver[i];
			vector<int> postura;
			bool opcionCompatible = true;
			for (int j = 0; j < CANTIDAD_CONFLICTOS; j++){
				if (conflictos[j] == -1){
					postura.push_back(posturaAResolverDelSector[j]);
				} else {
					if (posturaAResolverDelSector[j] == -1){
						postura.push_back(conflictos[j]);
					} else {
						if (conflictos[j] == posturaAResolverDelSector[j]){
							postura.push_back(conflictos[j]);
						} else {
							opcionCompatible = false;
						}
					}
				}
			}
			if (opcionCompatible and sectores[sectorAResolver]->getApoyo(postura)) {
				cout << "Puedo obtener el apoyo utilizando la opcion " << i << endl;
				opcionesPosibles.push_back(i);
			}
		}

		cout << "Por lo tanto, para resolver el sector " << sectorAResolver << " puedo hacerlo de " << opcionesPosibles.size() << " manera/s." << endl;


		// Con esto obtengo la opcion (de conflictos en los cuales tomar una decision) que me genera menor perdida de apoyo de otros sectores.
		// Solo lo aplico si necesito desempatar (Es decir, si hay mas de una opcion compatible).
		int minCantidadDeSectoresQueSePierdeElApoyo = CANTIDAD_CONFLICTOS;
		if (opcionesPosibles.size() > 1) {
			for(unsigned int j = 0; j < opcionesPosturasSectorAResolver.size(); j++){
				int cantidadDeSectoresQueSePierdeElApoyo = 0;
				for(int i = 0; i < CANTIDAD_SECTORES; i++){
					if (sectorAResolver == i) continue;
					if ( find(opcionesPosibles.begin(), opcionesPosibles.end(), j) == opcionesPosibles.end() ) continue;
					vector< vector<int> > opcionesPosturasSectorAComparar = sectores[i]->getPosturasConflictos();
					unsigned int cantidadDeOpcionesEnLasQueSePierdeElApoyo = 0;
					for(unsigned int l = 0; l < opcionesPosturasSectorAComparar.size(); l++){
						bool hayIncompatibilidad = false;
						for(int k = 0; k < CANTIDAD_CONFLICTOS; k++){
							if( (opcionesPosturasSectorAResolver[j][k] != opcionesPosturasSectorAComparar[l][k]) and (opcionesPosturasSectorAResolver[j][k] >= 0) and (opcionesPosturasSectorAComparar[l][k] >= 0) ){
								hayIncompatibilidad = true;
							}
						}
						if (hayIncompatibilidad) cantidadDeOpcionesEnLasQueSePierdeElApoyo++;
					}
					if ( cantidadDeOpcionesEnLasQueSePierdeElApoyo == opcionesPosturasSectorAComparar.size() ) cantidadDeSectoresQueSePierdeElApoyo++;
				}
				if( cantidadDeSectoresQueSePierdeElApoyo < minCantidadDeSectoresQueSePierdeElApoyo ){
					minCantidadDeSectoresQueSePierdeElApoyo = cantidadDeSectoresQueSePierdeElApoyo;
					opcionAResolver = j;
				}
			}
		} else {
			if (opcionesPosibles.size() == 1){
				opcionAResolver = opcionesPosibles[0];
			}
		}


		// Solo adopto una postura cuando puedo obtener su apoyo, sino no.
		if (opcionAResolver != -1){
			cout << "Para resolver a favor del sector " << sectorAResolver << " utilice la opcion " << opcionAResolver << endl << endl;
			vector<int> posturaAResolverDelSector = opcionesPosturasSectorAResolver[opcionAResolver];
			for (int i = 0; i < CANTIDAD_CONFLICTOS; i++){
				if ((conflictos[i] == -1) and (posturaAResolverDelSector[i] != -1)){
					conflictos[i] = posturaAResolverDelSector[i];
				}
			}
		} else {
			cout << "No pude resolver a favor del sector " << sectorAResolver << endl << endl;
		}
		sectores[sectorAResolver]->resolver();
	}

	// PASO 3
	for (int i = 0; i < CANTIDAD_CONFLICTOS; i++){
		if (conflictos[i] == -1) conflictos[i] = 1;
	}

	// PASO 4
	bool otorgueVicepresidencia = false;
	for (int i = 0; i < CANTIDAD_SECTORES; i++){
		if ( (not otorgueVicepresidencia) and (not sectores[i]->getApoyo(conflictos)) ){
			sectores[i]->otorgarVicepresidencia();
			otorgueVicepresidencia =  true;
			cout << "Le otorgue la vicepresidencia al sector " << i << endl;
		}
	}
	if (not otorgueVicepresidencia) sectores[0]->otorgarVicepresidencia();


	// Output del programa
	for (int i = 0; i < CANTIDAD_CONFLICTOS; i++){
		cout << "Posicion en el conflicto " << i << ": " << conflictos[i] << endl;
	}
	for (int i = 0; i < CANTIDAD_SECTORES; i++){
		cout << "Obtuve el apoyo del sector " << i << ": " << boolalpha << sectores[i]->getApoyo(conflictos) << endl;
	}


	for (int i = 0; i < CANTIDAD_SECTORES; i++){
		sectores.pop_back();
	}

	return 0;
}
