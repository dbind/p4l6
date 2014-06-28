#include "FabricaControladores.h"


/**
 * Instanciación de singleton
 */
FabricaControladores* FabricaControladores::_instancia = 0;

FabricaControladores* FabricaControladores::instancia()
{
	if (_instancia == 0)
	{
		_instancia = new FabricaControladores();
	}

	return _instancia;
}


ControladorMenu* FabricaControladores::controladorMenu()
{
	return ControladorMenu::instancia();
}

ControladorComando* FabricaControladores::controladorComando()
{
	return ControladorComando::instancia();
}


ControladorSesion* FabricaControladores::controladorSesion()
{
	return ControladorSesion::instancia();
}

ControladorUsuario* FabricaControladores::controladorUsuario()
{
	return ControladorUsuario::instancia();
}


ControladorFarmaco* FabricaControladores::controladorFarmaco()
{
	return ControladorFarmaco::instancia();
}

ControladorConsulta* FabricaControladores::controladorConsulta()
{
	return ControladorConsulta::instancia();
}

ControladorDiagnostico* FabricaControladores::controladorDiagnostico()
{
	return ControladorDiagnostico::instancia();
}