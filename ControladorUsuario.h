#ifndef CONTROLADORUSUARIO_H
#define	CONTROLADORUSUARIO_H

#include <string>
#include <vector>

#include "IControladorUsuario.h"
#include "TipoSexo.h"
#include "Fecha.h"
#include "Rol.h"


class Usuario;


/**
 * Realiza IControladorUsuario como Singleton
 */
class ControladorUsuario : public IControladorUsuario
{

public:
	static ControladorUsuario* instancia();

	Usuario* crearMaster(string ci, string pass, string nombre);
	
	Usuario* findUsuario(string ci);
	Usuario* altaUsuario(string ci, string nombre, string apellido,
	                     TipoSexo, Fecha, vector<Rol>);

private:
	static ControladorUsuario* _instancia;
	ControladorUsuario();
	~ControladorUsuario(){};

};

#endif	/* CONTROLADORUSUARIO_H */

