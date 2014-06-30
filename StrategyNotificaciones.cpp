using namespace std;

#include <iostream>

#include "StrategyNotificaciones.h"

#include "Usuario.h"
#include "Consulta.h"


void StrategyNotificaciones::notificar(Consulta* consulta)
{
	string tipoConsulta = (consulta->tipo() == TipoConsulta::comun) ? "COMUN" : "URGENCIA";

	Usuario* medico   = consulta->medico();
	Usuario* paciente = consulta->paciente();

	cout << "Paciente diagnosticado: " << paciente->getNombre() << " " << paciente->getApellido() << endl
	     << "Médico notificado: " << medico->getNombre() << " " << medico->getApellido() << endl
	     << "Tipo de consulta: " << tipoConsulta << endl
	     << "Hora de consulta: " << consulta->fechaConsulta() << endl;
}
