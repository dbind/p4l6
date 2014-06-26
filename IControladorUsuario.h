#ifndef ICONTROLADORUSUARIO_H
#define	ICONTROLADORUSUARIO_H

using namespace std;

#include <string>
#include <vector>

#include "TipoSexo.h"
#include "Rol.h"

class Usuario;
class Fecha;
class Comando;


class IControladorSesion;
class Comando;


class IControladorUsuario
{

public:
	virtual ~IControladorUsuario(){};

	virtual Usuario* crearMaster(string ci, string pass, string nombre)=0;

	virtual Usuario* altaUsuario(string ci, string nombre, string apellido,
	                             TipoSexo, Fecha, vector<Rol>)=0;
	virtual Usuario* findUsuario(string ci)=0;
	
	/**
	 * Retorna un vector de comandos habilitados para los roles especificados
     */
	virtual vector<Comando> comandos(vector<Rol>)=0;
	virtual void ejecutar(Comando)=0;

protected:
	Usuario* usuarioActivo;
	vector<Usuario*> usuarios;
	vector<Comando> _comandos;

};

#endif	/* ICONTROLADORUSUARIO_H */

