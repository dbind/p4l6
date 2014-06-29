/* 
 * File:   Reserva.cpp
 * Author: User1
 * 
 * Created on 29 juin 2014, 15:58
 */

#include "Reserva.h"

Reserva::Reserva(FechaHora fechaConsulta, FechaHora fechaReserva, Usuario* Medico, Usuario* Paciente) 
{
    this->fechaConsulta = fechaConsulta;
    this->fechaReserva = fechaReserva;
    this->Medico = Medico;
    this->Paciente = Paciente;

}


Reserva::~Reserva() {}



