using namespace std;

#include <sstream>
#include <iostream>
#include <stdexcept>

#include "ControladorMenu.h"
#include "FabricaControladores.h"
#include "Usuario.h"
#include "Comando.h"


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
	// Todos los comandos actualmente son reservados a usuarios autenticados
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

		// Pedir todos los comandos existentes y filtrar sólo los permitidos
		vector<Comando> comandos = this->cSesion->usuarioActivo()->comandos();
		vector<Comando>::iterator it = comandos.begin();

		for (int i=1; i<=comandos.size(); i++, it++)
		{
			Comando cmd = *it;
			cout << i << ". " << cmd.codigo() << "\n";
		}

		cout << "\nc. Cambiar de usuario\n";
		cout << "\nq. Salir\n";

		cin >> opcion;
		
		// Cambiar de usuario
		if (opcion == "c")
		{
			this->login(); // Se cierra la sesión actual automáticamente
		}
		// Salir
		if (opcion == "q")
		{
			cout << "\nThis is the end / my only friend / the end ...\n";
			return;
		}
		// Opción incorrecta
		else if (!this->esValidaOpcion(opcion, comandos.size()))
		{
			cout << "Opción inválida. Inténtelo nuevamente.\n";
		}
		// Opción correcta: ejecutar acción
		else
		{
			int idx;
			istringstream(opcion) >> idx;

			this->ejecutar(comandos.at(idx-1));
		}
	};
}

/**
 * Las opciones válidas son: números menores que 'max'.
 */
bool ControladorMenu::esValidaOpcion(string s_opcion, int max)
{
	char c_opcion[s_opcion.length()+1];
	int i_opcion;

	istringstream(s_opcion) >> i_opcion;  // Filtro solo números
	sprintf(c_opcion, "%d", i_opcion);    // Casteo el número a string

	return (s_opcion == c_opcion && i_opcion > 0 && i_opcion <= max);
}

void ControladorMenu::ejecutar(Comando cmd)
{	
	try
	{
		cout << "Ejecutando  " << cmd.codigo() << "... ";

		this->cUsuario->ejecutar(cmd);

		cout << "finalizado con éxito.\n";
	}
	catch (runtime_error& rt)
	{
		cout << rt.what() << '\n';
	}
	catch (logic_error& lg)
	{
		cout << lg.what() << '\n';
	}
	catch (exception& ex)
	{
		cout << ex.what() << '\n';
	}
}