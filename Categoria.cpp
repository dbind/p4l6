#include "Categoria.h"


Categoria::Categoria(char codigo, string etiqueta)
{
	_codigo   = codigo;
	_etiqueta = etiqueta;
}

char Categoria::codigo()
{
	return _codigo;
}

string Categoria::etiqueta()
{
	return _etiqueta;
}