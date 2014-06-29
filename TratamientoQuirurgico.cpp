using namespace std;

#include "TratamientoQuirurgico.h"

#include "Usuario.h"
#include "Fecha.h"


TratamientoQuirurgico::TratamientoQuirurgico(Usuario* medico, Fecha fecha, string descripcion)
{
	_medico      = medico;
	_fecha       = fecha;
	_descripcion = descripcion;
}

Usuario* TratamientoQuirurgico::medico()
{
	return _medico;
}

Fecha TratamientoQuirurgico::fecha()
{
	return _fecha;
}
