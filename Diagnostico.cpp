#include "Diagnostico.h"

//#include "Consulta.h"
//#include "Representacion.h"


Diagnostico::Diagnostico(Consulta* consulta, Representacion* representacion, string descripcion)
{
	_consulta = consulta;
	_representacion = representacion;
	_descripcion = descripcion;
}

Consulta* Diagnostico::consulta()
{
	return _consulta;
}

Representacion* Diagnostico::representacion()
{
	return _representacion;
}

string Diagnostico::descripcion()
{
	return _descripcion;
}
