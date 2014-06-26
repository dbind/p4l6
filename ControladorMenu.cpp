#include <sstream>
#include <iostream>
using namespace std;

#include "ControladorMenu.h"
#include "FabricaControladores.h"
#include "Usuario.h"


/**
 * Instanciación de singleton
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
 * · exige autenticación al iniciar
 * · ofrece en todo momento posterior la posibilidad de cerrar sesión
 * · una vez autenticado, presenta opciones de acuerdo al perfil del usuario
 * 
 * Nota: aborta ejecución si ocurre una falla inesperada en el inicio de sesión.
 */
void ControladorMenu::iniciar()
{
	// Todas las acciones son actualmente reservadas a usuarios autenticados
	this->login();

	// Verificar que la sesión fue creada, y dar la bienvenida al usuario ...
	try
	{
		Usuario* usuario = this->cSesion->usuarioActivo();
		cout << "Bienvenido, " << usuario->getNombre() << "\n\n";
	}
	// ... o abortar si falló el login
	catch (...)
	{
		cout << "Error irrecuperable: fallo desconocido en inicio de sesión";
		throw 1;
	}

	this->menuDeOpciones();
}

/**
 * Precondición: no hay una sesión activa en el sistema
 * Postcondición: se inició una sesión (y se asignó a this->cSesion)
 */
void ControladorMenu::login()
{
	// Antes de iniciar sesión, cerarr sesión anterior si la hubiera
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
			// e == 1: ci incorrecta | e == 0: usuario canceló
			// Por el momento, manejamos la excepción indistintamente
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
		cout << "Elija una opción:\n\n";

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
			this->login(); // Se cierra la sesión actual primero
		}
		// Salir
		if (opcion == "q")
		{
			cout << "\nThis is the end / my only friend / the end ...\n";
			return;
		}
		// Opción incorrecta
		else if (!this->esValidaOpcion(opcion, acciones.size()))
		{
			cout << "Opción inválida. Inténtelo nuevamente.\n";
		}
		// Opción correcta: ejecutar acción
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
 * Las opciones válidas son: números menores que 'max'.
 */
bool ControladorMenu::esValidaOpcion(string opcion, int max)
{
	char opcion_limpia[opcion.length()+1];
	int opcion_numeros;

	istringstream(opcion) >> opcion_numeros;      // Filtro solo números
	sprintf(opcion_limpia, "%d", opcion_numeros); // Casteo el número a string

	return (opcion == opcion_limpia && opcion.length() <= max);
}
