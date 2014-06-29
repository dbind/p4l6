#ifndef ICONTROLADORUSUARIO_H
#define	ICONTROLADORUSUARIO_H

using namespace std;

#include <string>
#include <vector>

#include "Genero.h"
#include "Rol.h"


class Usuario;
class Fecha;
class IControladorSesion;


class IControladorUsuario
{

public:
	virtual ~IControladorUsuario(){};

	virtual Usuario* crearMaster(string ci, string pass, string nombre)=0;

	virtual Usuario* altaUsuario(string ci, string nombre, string apellido,
	                             Genero, Fecha, Roles)=0;

	virtual void reactivar(Usuario*)=0;

	virtual vector<Usuario*> usuarios()=0;
	virtual Usuario* findUsuario(string ci)=0;

protected:
	Usuario* usuarioActivo;
	vector<Usuario*> _usuarios;

};

#endif	/* ICONTROLADORUSUARIO_H */

