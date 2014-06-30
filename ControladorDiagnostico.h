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

private:
	static ControladorDiagnostico* _instancia;
	ControladorDiagnostico(){};
	~ControladorDiagnostico(){};

};

#endif	/* CONTROLADORDIAGNOSTICO_H */

