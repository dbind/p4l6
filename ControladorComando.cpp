using namespace std;

#include <iostream>
#include <vector>

#include "ControladorComando.h"

#include "Comando.h"
#include "Rol.h"


ControladorComando::ControladorComando()
{
	// Registrar comandos reconocidos por el controlador
	this->_comandos = vector<Comando> {};

	// Agregar nuevos comandos: this->agregar(codigo, comando, roles);
	this->agregar("cmd1", "Comando 1", vector<Rol> {Rol::admin});
	this->agregar("cmd2", "Comando 2", vector<Rol> {Rol::admin, Rol::master});
	this->agregar("cmd3", "Comando 3", vector<Rol> {Rol::master});
	this->agregar("cmd4", "Comando 4", vector<Rol> {Rol::socio, Rol::medico});
	this->agregar("cmd5", "Comando 5", vector<Rol> {Rol::socio});
}

void ControladorComando::ejecutar(Comando cmd)
{
	string opcion = cmd.codigo();

	if (opcion == "cmd1")
	{
		cout << "Ejecuté cmd1!\n";
	}
	
	else if (opcion == "cmd2")
	{
		cout << "Ejecuté cmd2!\n";
	}
	
//	else if (opcion == "")
//	{
//		cout << "Ejecuto XXX... ";
//	}
	
	else
	{
		cout << "No hay manejador para la opción seleccionada\n";
	}
}


/******************************************************************************/
/******************************** I N T E R N O *******************************/
/******************************************************************************/

/**
 * Instanciación de singleton
 */
ControladorComando* ControladorComando::_instancia = 0;

ControladorComando* ControladorComando::instancia()
{
	if (_instancia == 0)
	{
		_instancia = new ControladorComando();
	}
	
	return _instancia;
}

vector<Comando> ControladorComando::comandos(vector<Rol> roles)
{
	vector<Comando> comandos = _comandos;

	// Filtrar solo los comandos que se pueden ejecutar con los roles dados
	vector<Comando>::iterator it = comandos.begin();

    while (it != comandos.end())
    {
		Comando cmd = *it;
		cmd.habilitadoPara(roles) ? ++it : comandos.erase(it);
    }

	return comandos;
}


/******************************************************************************/
/******************************** P R I V A T E *******************************/
/******************************************************************************/

void ControladorComando::agregar(string codigo, string nombre, vector<Rol> roles)
{
	this->_comandos.insert(this->_comandos.end(), Comando(codigo, nombre, roles));
}
