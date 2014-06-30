using namespace std;

#include <iostream>
#include <sstream>

#include "StrategyNotificaciones.h"

#include "Usuario.h"
#include "Consulta.h"


void StrategyNotificaciones::notificar(Consulta* consulta)
{
	stringstream notificacion;

	string tipoConsulta = (consulta->tipo() == TipoConsulta::comun) ? "COMUN" : "URGENCIA";

	Usuario* medico   = consulta->medico();
	Usuario* paciente = consulta->paciente();

	notificacion << "Paciente diagnosticado: " << paciente->getNombre() << " " << paciente->getApellido() << endl
	             << "Médico notificado: " << medico->getNombre() << " " << medico->getApellido() << endl
	             << "Tipo de consulta: " << tipoConsulta << endl
	             << "Hora de consulta: " << consulta->fechaConsulta() << endl;

	_notificaciones.push_back(notificacion.str());
}

vector<string> StrategyNotificaciones::notificaciones()
{
	return _notificaciones;
}