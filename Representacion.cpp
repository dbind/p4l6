#include "Representacion.h"


Representacion::Representacion(Categoria categoria, string codigo, string etiqueta)
{
	_categoria = categoria;
	_codigo    = codigo;
	_etiqueta  = etiqueta;
}

Categoria Representacion::categoria()
{
	return _categoria;
}

string Representacion::codigo()
{
	return _codigo;
}

string Representacion::etiqueta()
{
	return _etiqueta;
}