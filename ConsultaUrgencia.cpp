using namespace std;

#include <string>

#include "ConsultaUrgencia.h"

#include "Diagnostico.h"
#include "Usuario.h"
#include "Fecha.h"


ConsultaUrgencia::ConsultaUrgencia(Usuario* medico, Usuario* paciente, Fecha consulta, string descripcion)
{
	_medico      = medico;
	_paciente    = paciente;
	_consulta    = consulta;
	_descripcion = descripcion;

	_tipo = TipoConsulta::urgencia;

	_paciente->registrarConsulta(this);
}


string ConsultaUrgencia::descripcion()
{
	return _descripcion;
}