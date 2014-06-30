using namespace std;

#include "Diagnostico.h"

#include "Representacion.h"


Diagnostico::Diagnostico(Representacion representacion, string descripcion)
{
	_representacion = representacion;
	_descripcion = descripcion;
}

Diagnostico(Representacion representacion)
{
    _representacion = representacion;
    _descripcion = "No hay descipcion"
}

Representacion Diagnostico::representacion()
{
	return _representacion;
}

string Diagnostico::descripcion()
{
	return _descripcion;
}

void Diagnostico::agregarTratamientoFarmacologico(TratamientoFarmacologico* tratamiento)
{
	_tratamientosFarmacologicos.insert(_tratamientosFarmacologicos.begin(), tratamiento);
}

void Diagnostico::agregarTratamientoQuirurgico(TratamientoQuirurgico* tratamiento)
{
	_tratamientosQuirurgicos.insert(_tratamientosQuirurgicos.begin(), tratamiento);
}
