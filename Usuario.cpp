#include <algorithm>

#include "Usuario.h"

#include "FabricaControladores.h"
#include "Comando.h"


Usuario::Usuario(string ci, string nombre, string apellido,
                 Genero sexo, Fecha fecha, Roles roles)
{
	_ci       = ci;
	_nombre   = nombre;
	_apellido = apellido;
	_sexo     = sexo;
	_fechaNac = fecha;
	_roles    = roles;

	_estado   = EstadoUsuario::nuevo;

	// Cargar lista de comandos habilitados (dado el o los roles del usuario)
	_comandos = FabricaControladores::instancia()->controladorComando()->comandos(_roles);
}


string Usuario::getCi()
{
    return _ci;
}

string Usuario::getNombre()
{
    return _nombre;
}

string Usuario::getApellido()
{
    return _apellido;
}

Genero Usuario::getSexo()
{
    return _sexo;
}

Fecha Usuario::getFechaNac()
{
    return _fechaNac;
}

Roles Usuario::roles()
{
    return _roles;
}

vector<Comando> Usuario::comandos()
{
    return _comandos;
}


void Usuario::setNombre(string nombre)
{
    _nombre = nombre;
}

void Usuario::setApellido(string apellido)
{
    _apellido = apellido;
}

void Usuario::setSexo(Genero sexo)
{
    _sexo = sexo;
}

void Usuario::setFechaNac(Fecha fecha)
{
    _fechaNac = fecha;
}


bool Usuario::esUn(Rol rol)
{
	return find(_roles.begin(), _roles.end(), rol) != _roles.end();
}

bool Usuario::esNuevo()
{
	return _estado == EstadoUsuario::nuevo;
}

bool Usuario::estaActivo()
{
	return _estado == EstadoUsuario::activo;
}

bool Usuario::estaInactivo()
{
	return _estado != EstadoUsuario::activo;
}

bool Usuario::validarPass(string pass)
{
    return _pass == pass;
}


void Usuario::activar()
{
	_estado = EstadoUsuario::activo;
}

void Usuario::desactivar()
{
	_estado = EstadoUsuario::inactivo;
}

void Usuario::cambiarPass(string pass)
{
    _pass = pass;
}

void Usuario::agregarDadoDeAlta(Usuario* usuario)
{
	if (find(_dadosDeAlta.begin(), _dadosDeAlta.end(), usuario) != _dadosDeAlta.end())
	{
		_dadosDeAlta.insert(_dadosDeAlta.begin(), usuario);
	}
}

void Usuario::agregarReactivado(Usuario* usuario)
{
	if (find(_reactivados.begin(), _reactivados.end(), usuario) != _reactivados.end())
	{
		_reactivados.insert(_reactivados.begin(), usuario);
	}
}


int Usuario::calcularEdad()
{
    return 0; // TODO
}

int Usuario::calcularInasistencias()
{
    return 0; // TODO
}

//vector<Consulta> Usuario::listarConsultas()
//{
//    // TODO
//}
//
//vector<Consulta> Usuario::listarConsultasComunes()
//{
//    // TODO
//}
//
//vector<Consulta> Usuario::getConsultasAtendidas()
//{
//    // TODO
//}
//
//Consulta Usuario::obtenerConsulta()
//{
//    // TODO
//}
