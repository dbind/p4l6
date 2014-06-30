using namespace std;

#include <vector>

#include "ControladorConsulta.h"
#include "Reserva.h"


/**
 * Instanciación de singleton
 */
ControladorConsulta* ControladorConsulta::_instancia = 0;

ControladorConsulta* ControladorConsulta::instancia()
{
	if (_instancia == 0)
	{
		_instancia = new ControladorConsulta();
	}
	
	return _instancia;
}

vector<Reserva*> ControladorConsulta::getReservas()
{
    return reservas;
}

void ControladorConsulta::removeReserva(Usuario* medico, Usuario* paciente, Fecha fechaConsulta, Fecha fechaReserva)
{
    for(vector<Reserva*>::iterator it = reservas.begin(); it != reservas.end(); ++it)
	{
		Reserva* reserva = *it;

		if ((reserva->paciente()        == paciente)
		 && (reserva->medico()          == medico)
		 && (reserva->fechaConsulta()   == fechaConsulta
		 && (reserva->getFechaReserva() == fechaReserva))
		{
			reservas.erase(it);
		}
	}
}
