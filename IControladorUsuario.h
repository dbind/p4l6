#ifndef ICONTROLADORUSUARIO_H
#define	ICONTROLADORUSUARIO_H

using namespace std;

#include <string>
#include <vector>

#include "TipoSexo.h"
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
	                             TipoSexo, Fecha, vector<Rol>)=0;
	virtual Usuario* findUsuario(string ci)=0;

protected:
	Usuario* usuarioActivo;
	vector<Usuario*> usuarios;

};

#endif	/* ICONTROLADORUSUARIO_H */

