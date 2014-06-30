using namespace std;

#include <vector>

#include "ControladorSistema.h"

#include "FabricaControladores.h"
#include "Reserva.h"

/**
 * Instanciación de singleton
 */
ControladorSistema* ControladorSistema::_instancia = 0;

ControladorSistema* ControladorSistema::instancia()
{
	if (_instancia == 0)
	{
		_instancia = new ControladorSistema();
	}
	
	return _instancia;
}

ControladorSistema::ControladorSistema()
{
	_fecha = Fecha();
}


Fecha ControladorSistema::getFechaDelSistema()
{
	return _fecha;
}

void ControladorSistema::setFechaDelSistema(Fecha fecha)
{
	_fecha = fecha;

	// Triggers del cambio de hora
	IControladorConsulta* cConsulta = FabricaControladores::instancia()->controladorConsulta();

	vector<Reserva*> reservas = cConsulta->reservas();

	for(vector<Reserva*>::iterator it = reservas.begin(); it != reservas.end(); ++it)
	{
		Reserva* reserva = *it;

		if (reserva->fechaConsulta() < fecha && !reserva->asistio())
		{
			reserva->paciente()->faltoConsulta();
			cConsulta->removeReserva(reserva);
		}
	}
}

void ControladorSistema::reset()
{
	_fecha = Fecha();
}
