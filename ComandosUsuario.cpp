using namespace std;

#include <iostream>
#include <vector>

#include "ComandosUsuario.h"
#include "Usuario.h"
#include "FabricaControladores.h"


void ComandosUsuario::altaReactivacionUsuario()
{
	// TODO
}

void ComandosUsuario::listarAltasReactivaciones()
{
	vector<Usuario*> usuarios = FabricaControladores::instancia()->controladorUsuario()->usuarios();
	vector<Usuario*>::iterator it;

    for (it=usuarios.begin(); it != usuarios.end(); ++it)
    {
		Usuario* usuario = *it;

        cout << "Nombre: "   << usuario->getNombre() << "\n"
		     << "Apellido: " << usuario->getApellido() << "\n"
//		     << "Sexo: " << usuario->getSexo() << "\n"
//		     << "Fecha Nacimiento: " << usuario->getFechaNac() << "\n"
//		     << "Roles: " << usuario->roles() << "\n"
		     << "---------------------\n\n";
    }

}

void ComandosUsuario::verHistorial()
{
	// TODO
}
