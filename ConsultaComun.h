#ifndef CONSULTACOMUN_H
#define CONSULTACOMUN_H

#include "Consulta.h"

#include "Reserva.h"
#include "Usuario.h"
#include "Fecha.h"


class ConsultaComun : public Consulta
{

public:
	ConsultaComun(Usuario* medico, Usuario* paciente, Fecha consulta, Reserva* reserva);
	ConsultaComun(Usuario* medico, Usuario* paciente, Fecha consulta, Fecha reserva);

	Reserva* reserva();

protected:
	Reserva* _reserva;

};

#endif // CONSULTACOMUN_H
