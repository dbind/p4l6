#ifndef TRATAMIENTO_H
#define TRATAMIENTO_H

#include <string>

#include "../include/DataTratamiento.h"


class Tratamiento
{
    private:
        string descripcion;

    public:
        Tratamiento();
        virtual ~Tratamiento();

        string getDescripcion();
        setDescripcion(string descripcion);

        DataTratamiento obtenerDataTratamiento();
};

#endif // TRATAMIENTO_H
