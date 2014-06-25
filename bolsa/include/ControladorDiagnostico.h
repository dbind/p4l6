#ifndef CONTROLADORDIAGNOSTICO_H
#define CONTROLADORDIAGNOSTICO_H

#include <vector>
#include <string>

#include "../interfaces/Singleton.h"

#include "../includes/Representacion.h"
#include "../includes/Farmaco.h"
#include "../includes/Diagnostico.h"
#include "../includes/Tratamiento.h"
#include "../includes/TipoTratamiento.h"
#include "../includes/FechaHora.h"


class ControladorDiagnostico : public Singleton
{
    private:
        void ControladorDiagnostico() = 0;
        static ControladorDiagnostico* _instancia;

        vector<Representacion> representaciones;
        Representacion representacionSeleccionada;
        Diagnostico diagnostico;
        Tratamiento tratamiento;
        vector<Farmaco> farmacos;

    public:
        static ControladorDiagnostico* instancia();

        vector<Representacion> getRepresentaciones();
        Representacion getRepresentacionSeleccionada();
        Diagnostico getDiagnostico();
        Tratamiento getTratamiento();
        vector<Farmaco> getFarmacos();
        setRepresentaciones(vector<Representacion> representaciones);
        setRepresentacionSeleccionada(Representacion representacionSeleccionada);
        void setDiagnostico(Diagnostico diagnostico);
        void setTratamiento(Tratamiento tratamiento);
        void setFarmacos(vector<Farmaco> farmacos);

        vector<char> listarCategoriasRepresentacion();
        vector<Representacion> listarRepresentacionesPorCategoria(char categoria);
        void elegirRepresentacion(string patologia);
        Diagnostico crearDiagnostico();
        void agregarDescripcion(string descripcion);
        void definirTratamiento(TipoTratamiento tipo, string descripcion);
        void agregarDataTratamientoQuirurgico(FechaHora fecha, string ciMedico);
        void agregarFarmaco(string nombreFarmaco);
        void aceptarTratamiento();
        void aceptarDiagnostico();
        void cancelarDiagnostico();
        void cancelarTratamiento();
        void aceptarDiagnosticos();
        Diagnostico obtenerDiagnosticoRecordado();
        void vaciarDiagnosticoRecordado();
};

#endif // CONTROLADORDIAGNOSTICO_H
