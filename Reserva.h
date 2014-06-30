#ifndef RESERVA_H
#define	RESERVA_H

#include "Fecha.h"
#include "Usuario.h"

class Reserva 
{
    public:
        Reserva(Usuario* medico, Usuario* paciente, Fecha fechaConsulta, Fecha fechaReserva);
        virtual ~Reserva(){};
        
        Usuario* medico();
        Usuario* paciente();
        Fecha fechaConsulta();
        Fecha fechaReserva();
        
        
    private:
        Usuario* _medico;
        Usuario* _paciente;
        Fecha _consulta;
        Fecha _reserva;
};

#endif	/* RESERVA_H */

