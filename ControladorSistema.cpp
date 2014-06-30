using namespace std;

#include <vector>

#include "ControladorSistema.h"

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
}

void ControladorSistema::reset()
{
	_fecha = Fecha();
}
