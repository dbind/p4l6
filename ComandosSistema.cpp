using namespace std;

#include <iostream>
#include <vector>
#include <string>

#include "ComandosSistema.h"

#include "FabricaControladores.h"


void ComandosSistema::setTime()
{
	
}

void ComandosSistema::getTime()
{
	
}

void ComandosSistema::loadTestData()
{
	FabricaControladores* Fabrica = FabricaControladores::instancia();
	
	IControladorUsuario*  cUsuario  = Fabrica->controladorUsuario();
	IControladorConsulta* cConsulta = Fabrica->controladorConsulta();

	// Usuarios
	Genero M = Genero::masculino;
	Genero F = Genero::femenino;

	cUsuario->altaUsuario("34567645", "James" , "Peer"    , M, Fecha(28, 12, 1988), Roles{Rol::admin});
	cUsuario->altaUsuario("34562345", "Tifany", "McKensey", F, Fecha( 1,  1, 1990), Roles{Rol::socio});
	cUsuario->altaUsuario("12345435", "Diego" , "Perez"   , M, Fecha( 3,  3, 1980), Roles{Rol::socio});
	cUsuario->altaUsuario("65436667", "Juan"  , "Montoya" , M, Fecha( 7,  4, 1970), Roles{Rol::socio, Rol::medico});
	cUsuario->altaUsuario("43521343", "Debora", "Corral"  , F, Fecha(13,  7, 1993), Roles{Rol::medico});
	cUsuario->altaUsuario("98056743", "Ana"   , "Lopez"   , F, Fecha(24,  9, 1981), Roles{Rol::medico});
}