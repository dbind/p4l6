/* 
 * File:   Reserva.h
 * Author: User1
 *
 * Created on 29 juin 2014, 15:58
 */

#ifndef RESERVA_H
#define	RESERVA_H

#include "FechaHora.h"

class Reserva 
{
    public:
        Reserva(FechaHora fechaConsulta, FechaHora fechaReserva, Usuario* Medico, Usuario* Paciente);
        virtual ~Reserva();
    private:
        Usuario* Medico;
        Usuario* Paciente;
        FechaHora fechaConsulta;
        FechaHora fechaReserva;
};

#endif	/* RESERVA_H */

