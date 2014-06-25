#include <algorithm>

#include "Usuario.h"


Usuario::Usuario(string ci, string nombre, string apellido,
                 TipoSexo sexo, Fecha fecha, vector<Rol> roles)
{
	this->ci       = ci;
	this->nombre   = nombre;
	this->apellido = apellido;
	this->sexo     = sexo;
	this->fechaNac = fecha;
	this->roles    = roles;

	this->estado   = EstadoUsuario::nuevo;
}


string Usuario::getCi()
{
    return this->ci;
}

string Usuario::getNombre()
{
    return this->nombre;
}

string Usuario::getApellido()
{
    return this->apellido;
}

TipoSexo Usuario::getSexo()
{
    return this->sexo;
}

Fecha Usuario::getFechaNac()
{
    return this->fechaNac;
}

void Usuario::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Usuario::setApellido(string apellido)
{
    this->apellido = apellido;
}

void Usuario::setSexo(TipoSexo sexo)
{
    this->sexo = sexo;
}

void Usuario::setFechaNac(Fecha fecha)
{
    this->fechaNac = fecha;
}


bool Usuario::esUn(Rol rol)
{
	vector<Rol>::iterator it = find(this->roles.begin(), this->roles.end(), rol);
	return it != this->roles.end();
}

bool Usuario::esNuevo()
{
	return this->estado == EstadoUsuario::nuevo;
}

bool Usuario::estaActivo()
{
	return this->estado == EstadoUsuario::activo;
}

bool Usuario::estaInactivo()
{
	return !this->estaActivo();
}

bool Usuario::validarPass(string pass)
{
    return this->pass == pass;
}


void Usuario::activar()
{
	this->estado = EstadoUsuario::activo;
}

void Usuario::desactivar()
{
	this->estado = EstadoUsuario::inactivo;
}

void Usuario::cambiarPass(string pass)
{
    this->pass = pass;
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
