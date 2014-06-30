#include <algorithm>

#include "Usuario.h"

#include "FabricaControladores.h"
#include "Consulta.h"

#include "Comando.h"
#include "ControladorSistema.h"


Usuario::Usuario(string ci, string nombre, string apellido,
                 Genero genero, Fecha fecha, Roles roles)
{
	_ci       = ci;
	_nombre   = nombre;
	_apellido = apellido;
	_genero   = genero;
	_fechaNac = fecha;
	_roles    = roles;

	_estado   = EstadoUsuario::nuevo;

	// Cargar lista de comandos habilitados (dado el o los roles del usuario)
	_comandos = FabricaControladores::instancia()->controladorComando()->comandos(_roles);

	_alta         = FabricaControladores::instancia()->controladorSistema()->getFechaDelSistema();
	_reactivacion = Fecha();
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

Genero Usuario::getGenero()
{
    return _genero;
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


Fecha Usuario::fechaAlta()
{
	return _alta;
}

Fecha Usuario::fechaReactivacion()
{
	return _reactivacion;
}


void Usuario::setNombre(string nombre)
{
    _nombre = nombre;
}

void Usuario::setApellido(string apellido)
{
    _apellido = apellido;
}

void Usuario::setGenero(Genero genero)
{
    _genero = genero;
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
	if (_estado == EstadoUsuario::inactivo)
	{
		_reactivacion = FabricaControladores::instancia()->controladorSistema()->getFechaDelSistema();
		_inasistencias = 0;
	}

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


void Usuario::setNotificador(IStrategyNotificaciones* notificador)
{
	_notificador = notificador;
}

void Usuario::agregarSuscriptor(Usuario* medico, Fecha fecha)
{
	if (find(_suscriptores.begin(), _suscriptores.end(), medico) != _suscriptores.end())
	{
		_suscriptores.insert(_suscriptores.begin(), medico);
	}
}

void Usuario::notificarSujeto(Consulta* consulta)
{
	vector<Usuario*>::iterator it;

    for (it=_suscriptores.begin(); it != _suscriptores.end(); ++it)
    {
		Usuario* observer = *it;
		observer->notificarObserver(consulta);
    }
}

void Usuario::notificarObserver(Consulta* consulta)
{
	_notificador->notificar(consulta);
}

vector<string> Usuario::notificaciones()
{
	vector<string> vacio = vector<string> {};

	return (_notificador == NULL) ? vacio : _notificador->notificaciones();
}


vector<Usuario*> Usuario::dadosDeAlta()
{
	return _dadosDeAlta;
}

vector<Usuario*> Usuario::reactivados()
{
	return _reactivados;
}

vector<Usuario*> Usuario::suscriptores()
{
	return _suscriptores;
}


int Usuario::edad()
{
    return 0; // TODO
}

int Usuario::inasistencias()
{
    return _inasistencias;
}

void Usuario::faltoConsulta()
{
	++_inasistencias;
	
	if (_inasistencias > MAX_INASISTENCIAS)
	{
		this->desactivar();
	}
}
