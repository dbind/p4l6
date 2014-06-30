#ifndef RESERVA_H
#define	RESERVA_H

#include "Fecha.h"
#include "Usuario.h"


class Reserva 
{

public:
	Reserva(Usuario* medico, Usuario* paciente, Fecha consulta, Fecha reserva);
	virtual ~Reserva(){};

	Usuario* medico();
	Usuario* paciente();
	Fecha fechaConsulta();
	Fecha fechaReserva();

	bool asistio();
	void asistir();

private:
	Usuario* _medico;
	Usuario* _paciente;
	Fecha _consulta;
	Fecha _reserva;

	bool _asistio = false;

};

#endif	/* RESERVA_H */

