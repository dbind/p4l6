#ifndef CONSULTA_H
#define CONSULTA_H

using namespace std;

#include <vector>

#include "Fecha.h"
#include "TipoConsulta.h"


class Diagnostico;
class Usuario;


class Consulta
{
 public:
	Consulta(){};
	virtual ~Consulta(){};

	TipoConsulta tipo();
	Usuario* medico();
	Usuario* paciente();
	Fecha fechaConsulta();

	vector<Diagnostico*> diagnosticos();
	void agregarDiagnostico(Diagnostico*);

protected:
	TipoConsulta _tipo;

	Usuario* _medico;
	Usuario* _paciente;
	Fecha _consulta;

	vector<Diagnostico*> _diagnosticos;

};

#endif // CO
