#ifndef CONSULTA_H
#define CONSULTA_H

#include <string>
#include <vector>

#include "../include/Usuario.h"
#include "../include/Diagnostico.h"
#include "../include/DiagnosticoTratamiento.h"
#include "../include/Fecha.h"
#include "../include/Hora.h"
#include "../include/TipoAsis.h"
#include "../include/ConsultaAsistida.h"



class Consulta
{
    private:
        FechaHora fecha;
        TipoAsis asistio;

        Usuario* Medico;
        Usuario* Paciente;
        vector<Diagnostico> Diagnosticos;


    public:
        Consulta();
        virtual ~Consulta();

        FechaHora getFecha();
        TipoAsis getAsistio();

        setFecha(FechaHora fecha);
        setAsistio(TipoAsis asis);

        string getCiPaciente();
        string getCiMedico();
        vector<Diagnostico> getDiagnosticos();
        agregarDiagnosticos(vector<Diagnostico> ldiag);
        ConsultaAsistida getConsultaAsistio();
        DiagnosticoTratamiento crearDiagnosticoTratamiento(DataDiagnostico dataDiag,
                                                           vector<DataTratamiento> dataTs);
};

#endif // CONSULTA_H
