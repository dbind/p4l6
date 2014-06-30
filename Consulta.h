#ifndef CONSULTA_H
#define CONSULTA_H

#include <string>
#include <vector>

#include "Usuario.h"
//#include "Diagnostico.h"
#include "FechaHora.h"
#include "Hora.h"
#include "TipoAsis.h"

class Consulta
{
    private:
        FechaHora fecha;
        TipoAsis asistio;

        Usuario* Medico;
        Usuario* Paciente;
        //vector<Diagnostico> Diagnosticos;


    public:
        Consulta();
        virtual ~Consulta();

        FechaHora getFecha();
        TipoAsis getAsistio();

        setFecha(FechaHora fecha);
        setAsistio(TipoAsis asis);

        string getCiPaciente();
        string getCiMedico();
  
};

#endif // CO