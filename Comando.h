#ifndef COMANDO_H
#define COMANDO_H

using namespace std;

#include <string>
#include <vector>

#include "Rol.h"


class Comando
{

    public:
		Comando(string codigo, string nombre, Roles);

        string codigo();
        string nombre();
		bool habilitadoPara(Rol);
		bool habilitadoPara(Roles);

    private:
        string _codigo;
        string _nombre;
		Roles _roles; // Roles habilitados para ejecutar este comando

};

#endif // COMANDO_H
