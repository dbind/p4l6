#ifndef TRATAMIENTOQUIRURGICO_H
#define TRATAMIENTOQUIRURGICO_H

using namespace std;

#include <string>

#include "Tratamiento.h"
#include "Fecha.h"


class Usuario;


class TratamientoQuirurgico : public Tratamiento
{

    public:
        TratamientoQuirurgico(Usuario* medico, Fecha, string descripcion);
        virtual ~TratamientoQuirurgico(){};

        Usuario* medico();
		Fecha fecha();

    private:
        Usuario* _medico;
		Fecha _fecha;

};

#endif // TRATAMIENTOQUIRURGICO_H
