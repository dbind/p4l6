#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H

#include <string>
#include <vector>

#include "../include/Tratamiento.h"
#include "../include/DataTratamiento.h"
#include "../include/TratamientoQuirurgico.h"
#include "../include/Farmaco.h"
#include "../include/DataDiagnostico.h"


class Diagnostico
{
    private:
        string descripcion;
        vector<Tratamiento*> tratamientos;
        vector<DataTratamiento> dataTratamientos;

    public:
        Diagnostico();
        virtual ~Diagnostico();

        string getDescripcion();
        vector<Tratamiento*> getTratamientos();
        vector<DataTratamiento> getDataTratamientos();
        setDescripcion(string descripcion);
        setTratamientos(vector<Tratamiento*> lista);
        setDataTratamientos(vector<DataTratamiento> data);

        char getCategoria();
        string getEtiqueta();
        vector<Tratamiento> getTratamientos();
        vector<TratamientoQuirurgico> getTratamientosQuirurgicos();
        vector<Farmaco> getFarmacos();
        agregarTratamiento(Tratamiento t);
        DataDiagnostico obtenerDataDiagnostico();
};

#endif // DIAGNOSTICO_H
