#ifndef TRATAMIENTOFARMACO_H
#define TRATAMIENTOFARMACO_H

#include <vector>

#include "../include/Tratamiento.h"
#include "../include/Farmaco.h"


class TratamientoFarmaco : public Tratamiento
{
    private:
        vector<Farmaco> lFarmacos;

    public:
        TratamientoFarmaco();
        virtual ~TratamientoFarmaco();

        vector<Farmaco> getListaFarmacos();
        setListaFarmacos(vector<Farmaco> farmacos);

        vector<Farmaco> getFarmacos();
        agregarFarmacoTrat(Farmaco f);
};

#endif // TRATAMIENTOFARMACO_H
