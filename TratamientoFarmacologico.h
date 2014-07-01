#ifndef TRATAMIENTOFARMACOLOGICO_H
#define TRATAMIENTOFARMACOLOGICO_H

using namespace std;

#include <string>
#include <vector>

#include "Tratamiento.h"


class Farmaco;


class TratamientoFarmacologico : public Tratamiento
{

    public:
        TratamientoFarmacologico(vector<Farmaco*>, string descripcion);
        virtual ~TratamientoFarmacologico(){};

        vector<Farmaco*> farmacos();

    private:
        vector<Farmaco*> _farmacos;

};

#endif // TRATAMIENTOFARMACOLOGICO_H
