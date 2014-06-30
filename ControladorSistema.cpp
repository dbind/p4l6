using namespace std;

#include <vector>

#include "ControladorSistema.h"

/**
 * Instanciaci�n de singleton
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
}
