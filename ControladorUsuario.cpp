#include <string>
#include <vector>
#include <iostream>
using namespace std;

#include "ControladorUsuario.h"

#include "ControladorSesion.h"
#include "FabricaControladores.h"
#include "Usuario.h"


const string MASTER_CI   = "0";
const string MASTER_PASS = "p4";


/**
 * Instanciación de singleton
 */
ControladorUsuario* ControladorUsuario::_instancia = 0;

ControladorUsuario* ControladorUsuario::instancia()
{
	if (_instancia == 0)
	{
		_instancia = new ControladorUsuario();
	}
	
	return _instancia;
}

ControladorUsuario::ControladorUsuario()
{
	this->crearMaster(MASTER_CI, MASTER_PASS, "Master");
}


/**
 * Crear Master (administrador por defecto)
 */
Usuario* ControladorUsuario::crearMaster(string ci, string pass, string nombre)
{
	vector<Rol> roles {Rol::master, Rol::admin};
	TipoSexo sexo = TipoSexo::indeterminado;
	Fecha fecha = Fecha(); // Fecha indefinida, no es relevante para Master

	// Crear el usuario por defecto con los datos recibidos
	Usuario* usuario = this->altaUsuario(ci, nombre, "", sexo, fecha, roles);
	usuario->cambiarPass(pass);
	usuario->activar();

	return usuario;
}


Usuario* ControladorUsuario::altaUsuario(string ci, string nombre, string apellido,
	                                     TipoSexo sexo, Fecha fecha, vector<Rol> roles)
{
	Usuario* usuario = new Usuario(ci, nombre, apellido, sexo, fecha, roles);

	this->usuarios.insert(this->usuarios.begin(), usuario);

	return usuario;
}

Usuario* ControladorUsuario::findUsuario(string ci)
{
	for(vector<Usuario*>::iterator it = usuarios.begin(); it != usuarios.end(); ++it)
	{
		Usuario* usuario = *it;

		if (usuario->getCi() == ci)
		{
			return usuario;
		}
	}

	return NULL;
}