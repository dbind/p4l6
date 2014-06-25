#ifndef CONTROLADORDIAGNOSTICO_H
#define	CONTROLADORDIAGNOSTICO_H

#include "IControladorDiagnostico.h"


/**
 * Realiza IControladorDiagnostico como Singleton
 */
class ControladorDiagnostico : public IControladorDiagnostico
{

public:
	static ControladorDiagnostico* instancia();

private:
	static ControladorDiagnostico* _instancia;
	ControladorDiagnostico(){};
	~ControladorDiagnostico(){};

};

#endif	/* CONTROLADORDIAGNOSTICO_H */

