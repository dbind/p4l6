#ifndef CONSULTACOMUN_H
#define CONSULTACOMUN_H

#include "Consulta.h"

#include "Usuario.h"
#include "Fecha.h"


class ConsultaComun : public Consulta
{

public:
	ConsultaComun(Usuario* medico, Usuario* paciente, Fecha consulta, Fecha reserva);

	Fecha fechaReserva();

protected:
	Fecha _reserva;

};

#endif // CONSULTACOMUN_H
