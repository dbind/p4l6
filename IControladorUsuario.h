#ifndef ICONTROLADORUSUARIO_H
#define	ICONTROLADORUSUARIO_H

#include <string>
#include <vector>

#include "Usuario.h"
#include "TipoSexo.h"
#include "Fecha.h"
#include "Rol.h"


class IControladorSesion;


class IControladorUsuario
{

public:
	virtual ~IControladorUsuario(){};

	virtual Usuario* crearMaster(string ci, string pass, string nombre)=0;

	virtual Usuario* altaUsuario(string ci, string nombre, string apellido,
	                             TipoSexo, Fecha, vector<Rol>)=0;
	virtual Usuario* findUsuario(string ci)=0;
	
	virtual vector<string> getAccionesHabilitadas()=0;

protected:
	Usuario* usuarioActivo;
	vector<Usuario*> usuarios;

};

#endif	/* ICONTROLADORUSUARIO_H */

