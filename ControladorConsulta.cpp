using namespace std;

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
	_reservas.insert(_reservas.begin(), reserva);
}

void ControladorConsulta::altaConsulta(Consulta* consulta)
{
	_consultas.insert(_consultas.begin(), consulta);
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
    for(vector<Reserva*>::iterator it = _reservas.begin(); it != _reservas.end(); ++it)
	{
		if (reserva = (*it))
		{
			_reservas.erase(it);
			delete reserva;
		}
	}
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
