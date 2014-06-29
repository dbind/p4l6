using namespace std;

#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdexcept>

#include "ControladorMenu.h"

#include "FabricaControladores.h"
#include "Usuario.h"

#include "ControladorComando.h"
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
	this->cSesion = FabricaControladores::instancia()->controladorSesion();
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
	try
	{
		this->login();

		// Verificar que la sesión fue creada, y dar la bienvenida al usuario ...
		Usuario* usuario = this->cSesion->usuarioActivo();
		cout << "Bienvenido, " << usuario->getNombre() << "\n\n";

		this->menuDeOpciones();
	}
	catch (int e)
	{
		if (e) throw e; // Excepciones para manejar (por el momento, ninguna)
		else return;    // El usuario eligió terminar el programa
	}
	catch (...)
	{
		cout << "Error irrecuperable: fallo desconocido en inicio de sesión";
		throw 1; // Unhandled exception
	}
}

/**
 * Precondición: no hay una sesión activa en el sistema
 * Postcondición: se inició una sesión (y se asignó a this->cSesion)
 */
void ControladorMenu::login()
{
	// Antes de iniciar sesión, cerrar sesión anterior si la hubiera
	this->cSesion->cerrarSesion();

	this->cSesion->iniciarSesion();
}

void ControladorMenu::logout()
{
	this->cSesion->cerrarSesion();
}

void ControladorMenu::menuDeOpciones()
{
	string opcion = "";
	
	// Lista de comandos que el usuario puede ejecutar según su(s) rol(es)
	vector<Comando> comandosUsuario;
	comandosUsuario = this->cSesion->usuarioActivo()->comandos();

	// Imprimir menú solo con las opciones válidas para el usuario actual
	this->imprimirMenu(comandosUsuario);

	while (true)
	{
		// El usuario elije una opcion
		cin >> opcion;

		this->interpretarOpcion(opcion, comandosUsuario);
	};
}

void ControladorMenu::interpretarOpcion(string opcion, vector<Comando> comandos)
{
		
	// Opción general: Salir
	if (opcion == "q")
	{
		cout << "\nThis is the end / my only friend / the end ...\n";
		throw 0;
	}
	// Opción general: Cambiar de usuario
	else if (opcion == "c")
	{
		this->login(); // Se cierra la sesión actual automáticamente

		// Actualizar la lista de comandos, para el nuevo usuario logueado
		comandos = this->cSesion->usuarioActivo()->comandos();
		this->imprimirMenu(this->cSesion->usuarioActivo()->comandos());
	}
	// Opción correcta, específica del rol del usuario: ejecutar acción
	else if (this->esValidaOpcion(opcion, comandos.size()))
	{
		int idx;
		istringstream(opcion) >> idx;

		this->ejecutar(comandos.at(idx-1));
		this->imprimirMenu(comandos);
	}
	// Opción incorrecta
	else
	{
		cout << "Opción inválida. Inténtelo nuevamente.\n";
	}
}

void ControladorMenu::imprimirMenu(vector<Comando> comandos)
{
	cout << "Elija una opción:\n\n";

	// Imprimir comandos pasados (parte personalizable del menú)
	vector<Comando>::iterator it = comandos.begin();

	for (int i=1; i<=comandos.size(); i++, it++)
	{
		Comando cmd = *it;
		cout << i << ". " << cmd.nombre() << "\n";
	}

	cout << "\nc. Cambiar de usuario\n";
	cout << "\nq. Salir\n";
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
		FabricaControladores::instancia()->controladorComando()->ejecutar(cmd);

		system("pause");
		cout << "\n";
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