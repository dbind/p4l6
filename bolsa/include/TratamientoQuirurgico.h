#ifndef TRATAMIENTOQUIRURGICO_H
#define TRATAMIENTOQUIRURGICO_H

#include "../include/Tratamiento.h"
#include "../include/Fecha.h"
#include "../include/Hora.h"
#include "../include/Usuario.h"


class TratamientoQuirurgico : public Tratamiento
{
    private:
        Fecha dia;
        Hora hora;
        Usuario Medico;

    public:
        TratamientoQuirurgico();
        virtual ~TratamientoQuirurgico();

        Fecha getDia();
        Hora getHora();
        Usuario getMedico();
        setDia(Fecha dia);
        setHora(Hora hora);
        setMedico(Usuario medico);
};

#endif // TRATAMIENTOQUIRURGICO_H
