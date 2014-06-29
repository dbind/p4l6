using namespace std;

#include "TratamientoFarmacologico.h"

#include "Farmaco.h"


TratamientoFarmacologico::TratamientoFarmacologico(Farmaco* farmaco, string descripcion)
{
	_farmaco     = farmaco;
	_descripcion = descripcion;
}

Farmaco* TratamientoFarmacologico::farmaco()
{
	return _farmaco;
}
