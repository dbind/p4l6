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
	this->Fabrica  = FabricaControladores::instancia();
	this->cUsuario = Fabrica->controladorUsuario();
	this->cSesion  = Fabrica->controladorSesion();
}


void ControladorMenu::iniciar()
{
//	bool salir; // Flag para terminar el programa
//
//	// Cargar el controlador de Menú (interfaz del programa) e iniciar programa
//	while (!salir)
//	{
//		try
//		{
//			bool salir = Menu->iniciar();
//		}
//		catch (int e)
//		{
//			salir = false;
//		}
//	}

	// No es posible continuar sin iniciar sesión
	this->login();
	
	this->menuDeOpciones();
}

/**
 * Precondición: no hay una sesión activa en el sistema
 * Postcondición: se inició una sesión (y se asignó a this->cSesion)
 * 
 * Nota: aborta ejecución si ocurre una falla inesperada en el inicio de sesión
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

	// Verificar que la sesión fue creada, y dar la bienvenida al usuario
	try
	{
		Usuario* usuario = this->cSesion->usuarioActivo();
		cout << "Bienvenido, " << usuario->getNombre() << "\n\n";
	}
	catch (...)
	{
		cout << "Error irrecuperable: fallo desconocido en inicio de sesión";
	}
}

void ControladorMenu::logout()
{
	this->cSesion->cerrarSesion();
}


void ControladorMenu::menuDeOpciones()
{
	cout << "Y éste es el menú!";
}
