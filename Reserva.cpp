#include "Reserva.h"

#include "Usuario.h"
#include "Fecha.h"

Reserva::Reserva(Usuario* Medico, Usuario* Paciente, Fecha fechaConsulta, Fecha fechaReserva)
{
	_consulta = fechaConsulta;
	_reserva  = fechaReserva;
	_medico   = medico;
	_paciente = paciente;
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
    return reserva;
}
