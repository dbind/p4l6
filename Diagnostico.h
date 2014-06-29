#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H

using namespace std;

#include <string>


class Consulta;
class Representacion;


class Diagnostico
{

public:
	Diagnostico(Consulta*, Representacion*, string descripcion);
	virtual ~Diagnostico(){};

	Consulta* consulta();
	Representacion* representacion();
	string descripcion();

private:
	Consulta* _consulta;
	Representacion* _representacion;
	string _descripcion;

};

#endif // DIAGNOSTICO_H
