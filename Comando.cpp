#include "Comando.h"


Comando::Comando(string codigo, string nombre, vector<Rol> roles)
{
	this->_codigo = codigo;
	this->_nombre = nombre;
	this->_roles  = roles;
}

string Comando::codigo()
{
	return this->_codigo;
}

string Comando::nombre()
{
	return this->_nombre;
}

bool Comando::habilitadoPara(Rol rol)
{
	for(vector<Rol>::iterator it = _roles.begin(); it != _roles.end(); ++it)
	{
		if (*it == rol)
		{
			return true;
		}
	}

	return false;
}