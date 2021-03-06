using namespace std;

#include <iostream>
#include <vector>

#include "ControladorConsulta.h"
#include "Reserva.h"
#include "Consulta.h"
#include "Usuario.h"


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

void ControladorConsulta::altaReserva(Reserva* reserva)
{
	_reservas.push_back(reserva);
}

void ControladorConsulta::altaConsulta(Consulta* consulta)
{
	_consultas.push_back(consulta);
}

vector<Consulta*> ControladorConsulta::consultas()
{
    return _consultas;
}

vector<Reserva*> ControladorConsulta::reservas()
{
    return _reservas;
}


void ControladorConsulta::removeReserva(Reserva* reserva)
{
    for(vector<Reserva*>::iterator it=_reservas.begin(); it != _reservas.end(); ++it)
	{
		if ((reserva->medico()        == (*it)->medico())
		 && (reserva->paciente()      == (*it)->paciente())
		 && (reserva->fechaReserva()  == (*it)->fechaReserva())
		 && (reserva->fechaConsulta() == (*it)->fechaConsulta()))
		{
			_reservas.erase(it);
			return;
		}
	}
}


vector<Reserva*> ControladorConsulta::listarReservasDia(Fecha fecha)
{
	vector<Reserva*> reservasDia;
		
    for(vector<Reserva*>::iterator it = _reservas.begin(); it != _reservas.end(); ++it)
	{
		Reserva* reserva = *it;

		if (reserva->fechaReserva() == fecha)
		{
			reservasDia.push_back(reserva);
		}
	}

	return reservasDia;
}

vector<Consulta*> ControladorConsulta::listarConsultasDia(Fecha fecha)
{
	vector<Consulta*> consultasDia;
		
    for(vector<Consulta*>::iterator it = _consultas.begin(); it != _consultas.end(); ++it)
	{
		Consulta* consulta = *it;

		if (consulta->fechaConsulta() == fecha)
		{
			consultasDia.push_back(consulta);
		}
	}

	return consultasDia;
}


void ControladorConsulta::reset()
{
	for(vector<Reserva*>::iterator it = _reservas.begin(); it != _reservas.end(); ++it)
	{
		delete *it;
	}

	_reservas = vector<Reserva*> {};
}
