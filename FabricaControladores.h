#ifndef FABRICACONTROLADORES_H
#define	FABRICACONTROLADORES_H

#include "ControladorMenu.h"
#include "ControladorComando.h"

#include "ControladorSesion.h"
#include "ControladorUsuario.h"

#include "ControladorFarmaco.h"
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
	ControladorComando*     controladorComando();

	ControladorSesion*      controladorSesion();
	ControladorUsuario*     controladorUsuario();

	ControladorFarmaco*     controladorFarmaco();
	ControladorConsulta*    controladorConsulta();
	ControladorDiagnostico* controladorDiagnostico();
	
};

#endif	/* FABRICACONTROLADORES_H */

