#ifndef CONTROLADORDIAGNOSTICO_H
#define	CONTROLADORDIAGNOSTICO_H

using namespace std;

#include <string>

#include "IControladorDiagnostico.h"
#include "Categoria.h"
#include "Representacion.h"


/**
 * Realiza IControladorDiagnostico como Singleton
 */
class ControladorDiagnostico : public IControladorDiagnostico
{

public:
	static ControladorDiagnostico* instancia();

	Categoria agregarCategoria(char codigo, string etiqueta);
	Representacion altaRepresentacion(Categoria, string codigo, string etiqueta);
	Diagnostico* altaDiagnostico(Consulta*, Representacion, string descripcion);
	TratamientoFarmacologico* agregarTratamientoFarmacologico(Diagnostico*, Farmaco*, string descripcion);
	TratamientoQuirurgico* agregarTratamientoQuirurgico(Diagnostico*, Usuario* medico, Fecha, string descripcion);

	vector<Categoria> categorias();
	vector<Representacion> representaciones();

	void reset();

private:
	static ControladorDiagnostico* _instancia;
	ControladorDiagnostico(){};
	~ControladorDiagnostico(){};

};

#endif	/* CONTROLADORDIAGNOSTICO_H */

