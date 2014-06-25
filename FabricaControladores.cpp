#include "FabricaControladores.h"

#include "ControladorSesion.h"
//#include "ControladorUsuario.h"
//#include "ControladorConsulta.h"
//#include "ControladorDiagnostico.h"


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


/**
 * Fábrica
 */
ControladorSesion* FabricaControladores::getControladorSesion()
{
	return ControladorSesion::instancia();
}

ControladorUsuario* FabricaControladores::getControladorUsuario()
{
	return ControladorUsuario::instancia();
}

ControladorConsulta* FabricaControladores::getControladorConsulta()
{
	return ControladorConsulta::instancia();
}

ControladorDiagnostico* FabricaControladores::getControladorDiagnostico()
{
	return ControladorDiagnostico::instancia();
}