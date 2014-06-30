#ifndef CONTROLADORCONSULTA_H
#define	CONTROLADORCONSULTA_H

using namespace std;

#include <vector>

#include "IControladorConsulta.h"

#include "Usuario.h"
#include "Consulta.h"
#include "Reserva.h"

#include "Fecha.h"


/**
 * Realiza IControladorConsulta como Singleton
 */
class ControladorConsulta : public IControladorConsulta
{

public:
	static ControladorConsulta* instancia();

	vector<Consulta*> consultas();
	vector<Reserva*> reservas();

	vector<Consulta*> listarConsultasDia(Fecha);

	void removeReserva(Usuario* medico, Usuario* paciente, Fecha fechaConsulta, Fecha fechaReserva);

	void reset();

private:
	static ControladorConsulta* _instancia;
	ControladorConsulta(){};

};

#endif	/* CONTROLADORCONSULTA_H */

