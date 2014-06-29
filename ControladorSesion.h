#ifndef CONTROLADORSESION_H
#define	CONTROLADORSESION_H

using namespace std;

#include <string>

#include "IControladorSesion.h"


class Usuario;


/**
 * Realiza IControladorSesion como Singleton
 */
class ControladorSesion : public IControladorSesion
{

public:
	static ControladorSesion* instancia();

	void iniciarSesion();
	void cerrarSesion();

	bool sesionIniciada();
	Usuario* usuarioActivo();

	void iniciarSesionInterno(Usuario*);

private:

	static ControladorSesion* _instancia;
	ControladorSesion(){};
	~ControladorSesion(){};

	Usuario* pedirIdentificacion();
	bool autenticar(Usuario*);
	bool esValidaCi(string);
	bool esValidoPass(string);

};

#endif	/* CONTROLADORSESION_H */

