#include <iostream>
using namespace std;

#include "ControladorDiagnostico.h"

/**
 * Testea la creación de la instancia del controlador
 */
void ControladorDiagnostico::testControlador()
{
	cout << "test";
}


/**
 * Instanciación de singleton
 */
ControladorDiagnostico* ControladorDiagnostico::_instancia = 0;

ControladorDiagnostico* ControladorDiagnostico::instancia()
{
	if (_instancia == 0)
	{
		_instancia = new ControladorDiagnostico();
	}
	
	return _instancia;
}
