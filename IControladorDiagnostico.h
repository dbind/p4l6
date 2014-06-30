#ifndef ICONTROLADORDIAGNOSTICO_H
#define	ICONTROLADORDIAGNOSTICO_H

using namespace std;

#include <string>
#include <vector>

#include "Categoria.h"
#include "Representacion.h"


class IControladorDiagnostico
{

public:
	virtual ~IControladorDiagnostico(){};

	virtual Categoria agregarCategoria(char codigo, string etiqueta)=0;
	virtual Representacion altaRepresentacion(Categoria, string codigo, string etiqueta)=0;
        virtual vector<Categoria> categorias()=0;

protected:
	vector<Categoria> _categorias;
	vector<Representacion> _representaciones;

};

#endif	/* ICONTROLADORDIAGNOSTICO_H */

