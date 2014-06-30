#ifndef CONSULTAURGENCIA_H
#define CONSULTAURGENCIA_H

using namespace std;

#include <string>

#include "Consulta.h"


class ConsultaUrgencia : public Consulta
{

public:
	ConsultaUrgencia(Usuario* medico, Usuario* paciente, Fecha consulta, string descripcion);

protected:
	string _descripcion;

};

#endif // CONSULTAURGENCIA_H
