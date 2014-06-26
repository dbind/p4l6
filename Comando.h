#ifndef COMANDO_H
#define COMANDO_H

using namespace std;

#include <string>
#include <vector>

#include "Rol.h"


class Comando
{

    public:
		Comando(string codigo, string nombre, vector<Rol>);

        string codigo();
        string nombre();
		bool habilitadoPara(Rol);

    private:
        string _codigo;
        string _nombre;
		vector<Rol> _roles; // Roles habilitados para ejecutar este comando

};

#endif // COMANDO_H
