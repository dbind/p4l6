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
	this->Fabrica = FabricaControladores::instancia();

	this->cUsuario = this->Fabrica->controladorUsuario();
	this->cSesion  = this->Fabrica->controladorSesion();
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
	cout << "Elija una opción para continuar:\n\n";

	// Listar acciones específicas dependientes del estado y/o tipo de usuario
	vector<string> acciones = this->cUsuario->getAccionesHabilitadas();
	vector<string>::iterator it = acciones.begin();

	for (int i=1; i<=acciones.size(); i++, it++)
	{
		cout << i << ". " << (*it) << "\n";
	}

	cout << "\nq. Cerrar sesión:\n";
}
