#include <algorithm>

#include "Usuario.h"

#include "FabricaControladores.h"
#include "Comando.h"


Usuario::Usuario(string ci, string nombre, string apellido,
                 TipoSexo sexo, Fecha fecha, vector<Rol> roles)
{
	_ci       = ci;
	_nombre   = nombre;
	_apellido = apellido;
	_sexo     = sexo;
	_fechaNac = fecha;
	_roles    = roles;

	_estado   = EstadoUsuario::nuevo;
}

void Usuario::cargarComandos()
{
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

TipoSexo Usuario::getSexo()
{
    return _sexo;
}

Fecha Usuario::getFechaNac()
{
    return _fechaNac;
}

vector<Rol> Usuario::roles()
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

void Usuario::setSexo(TipoSexo sexo)
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
