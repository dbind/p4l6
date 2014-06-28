#ifndef USUARIO_H
#define USUARIO_H

using namespace std;

#include <string>
#include <vector>

#include "TipoSexo.h"
#include "Fecha.h"
#include "Rol.h"
#include "EstadoUsuario.h"
//#include "Consulta.h"


class Comando;


class Usuario
{

public:
	Usuario(string ci, string nombre, string apellido,
	        TipoSexo, Fecha, vector<Rol>);
	virtual ~Usuario(){};

	string getCi();
	string getNombre();
	string getApellido();
	TipoSexo getSexo();
	Fecha getFechaNac();
	vector<Rol> roles();
	vector<Comando> comandos();

	void setNombre(string);
	void setApellido(string);
	void setSexo(TipoSexo);
	void setFechaNac(Fecha);

	
	bool esUn(Rol);
	bool esNuevo();
	bool estaActivo();
	bool estaInactivo();
	bool validarPass(string);
	
	void activar();
	void desactivar();
	void cambiarPass(string);

	int calcularEdad();
	int calcularInasistencias();
//	vector<Consulta> listarConsultas();
//	vector<Consulta> listarConsultasComunes();
//	vector<Consulta> getConsultasAtendidas();
//	Consulta obtenerConsulta();

private:
	string _ci;
	string _nombre;
	string _apellido;
	TipoSexo _sexo;
	Fecha _fechaNac;
	string _pass;
	EstadoUsuario _estado;
	vector<Rol> _roles;
	vector<Comando> _comandos;
};

#endif // USUARIO_H
