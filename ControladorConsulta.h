#ifndef CONTROLADORCONSULTA_H
#define	CONTROLADORCONSULTA_H

#include "IControladorConsulta.h"
#include "Reserva.h"
#include "Fecha.h"

/**
 * Realiza IControladorConsulta como Singleton
 */
class ControladorConsulta : public IControladorConsulta
{

public:
	static ControladorConsulta* instancia();
        
        vector<Consulta> consultas();

	vector<Reserva*> reservas();
	void removeReserva(Usuario* medico, Usuario* paciente, Fecha fechaConsulta, Fecha fechaReserva);

	void reset();

private:
	static ControladorConsulta* _instancia;
	ControladorConsulta(){};

};

#endif	/* CONTROLADORCONSULTA_H */

