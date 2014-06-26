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
	
	Usuario* altaUsuario(string ci, string nombre, string apellido,
	                     TipoSexo, Fecha, vector<Rol>);
	Usuario* findUsuario(string ci);
	
	vector<string> getAccionesHabilitadas();

private:
	static ControladorUsuario* _instancia;
	ControladorUsuario();
	~ControladorUsuario(){};

};

#endif	/* CONTROLADORUSUARIO_H */

