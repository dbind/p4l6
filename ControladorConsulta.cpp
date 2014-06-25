#include <iostream>
using namespace std;

#include "ControladorConsulta.h"

/**
 * Testea la creación de la instancia del controlador
 */
void ControladorConsulta::testControlador()
{
	cout << "test";
}


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
