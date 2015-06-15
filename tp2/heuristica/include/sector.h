#ifndef SECTOR_H_
#define SECTOR_H_

#include <vector>
using namespace std;

class Sector{

private:
	// Este vector indica que postura desea para cada conflicto, si la postura es -1 indica que no le importa el conflicto
	// Tengo varios opciones para ganar el apoyo del sector
	vector<vector<int> > opcionesPosturasConflictos;

	int cantidadDeConflictosTotales;
	bool resuelto;
	bool tieneVicepresidencia;

public:
	Sector(vector<int> posturasConflictos);
	~Sector();
	bool getApoyo(vector<int>& conflictos);
	void agregarOpcion(vector<int> posturaConflictos);

	// Devuelve la minima cantidad de conflictos a solucionar para ganar el apoyo de este sector
	int minimaCantidadDeConflictosASolucionar();

	bool sectorResuelto();
	void resolver();
	void otorgarVicepresidencia();

	vector<vector<int> > getPosturasConflictos();
};

#endif /* SECTOR_H_ */
