using namespace std;

#include <iostream>
#include <vector>

#include "ControladorComando.h"

#include "Comando.h"
#include "Rol.h"

#include "ComandosUsuario.h"
#include "ComandosDiagnostico.h"
#include "ComandosConsulta.h"
#include "ComandosFarmaco.h"
#include "ComandosNotificacion.h"
#include "ComandosSistema.h"


/**
 * Agregar nuevos comandos: agregar("codigo", "nombre", Roles{lista})
 */
void ControladorComando::registrarComandos()
{
	// Casos de uso: Usuarios
	agregar("alta_usuario", "Alta/Reactivación de Usuario",
	        Roles{Rol::admin});
	agregar("altas_reactivaciones", "Usuarios Dados de Alta o Reactivados",
	        Roles{Rol::admin});
	agregar("ver_historial", "Obtener Historial Paciente",
	        Roles{Rol::medico});

	// Casos de uso: Diagnósticos
	agregar("alta_representacion", "Alta Representación de Diagnóstico",
	        Roles{Rol::admin});
	agregar("listar_representaciones", "Listar Representaciones de Diagnósticos",
	        Roles{Rol::admin, Rol::medico});

	// Casos de uso: Consultas
	agregar("reserva_consulta", "Reserva Consulta",
	        Roles{Rol::socio});
	agregar("devolucion_reserva", "Devolución de Reserva",
	        Roles{Rol::socio});
	agregar("registro_consulta", "Registro Consulta",
	        Roles{Rol::admin});
	agregar("alta_diagnosticos", "Alta Diagnósticos de Consulta",
	        Roles{Rol::medico});

	// Casos de uso: Medicamentos
	agregar("alta_farmaco", "Alta Medicamento",
	        Roles{Rol::admin});

	// Casos de uso: Notificaciones
	agregar("suscribirse_paciente", "Subscribirse a Notificaciones del Paciente",
	        Roles{Rol::admin});
	agregar("notificar_medicos", "Notificar Médicos",
	        Roles{Rol::admin});

	// Opciones específicas de la implementación (e.g. ver hora)
	agregar("set_time", "Modificar fecha del Sistema",
	        Roles{Rol::master});
	agregar("get_time", "Consultar fecha del sistema",
	        Roles{Rol::admin, Rol::medico, Rol::socio});

	// Solo para Master (debug, tests)
	agregar("load_test_data", "Cargar datos de prueba",
	        Roles{Rol::master});
}

void ControladorComando::ejecutar(Comando cmd)
{
	string opcion = cmd.codigo();

	// Casos de uso: Usuarios
	if (opcion == "alta_usuario")
	{
		ComandosUsuario::altaReactivacionUsuario();
	}
	else if (opcion == "altas_reactivaciones")
	{
		ComandosUsuario::listarAltasReactivaciones();
	}
	else if (opcion == "ver_historial")
	{
		ComandosUsuario::verHistorial();
	}

	// Casos de uso: Diagnósticos
	else if (opcion == "alta_representacion")
	{
		ComandosDiagnostico::altaRepresentacion();
	}
	else if (opcion == "listar_representaciones")
	{
		ComandosDiagnostico::listarRepresentaciones();
	}

	// Casos de uso: Consultas
	else if (opcion == "reserva_consulta")
	{
		ComandosConsulta::reservarConsulta();
	}
	else if (opcion == "devolucion_reserva")
	{
		ComandosConsulta::cancelarReserva();
	}
	else if (opcion == "registro_consulta")
	{
		ComandosConsulta::registrarConsulta();
	}
	else if (opcion == "alta_diagnosticos")
	{
		ComandosConsulta::altaDiagnosticosConsulta();
	}

	// Casos de uso: Medicamentos
	else if (opcion == "alta_farmaco")
	{
		ComandosFarmaco::altaFarmaco();
	}

	// Casos de uso: Notificaciones
	else if (opcion == "suscribirse_paciente")
	{
		ComandosNotificacion::seguirPaciente();
	}
	else if (opcion == "notificar_medicos")
	{
		ComandosNotificacion::notificarMedicos();
	}

	// Opciones específicas de la implementación (e.g. ver hora)
	else if (opcion == "set_time")
	{
		ComandosSistema::setTime();
	}
	else if (opcion == "get_time")
	{
		ComandosSistema::getTime();
	}

	// Solo para Master (debug, tests)
	else if (opcion == "load_test_data")
	{
		ComandosSistema::loadTestData();
	}

	// Opciones en desarrollo (todavía no implementadas)
	else
	{
		cout << "No hay manejador para la opción seleccionada "
		     << "(" << cmd.nombre() << ": " << cmd.nombre() << ")\n";
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

vector<Comando> ControladorComando::comandos(Roles roles)
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

void ControladorComando::agregar(string codigo, string nombre, Roles roles)
{
	this->_comandos.insert(this->_comandos.end(), Comando(codigo, nombre, roles));
}
