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

	void iniciarSesion();
	void cerrarSesion();

	bool sesionIniciada();

private:
	static ControladorSesion* _instancia;
	ControladorSesion();
	~ControladorSesion(){};

	Usuario* pedirIdentificacion();
	void autenticar(Usuario*);
	bool esValidaCi(string);
	bool esValidoPass(string);

};

#endif	/* CONTROLADORSESION_H */

