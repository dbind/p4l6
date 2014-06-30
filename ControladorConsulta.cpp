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

//void ControladorConsulta::removeReserva(FechaHora fechaConsulta, FechaHora fechaReserva, Usuario* Medico, Usuario* Paciente)
//{
//    int i = 0;
//    for(vector<Reserva*>::iterator it = reservas.begin(); it != reservas.end(); ++it)
//	{
//		Reserva* reserva = *it;
//                i++;
//
//		if (reserva->getPaciente() == Paciente && reserva->getMedico() == Medico && reserva->getFechaConsulta()==fechaConsulta && reserva->getFechaReserva()==fechaReserva)
//		{
//                        reservas.erase(reservas.begin()+i);
//                        
//		}
//	}
//}