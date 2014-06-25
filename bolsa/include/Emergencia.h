#ifndef EMERGENCIA_H
#define EMERGENCIA_H

#include <string>

#include "../include/Consulta.h"
#include "../include/Fecha.h"


class Emergencia : public Consulta
{
    private:
        string motivo;

    public:
        Emergencia();
        virtual ~Emergencia();

        string getMotivo();
        setMotivo(string motivo);

        agregarFechaMotivo(Fecha fechaConsulta, string motivo);
};

#endif // EMERGENCIA_H
