#ifndef CONTROLADORSISTEMA_H
#define	CONTROLADORSISTEMA_H

#include "IControladorSistema.h"
#include "Fecha.h"


/**
 * Singleton ControladorSistema
 */
class ControladorSistema : public IControladorSistema
{

public:
	static ControladorSistema* instancia();

	Fecha getFechaDelSistema();
	void setFechaDelSistema(Fecha);

	void reset();

private:
	static ControladorSistema* _instancia;
	ControladorSistema();

};

#endif	/* CONTROLADORSISTEMA_H */
