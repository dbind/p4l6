#ifndef CONTROLADORSESION_H
#define	CONTROLADORSESION_H

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
	
	void testControlador();

	bool iniciarSesion();

private:
	static ControladorSesion* _instancia;
	ControladorSesion();
	~ControladorSesion(){};

	Usuario* pedirIdentificacion();
	bool pedirAutenticacion(Usuario*);
	bool esValidaCi(string);
	bool esValidoPass(string);

};

#endif	/* CONTROLADORSESION_H */

