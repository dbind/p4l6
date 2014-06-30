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


class Usuario
{

public:
	Usuario(string ci, string nombre, string apellido,
	        Genero, Fecha, Roles);
	virtual ~Usuario(){};

	string getCi();
	string getNombre();
	string getApellido();
	Genero getSexo();
	Fecha getFechaNac();
	Roles roles();
	vector<Comando> comandos();

	void setNombre(string);
	void setApellido(string);
	void setSexo(Genero);
	void setFechaNac(Fecha);
	
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
	void agregarSuscriptor(Usuario* medico, Fecha); // Suscribir observers
	void notificarSujeto(Consulta*);                // Consulta avisa a paciente
	void notificarObserver(Consulta*);              // Paciente avisa a médico

	int calcularEdad();
	int calcularInasistencias();

private:
	string _ci;
	string _nombre;
	string _apellido;
	Genero _sexo;
	Fecha _fechaNac;
	string _pass;
	EstadoUsuario _estado;
	Roles _roles;

	vector<Comando> _comandos;

	vector<Usuario*> _dadosDeAlta {};
	vector<Usuario*> _reactivados {};

	vector<Usuario*> _suscriptores {};
};

#endif // USUARIO_H
