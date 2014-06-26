#include <sstream>
#include <iostream>
using namespace std;

#include "ControladorMenu.h"
#include "FabricaControladores.h"
#include "Usuario.h"


/**
 * Instanciaci�n de singleton
 */
ControladorMenu* ControladorMenu::_instancia = 0;

ControladorMenu* ControladorMenu::instancia()
{
	if (_instancia == 0)
	{
		_instancia = new ControladorMenu();
	}
	
	return _instancia;
}

ControladorMenu::ControladorMenu()
{
	this->cSesion  = FabricaControladores::instancia()->controladorSesion();
	this->cUsuario = FabricaControladores::instancia()->controladorUsuario();
}

/**
 * Inicia el sistema:
 * 
 * � exige autenticaci�n al iniciar
 * � ofrece en todo momento posterior la posibilidad de cerrar sesi�n
 * � una vez autenticado, presenta opciones de acuerdo al perfil del usuario
 * 
 * Nota: aborta ejecuci�n si ocurre una falla inesperada en el inicio de sesi�n.
 */
void ControladorMenu::iniciar()
{
	// Todas las acciones son actualmente reservadas a usuarios autenticados
	this->login();

	// Verificar que la sesi�n fue creada, y dar la bienvenida al usuario ...
	try
	{
		Usuario* usuario = this->cSesion->usuarioActivo();
		cout << "Bienvenido, " << usuario->getNombre() << "\n\n";
	}
	// ... o abortar si fall� el login
	catch (...)
	{
		cout << "Error irrecuperable: fallo desconocido en inicio de sesi�n";
		throw 1;
	}

	this->menuDeOpciones();
}

/**
 * Precondici�n: no hay una sesi�n activa en el sistema
 * Postcondici�n: se inici� una sesi�n (y se asign� a this->cSesion)
 */
void ControladorMenu::login()
{
	// Antes de iniciar sesi�n, cerarr sesi�n anterior si la hubiera
	this->cSesion->cerrarSesion();

	// Permitir intentos ilimitados de login, hasta que ponga datos correctos
	while (!this->cSesion->sesionIniciada())
	{
		try
		{
			this->cSesion->iniciarSesion();
		}
		catch (int e)
		{
			// e == 1: ci incorrecta | e == 0: usuario cancel�
			// Por el momento, manejamos la excepci�n indistintamente
		}
	}
}

void ControladorMenu::logout()
{
	this->cSesion->cerrarSesion();
}


void ControladorMenu::menuDeOpciones()
{
	string opcion = "";

	while (true)
	{
		cout << "Elija una opci�n:\n\n";

		// Listar acciones (dependientes y no del estado y/o rol del usuario)
		vector<string> acciones = this->cUsuario->getAccionesHabilitadas();
		vector<string>::iterator it = acciones.begin();

		for (int i=1; i<=acciones.size(); i++, it++)
		{
			cout << i << ". " << (*it) << "\n";
		}

		cout << "\nc. Cambiar de usuario\n";
		cout << "\nq. Salir\n";

		cin >> opcion;
		
		// Cambiar de usuario
		if (opcion == "c")
		{
			this->login(); // Se cierra la sesi�n actual primero
		}
		// Salir
		if (opcion == "q")
		{
			cout << "\nThis is the end / my only friend / the end ...\n";
			return;
		}
		// Opci�n incorrecta
		else if (!this->esValidaOpcion(opcion, acciones.size()))
		{
			cout << "Opci�n inv�lida. Int�ntelo nuevamente.\n";
		}
		// Opci�n correcta: ejecutar acci�n
		else
		{
			int o;
			istringstream(opcion) >> o;
			cout << "Seleccionaste " << opcion << " (" << acciones.at(o) << ")\n";
//			this->ejectuar(acciones);
		}
	};
}

/**
 * Las opciones v�lidas son: n�meros menores que 'max'.
 */
bool ControladorMenu::esValidaOpcion(string opcion, int max)
{
	char opcion_limpia[opcion.length()+1];
	int opcion_numeros;

	istringstream(opcion) >> opcion_numeros;      // Filtro solo n�meros
	sprintf(opcion_limpia, "%d", opcion_numeros); // Casteo el n�mero a string

	return (opcion == opcion_limpia && opcion.length() <= max);
}
