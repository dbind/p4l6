#ifndef ICONTROLADORDIAGNOSTICO_H
#define	ICONTROLADORDIAGNOSTICO_H

using namespace std;

#include <string>
#include <vector>

#include "Categoria.h"
#include "Representacion.h"
#include "Diagnostico.h"
#include "Consulta.h"
#include "Usuario.h"

#include "Fecha.h"


class IControladorDiagnostico
{

public:
	virtual ~IControladorDiagnostico(){};

	virtual Categoria agregarCategoria(char codigo, string etiqueta)=0;
	virtual Representacion altaRepresentacion(Categoria, string codigo, string etiqueta)=0;
	virtual Diagnostico* altaDiagnostico(Consulta*, Representacion, string descripcion)=0;
	virtual TratamientoFarmacologico* agregarTratamientoFarmacologico(Diagnostico*, vector<Farmaco*>, string descripcion)=0;
	virtual TratamientoQuirurgico* agregarTratamientoQuirurgico(Diagnostico*, Usuario* medico, Fecha, string descripcion)=0;
	
	virtual vector<Categoria> categorias()=0;
	virtual vector<Representacion> representaciones()=0;

	virtual void reset()=0;

protected:
	vector<Categoria> _categorias;
	vector<Representacion> _representaciones;

};

#endif	/* ICONTROLADORDIAGNOSTICO_H */

