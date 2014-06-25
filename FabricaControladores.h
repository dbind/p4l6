#ifndef FABRICACONTROLADORES_H
#define	FABRICACONTROLADORES_H

#include "IControladorSesion.h"
#include "IControladorUsuario.h"
#include "IControladorConsulta.h"
#include "IControladorDiagnostico.h"

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
	
	ControladorSesion*      getControladorSesion();
	ControladorUsuario*     getControladorUsuario();
	ControladorConsulta*    getControladorConsulta();
	ControladorDiagnostico* getControladorDiagnostico();
	
};

#endif	/* FABRICACONTROLADORES_H */

