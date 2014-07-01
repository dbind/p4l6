using namespace std;

#include <vector>

#include "TratamientoFarmacologico.h"

#include "Farmaco.h"


TratamientoFarmacologico::TratamientoFarmacologico(vector<Farmaco*> farmacos, string descripcion)
{
	_farmacos     = farmacos;
	_descripcion = descripcion;
}

vector<Farmaco*> TratamientoFarmacologico::farmacos()
{
	return _farmacos;
}
