#ifndef USUARIO_H
#define USUARIO_H

using namespace std;

#include <string>
#include <vector>

#include "Consulta.h"

#include "Comando.h"
#include "Genero.h"
#include "Fecha.h"
#include "Rol.h"
#include "EstadoUsuario.h"

#include "IStrategyNotificaciones.h"


const int MAX_INASISTENCIAS = 3;


class Usuario
{

public:
	Usuario(string ci, string nombre, string apellido,
	        Genero, Fecha, Roles);
	virtual ~Usuario(){};

	string getCi();
	string getNombre();
	string getApellido();
	Genero getGenero();
	Fecha getFechaNac();
	Roles &roles();

	vector<Comando> comandos();

	Fecha fechaAlta();
	Fecha fechaReactivacion();

	void setNombre(string);
	void setApellido(string);
	void setGenero(Genero);
	void setFechaNac(Fecha);
	int edad();
	
	bool esUn(Rol);
	bool esNuevo();
	bool estaActivo();
	bool estaInactivo();
	bool validarPass(string);
	
	void activar();
	void desactivar();
	void cambiarPass(string);
	
	/**
	 * Agrego usuarios a la lista de dados de alta por este usuario
     */
	void agregarDadoDeAlta(Usuario*);

	/**
	 * Agrego usuarios a la lista de reactivados por este usuario
     */
	void agregarReactivado(Usuario*);

	/**
	 * Notificaciones
	 */
	void setNotificador(IStrategyNotificaciones*);  // Setear estrategia
	void agregarSuscriptor(Usuario* medico, Fecha); // Suscribir observers
	void notificarSujeto(Consulta*);                // Consulta avisa a paciente
	void notificarObserver(Consulta*);              // Paciente avisa a m�dico
	vector<string> notificaciones();                // Lista de notificaciones

	vector<Usuario*> dadosDeAlta();
	vector<Usuario*> reactivados();
	vector<Usuario*> suscriptores();

	int inasistencias();
	void faltoConsulta();

	vector<Consulta*> consultas();
	void registrarConsulta(Consulta*);

private:
	string _ci;
	string _nombre;
	string _apellido;
	Genero _genero;
	Fecha _fechaNac;
	string _pass;
	EstadoUsuario _estado;
	Roles _roles;

	int _inasistencias = 0;

	Fecha _alta;
	Fecha _reactivacion;

	vector<Comando> _comandos;

	vector<Usuario*> _dadosDeAlta {};
	vector<Usuario*> _reactivados {};

	vector<Usuario*> _suscriptores {};
	IStrategyNotificaciones* _notificador = NULL;

	vector<Consulta*> _consultas;
};

#endif // USUARIO_H
