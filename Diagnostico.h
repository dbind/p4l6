#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H

using namespace std;

#include <string>
#include <vector>

#include "Representacion.h"
#include "TratamientoFarmacologico.h"
#include "TratamientoQuirurgico.h"


class Diagnostico
{

public:
	Diagnostico(Representacion, string descripcion);
	virtual ~Diagnostico(){};

	Representacion representacion();
	string descripcion();
	
	vector<TratamientoFarmacologico*> tratamientosFarmacologicos();

	void agregarTratamientoFarmacologico(TratamientoFarmacologico*);
	void agregarTratamientoQuirurgico(TratamientoQuirurgico*);

private:
	Representacion _representacion;
	string _descripcion;

	vector<TratamientoFarmacologico*> _tratamientosFarmacologicos {};
	vector<TratamientoQuirurgico*>    _tratamientosQuirurgicos {};

};

#endif // DIAGNOSTICO_H
