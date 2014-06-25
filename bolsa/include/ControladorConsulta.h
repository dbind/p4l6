#ifndef CONTROLADORCONSULTA_H
#define CONTROLADORCONSULTA_H

#include <vector>
#include <string>

#include "../interfaces/Singleton.h"

#include "../includes/Consulta.h"
#include "../includes/ConsultaAsistida.h"
#include "../includes/Diagnostico.h"
#include "../includes/Fecha.h"
#include "../includes/FechaHora.h"
#include "../includes/Usuario.h"
#include "../includes/Historial.h"


class ControladorConsulta : public Singleton
{
    private:
        ControladorConsulta() = 0;
        static ControladorConsulta* _instancia;

        vector<Consulta*> consultas;
        vector<Diagnostico*> diagnosticos;
        vector<ConsultaAsistida> consultasAsistidas;
        Consulta consultaSeleccionada;

    public:
        static ControladorConsulta* instancia();

        vector<Consulta*> getConsultas();
        vector<Diagnostico*> getDiagnosticos();
        vector<ConsultaAsistida> getConsultasAsistidas();
        Consulta getConsultaSeleccionada();
        setConsultas(vector<Consulta*> consultas);
        setDiagnosticos(vector<Diagnostico*> diagnosticos);
        setConsultasAsistidas(vector<ConsultaAsistida> consultasAsistidas);
        setConsultaSeleccionada(Consulta consultaSeleccionada);

        vector<string> listarCiPacientesConsultasPorFecha(Fecha dia);
        seleccionarConsulta(string ci);
        aceptarDiagnostico();
        guardarDiagnosticosAceptados();
        cancelarDiagnosticosConsulta();
        cancelarEdicionConsulta();
        vector<Consulta*> listarConsultasActivas(vector<Consulta,> FechaHora fecha);
        borrarReserva(FechaHora fecha);
        vector<string> obtenerListaCiPacientes(vector<Consulta*> consultas);
        Historial crearHistorial(Usuario paciente, vector<Consulta*> consultas);
        ingresarPacienteMedico(string ciPaciente, string ciMedico);
        registrarConsultaComun(FechaHora fechaReserva, FechaHora fechaConsulta);
        registrarConsultaEmergencia(string motivo, FechaHora fechaConsulta);
};

#endif // CONTROLADORCONSULTA_H
