#include "ConsultaComun.h"

#include "Diagnostico.h"
#include "Usuario.h"
#include "Fecha.h"
#include "ConsultaComun.h"


ConsultaComun::ConsultaComun(Usuario* medico, Usuario* paciente, Fecha consulta, Fecha reserva)
{
	_medico   = medico;
	_paciente = paciente;
	_consulta = consulta;
	_reserva  = reserva;

	_tipo = TipoConsulta::comun;
}


Fecha ConsultaComun::fechaReserva()
{
	return _reserva;
}
