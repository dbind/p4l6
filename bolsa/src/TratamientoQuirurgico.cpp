#include "../include/TratamientoQuirurgico.h"

TratamientoQuirurgico::TratamientoQuirurgico()
{
    // TODO
}

TratamientoQuirurgico::~TratamientoQuirurgico()
{
    // TODO
}


Fecha TratamientoQuirurgico::getDia()
{
    return this->dia;
}

Hora TratamientoQuirurgico::getHora()
{
    return this->hora;
}

Usuario TratamientoQuirurgico::getMedico()
{
    return this->Medico;
}

TratamientoQuirurgico::setDia(Fecha dia)
{
    this->dia = dia;
}

TratamientoQuirurgico::setHora(Hora hora)
{
    this->hora = hora;
}

TratamientoQuirurgico::setMedico(Usuario medico)
{
    this->Medico = medico;
}
