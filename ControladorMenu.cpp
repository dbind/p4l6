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
	this->cSesion = FabricaControladores::instancia()->controladorSesion();
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
	// Todos los comandos actualmente son reservados a usuarios autenticados
	try
	{
		this->login();

		// Verificar que la sesi�n fue creada, y dar la bienvenida al usuario ...
		Usuario* usuario = this->cSesion->usuarioActivo();
		cout << "Bienvenido, " << usuario->getNombre() << "\n\n";

		this->menuDeOpciones();
	}
	catch (int e)
	{
		if (e) throw e; // Excepciones para manejar (por el momento, ninguna)
		else return;    // El usuario eligi� terminar el programa
	}
	catch (...)
	{
		cout << "Error irrecuperable: fallo desconocido en inicio de sesi�n";
		throw 1; // Unhandled exception
	}
}

/**
 * Precondici�n: no hay una sesi�n activa en el sistema
 * Postcondici�n: se inici� una sesi�n (y se asign� a this->cSesion)
 */
void ControladorMenu::login()
{
	// Antes de iniciar sesi�n, cerrar sesi�n anterior si la hubiera
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
	
	// Lista de comandos que el usuario puede ejecutar seg�n su(s) rol(es)
	vector<Comando> comandosUsuario;
	comandosUsuario = this->cSesion->usuarioActivo()->comandos();

	// Imprimir men� solo con las opciones v�lidas para el usuario actual
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
		
	// Opci�n general: Salir
	if (opcion == "q")
	{
		cout << "\nThis is the end / my only friend / the end ...\n";
		throw 0;
	}
	// Opci�n general: Cambiar de usuario
	else if (opcion == "c")
	{
		this->login(); // Se cierra la sesi�n actual autom�ticamente

		// Actualizar la lista de comandos, para el nuevo usuario logueado
		comandos = this->cSesion->usuarioActivo()->comandos();
		this->imprimirMenu(this->cSesion->usuarioActivo()->comandos());
	}
	// Opci�n correcta, espec�fica del rol del usuario: ejecutar acci�n
	else if (this->esValidaOpcion(opcion, comandos.size()))
	{
		int idx;
		istringstream(opcion) >> idx;

		this->ejecutar(comandos.at(idx-1));
		this->imprimirMenu(comandos);
	}
	// Opci�n incorrecta
	else
	{
		cout << "Opci�n inv�lida. Int�ntelo nuevamente.\n";
	}
}

void ControladorMenu::imprimirMenu(vector<Comando> comandos)
{
	cout << "Elija una opci�n:\n\n";

	// Imprimir comandos pasados (parte personalizable del men�)
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
 * Las opciones v�lidas son: n�meros menores que 'max'.
 */
bool ControladorMenu::esValidaOpcion(string s_opcion, int max)
{
	char c_opcion[s_opcion.length()+1];
	int i_opcion;

	istringstream(s_opcion) >> i_opcion;  // Filtro solo n�meros
	sprintf(c_opcion, "%d", i_opcion);    // Casteo el n�mero a string

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