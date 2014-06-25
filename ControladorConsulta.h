#ifndef CONTROLADORCONSULTA_H
#define	CONTROLADORCONSULTA_H

#include "IControladorConsulta.h"


/**
 * Realiza IControladorConsulta como Singleton
 */
class ControladorConsulta : public IControladorConsulta
{

public:
	static ControladorConsulta* instancia();

private:
	static ControladorConsulta* _instancia;
	ControladorConsulta(){};

};

#endif	/* CONTROLADORCONSULTA_H */

