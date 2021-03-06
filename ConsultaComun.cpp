#include "ConsultaComun.h"

#include "Diagnostico.h"
#include "Usuario.h"
#include "Fecha.h"
#include "ConsultaComun.h"
#include "FabricaControladores.h"


ConsultaComun::ConsultaComun(Usuario* medico, Usuario* paciente, Fecha consulta, Reserva* reserva)
{
	_medico   = medico;
	_paciente = paciente;
	_consulta = consulta;
	_reserva  = reserva;

	_tipo = TipoConsulta::comun;

	_paciente->registrarConsulta(this);
}

ConsultaComun::ConsultaComun(Usuario* medico, Usuario* paciente, Fecha consulta, Fecha reserva)
{
	_medico   = medico;
	_paciente = paciente;
	_consulta = consulta;

	_tipo = TipoConsulta::comun;

	_reserva = new Reserva(medico, paciente, consulta, reserva);
	FabricaControladores::instancia()->controladorConsulta()->altaReserva(_reserva);

	_paciente->registrarConsulta(this);
}

Reserva* ConsultaComun::reserva()
{
	return _reserva;
}
