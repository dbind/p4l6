#ifndef CONTROLADORCONSULTA_H
#define	CONTROLADORCONSULTA_H

#include "IControladorConsulta.h"
#include "Reserva.h"

/**
 * Realiza IControladorConsulta como Singleton
 */
class ControladorConsulta : public IControladorConsulta
{

public:
	static ControladorConsulta* instancia();
        vector<Reserva*> getReservas();
        void removeReserva(FechaHora* fechaConsulta, FechaHora* fechaReserva, Usuario* Medico, Usuario* Paciente);


private:
	static ControladorConsulta* _instancia;
	ControladorConsulta(){};

};

#endif	/* CONTROLADORCONSULTA_H */

