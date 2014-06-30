#ifndef ICONTROLADORCONSULTA_H
#define	ICONTROLADORCONSULTA_H

using namespace std;

#include <vector>
#include <string>
#include "Reserva.h"


class IControladorConsulta
{

public:
	virtual ~IControladorConsulta(){};

	virtual void reset()=0;

protected:
	vector<Reserva*> _reservas;

};

#endif	/* ICONTROLADORCONSULTA_H */