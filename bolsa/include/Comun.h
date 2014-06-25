#ifndef COMUN_H
#define COMUN_H

#include "../include/Consulta.h"
#include "../include/Fecha.h"


class Comun : public Consulta
{
    private:
        FechaHora fechaReserva;

    public:
        Comun();
        virtual ~Comun();

        FechaHora getFechaReserva();
        setFechaReserva(FechaHora fecha);

        agregarConsulta(FechaHora fechaConsulta, FechaHora fechaReserva);
};

#endif // COMUN_H
