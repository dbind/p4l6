#ifndef CATEGORIA_H
#define CATEGORIA_H

using namespace std;

#include <string>


class Categoria
{

public:
	Categoria(){};
	Categoria(char codigo, string etiqueta);
	~Categoria(){};

	char codigo();
	string etiqueta();

private:
	char _codigo;
	string _etiqueta;

};

#endif // CATEGORIA_H
