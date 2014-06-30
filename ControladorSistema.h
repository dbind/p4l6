#ifndef CONTROLADORSISTEMA_H
#define	CONTROLADORSISTEMA_H

#include "IControladorSistema.h"


/**
 * Singleton ControladorSistema
 */
class ControladorSistema : public IControladorSistema
{

public:
	static ControladorSistema* instancia();

private:
	static ControladorSistema* _instancia;
	ControladorSistema();

	Fecha actual;

};

#endif	/* CONTROLADORSISTEMA_H */
