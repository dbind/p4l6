#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>

#include "TipoSexo.h"
#include "Fecha.h"
#include "Rol.h"
#include "EstadoUsuario.h"
//#include "Consulta.h"

using namespace std;


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

	void setNombre(string);
	void setApellido(string);
	void setSexo(TipoSexo);
	void setFechaNac(Fecha);

	
	bool esUn(Rol);
	bool esNuevo();
	bool estaActivo();
	bool estaInactivo();
	bool validarPass(string pass);
	
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
	string ci;
	string nombre;
	string apellido;
	TipoSexo sexo;
	Fecha fechaNac;
	string pass;
	EstadoUsuario estado;
	vector<Rol> roles;
};

#endif // USUARIO_H
