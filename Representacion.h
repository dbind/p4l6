#ifndef REPRESENTACION_H
#define REPRESENTACION_H

using namespace std;

#include <string>

#include "Categoria.h"


class Representacion
{

public:
	Representacion(){};
	Representacion(Categoria, string codigo, string etiqueta);
	~Representacion(){};

	Categoria categoria();
	string codigo();
	string etiqueta();

private:
	Categoria _categoria;
	string _codigo;
	string _etiqueta;

};

#endif // REPRESENTACION_H
