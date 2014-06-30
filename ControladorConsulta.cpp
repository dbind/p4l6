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

vector<Reserva*> ControladorConsulta::reservas()
{
    return _reservas;
}

vector<Consulta> ControladorConsulta::consultas()
{
    return _consultas;
}

void ControladorConsulta::removeReserva(Usuario* medico, Usuario* paciente, Fecha fechaConsulta, Fecha fechaReserva)
{
//    for(vector<Reserva*>::iterator it = _reservas.begin(); it != _reservas.end(); ++it)
//	{
//		Reserva* reserva = *it;
//
//		if ((reserva->paciente()        == paciente)
//		 && (reserva->medico()          == medico)
//		 && (reserva->fechaConsulta()   == fechaConsulta
//		 && (reserva->getFechaReserva() == fechaReserva))
//		{
//			_reservas.erase(it);
//		}
//	}
}


void ControladorConsulta::reset()
{
	for(vector<Reserva*>::iterator it = _reservas.begin(); it != _reservas.end(); ++it)
	{
		delete *it;
	}

	_reservas = vector<Reserva*> {};
}
