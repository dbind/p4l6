using namespace std;

#include <iostream>
#include <vector>

#include "ControladorComando.h"

#include "Comando.h"
#include "Rol.h"

// Shortcut por practicidad
typedef vector<Rol> Roles;

/**
 * Agregar nuevos comandos: this->agregar("codigo", "nombre", Roles{lista})
 */
void ControladorComando::registrarComandos()
{
	// Casos de uso
	this->agregar("alta_usuario", "Alta/Reactivación de Usuario",
	               Roles{Rol::admin});
	this->agregar("alta_representacion", "Alta Representación de Diagnóstico",
	               Roles{Rol::admin});
	this->agregar("reserva_consulta", "Reserva Consulta",
	               Roles{Rol::admin});
	this->agregar("registro_consulta", "Registro Consulta",
	               Roles{Rol::admin});
	this->agregar("alta_diagnosticos", "Alta Diagnósticos de Consulta",
	               Roles{Rol::admin});
	this->agregar("alta_medicamento", "Alta Medicamento",
	               Roles{Rol::admin});
	this->agregar("devolucion_consulta", "Devolución de Consulta",
	               Roles{Rol::admin});
	this->agregar("listar_usuarios", "Usuarios Dados de Alta",
	               Roles{Rol::admin});
	this->agregar("listar_representaciones", "Listar Representaciones de Diagnósticos",
	               Roles{Rol::admin});
	this->agregar("ver_historial", "Obtener Historial Paciente",
	               Roles{Rol::admin});
	this->agregar("notificar_medico", "Notificar Médicos",
	               Roles{Rol::admin});

	// Solo para Master (admin por defecto)
	this->agregar("set_time", "Modificar fecha del sistema",
	              Roles{Rol::master});
	this->agregar("load_test_data", "Cargar datos de prueba",
	              Roles{Rol::master});

	// Opciones específicas de la implementación (e.g. ver hora)
	this->agregar("get_time", "Consultar fecha del sistema",
	              Roles{Rol::admin, Rol::medico, Rol::socio});
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
		cout << "No hay manejador para la opción seleccionada (" << cmd.nombre() << ")\n";
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

ControladorComando::ControladorComando()
{
	// Registrar comandos reconocidos por el controlador
	this->_comandos = vector<Comando> {};
	this->registrarComandos();
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
