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
        
        virtual vector<Consulta> consultas()=0;
        
	virtual vector<Reserva*> reservas()=0;
	virtual void removeReserva(Usuario* medico, Usuario* paciente, Fecha fechaConsulta, Fecha fechaReserva)=0;

	virtual void reset()=0;

protected:
	vector<Reserva*> _reservas;
        vector<Consulta> _consultas;

};

#endif	/* ICONTROLADORCONSULTA_H */