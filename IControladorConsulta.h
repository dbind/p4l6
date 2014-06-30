#ifndef ICONTROLADORCONSULTA_H
#define	ICONTROLADORCONSULTA_H

using namespace std;

#include <vector>

#include "Usuario.h"
#include "Consulta.h"
#include "Reserva.h"

#include "Fecha.h"


class IControladorConsulta
{

public:
	virtual ~IControladorConsulta(){};

	virtual vector<Consulta*> consultas()=0;
	virtual vector<Reserva*> reservas()=0;
        
        virtual void altaReserva(Reserva* reserva)=0;
        virtual void altaConsulta(Consulta* consulta)=0;

	virtual vector<Reserva*> listarReservasDia(Fecha)=0;
        virtual vector<Consulta*> listarConsultasDia(Fecha)=0;
        
	virtual void removeReserva(Reserva*)=0;

	virtual void reset()=0;

protected:
	vector<Reserva*> _reservas{};
	vector<Consulta*> _consultas{};

};

#endif	/* ICONTROLADORCONSULTA_H */