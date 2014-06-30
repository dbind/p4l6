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


vector<Consulta*> ControladorConsulta::consultas()
{
    return _consultas;
}

vector<Reserva*> ControladorConsulta::reservas()
{
    return _reservas;
}


void ControladorConsulta::removeReserva(Usuario* medico, Usuario* paciente, Fecha fechaConsulta, Fecha fechaReserva)
{
    for(vector<Reserva*>::iterator it = _reservas.begin(); it != _reservas.end(); ++it)
	{
		Reserva* reserva = *it;

		if ((reserva->medico()        == medico)
		 && (reserva->paciente()      == paciente)
		 && (reserva->fechaConsulta() == fechaConsulta)
		 && (reserva->fechaReserva()  == fechaReserva))
		{
			delete reserva;
			_reservas.erase(it);
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
