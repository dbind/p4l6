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
        
        void altaReserva (Reserva* reserva);
        void altaConsulta (Consulta* consulta);

	vector<Consulta*> listarConsultasDia(Fecha);

	void removeReserva(Reserva* reserva);

	void reset();

private:
	static ControladorConsulta* _instancia;
	ControladorConsulta(){};

};

#endif	/* CONTROLADORCONSULTA_H */

