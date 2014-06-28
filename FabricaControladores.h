#ifndef FABRICACONTROLADORES_H
#define	FABRICACONTROLADORES_H

#include "ControladorMenu.h"
#include "ControladorSesion.h"
#include "ControladorUsuario.h"
#include "ControladorConsulta.h"
#include "ControladorDiagnostico.h"


class FabricaControladores
{
	
private:
	static FabricaControladores* _instancia;
	FabricaControladores(){};
	
public:
	static FabricaControladores* instancia();
	
	ControladorMenu*        controladorMenu();

	ControladorSesion*      controladorSesion();
	ControladorUsuario*     controladorUsuario();

	ControladorConsulta*    controladorConsulta();
	ControladorDiagnostico* controladorDiagnostico();
	
};

#endif	/* FABRICACONTROLADORES_H */

