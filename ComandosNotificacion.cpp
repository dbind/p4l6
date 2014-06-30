using namespace std;

#include <iostream>
#include <vector>
#include <string>

#include "ComandosNotificacion.h"
#include "FabricaControladores.h"


void ComandosNotificacion::seguirPaciente()
{
	
}

void ComandosNotificacion::verNotificaciones()
{
	vector<string> lista = FabricaControladores::instancia()->controladorSesion()
	                                                        ->usuarioActivo()
	                                                        ->notificaciones();
	int i=0;

	for (vector<string>::iterator it = lista.begin(); it != lista.end(); ++it)
	{
		string notificacion = *it;

		cout << "Notificacion " << ++i << endl << notificacion << endl << endl;
	}
}