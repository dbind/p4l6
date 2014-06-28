using namespace std;

#include <iostream>
#include <vector>

#include "ControladorComando.h"

#include "Comando.h"
#include "Rol.h"


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


ControladorComando::ControladorComando()
{
	
	// Registrar comandos reconocidos por el controlador
	vector<Comando> c {};
	
	vector<Comando>::iterator pos = c.begin();

	c.insert(c.end(), Comando("cmd1", "Comando 1", vector<Rol> {Rol::admin}));
	c.insert(c.end(), Comando("cmd2", "Comando 2", vector<Rol> {Rol::admin, Rol::master}));
	c.insert(c.end(), Comando("cmd3", "Comando 3", vector<Rol> {Rol::master}));
	c.insert(c.end(), Comando("cmd4", "Comando 4", vector<Rol> {Rol::socio}));
	
	this->_comandos = c;	
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

void ControladorComando::ejecutar(Comando cmd)
{
	cout << "Ejecutando  " << cmd.codigo() << "... ";
	cout << "finalizado con éxito.\n";
}
