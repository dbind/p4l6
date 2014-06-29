#include <iostream>
using namespace std;

#include "ControladorConsulta.h"


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