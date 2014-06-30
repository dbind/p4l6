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
}
