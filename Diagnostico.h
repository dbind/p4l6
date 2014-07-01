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
	Diagnostico(Representacion representacion, string descripcion);
	Diagnostico(Representacion representacion);
	virtual ~Diagnostico(){};

	Representacion representacion();
	string descripcion();

	vector<TratamientoFarmacologico*> tratamientosFarmacologicos();
	vector<TratamientoQuirurgico*> tratamientosQuirurgicos();

	void agregarTratamientoFarmacologico(TratamientoFarmacologico*);
	void agregarTratamientoQuirurgico(TratamientoQuirurgico*);

private:
	Representacion _representacion;
	string _descripcion;

	vector<TratamientoFarmacologico*> _tratamientosFarmacologicos {};
	vector<TratamientoQuirurgico*>    _tratamientosQuirurgicos {};

};

#endif // DIAGNOSTICO_H
