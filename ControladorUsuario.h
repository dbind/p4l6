#ifndef CONTROLADORUSUARIO_H
#define	CONTROLADORUSUARIO_H

using namespace std;

#include <string>
#include <vector>

#include "IControladorUsuario.h"

#include "Genero.h"
#include "Fecha.h"
#include "Rol.h"
#include "Comando.h"


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
	                     Genero, Fecha, Roles);

	void reactivar(Usuario* usuario);
        
	vector<Usuario*> usuarios();
	Usuario* findUsuario(string ci);

private:
	static ControladorUsuario* _instancia;
	ControladorUsuario();
	~ControladorUsuario(){};

};

#endif	/* CONTROLADORUSUARIO_H */

