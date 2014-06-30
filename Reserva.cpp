#include "Reserva.h"

#include "Usuario.h"
#include "Fecha.h"

Reserva::Reserva(Usuario* medico, Usuario* paciente, Fecha fechaConsulta, Fecha fechaReserva)
{
	_medico   = medico;
	_paciente = paciente;
	_consulta = fechaConsulta;
	_reserva  = fechaReserva;
}

Usuario* Reserva::paciente()
{
    return _paciente;
}

Usuario* Reserva::medico()
{
    return _medico;
}
        
Fecha Reserva::fechaConsulta()
{
    return _consulta;
}
        
Fecha Reserva::fechaReserva()
{
    return _reserva;
}

bool Reserva::asistio()
{
	return _asistio;
}

void Reserva::asistir()
{
	_asistio = true;
}
