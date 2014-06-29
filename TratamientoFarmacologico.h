#ifndef TRATAMIENTOFARMACOLOGICO_H
#define TRATAMIENTOFARMACOLOGICO_H

using namespace std;

#include <string>

#include "Tratamiento.h"


class Farmaco;


class TratamientoFarmacologico : public Tratamiento
{

    public:
        TratamientoFarmacologico(Farmaco*, string descripcion);
        virtual ~TratamientoFarmacologico(){};

        Farmaco* farmaco();

    private:
        Farmaco* _farmaco;

};

#endif // TRATAMIENTOFARMACOLOGICO_H
