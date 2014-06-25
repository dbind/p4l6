#include "../include/ControladorConsulta.h"


ControladorConsulta* ControladorConsulta::instancia()
{
    if (this->_instancia == 0)
        this->_instancia = new ControladorConsulta;

    return this->_instancia;
}


vector<Consulta*> ControladorConsulta::getConsultas()
{
    return this->consultas;
}

vector<Diagnostico*> ControladorConsulta::getDiagnosticos()
{
    return this->diagnosticos;
}

vector<ConsultaAsistida> ControladorConsulta::getConsultasAsistidas()
{
    return this->consultasAsistidas;
}

Consulta ControladorConsulta::getConsultaSeleccionada()
{
    return this->consultaSelecciada;
}

ControladorConsulta::setConsultas(vector<Consulta*> consultas)
{
    this->consultas = consultas;
}

ControladorConsulta::setDiagnosticos(vector<Diagnostico*> diagnosticos)
{
    this->diagnosticos = diagnosticos;
}

ControladorConsulta::setConsultasAsistidas(vector<ConsultaAsistida> consultasAsistidas)
{
    this->consultasAsistidas = consultasAsistidas;
}

ControladorConsulta::setConsultaSeleccionada(Consulta consultaSeleccionada)
{
    this->consultaSeleccionada = consultaSeleccionada;
}


vector<string> ControladorConsulta::listarCiPacientesConsultasPorFecha(Fecha dia)
{
    // TODO
}

ControladorConsulta::seleccionarConsulta(string ci)
{
    // TODO
}

ControladorConsulta::aceptarDiagnostico()
{
    // TODO
}

ControladorConsulta::guardarDiagnosticosAceptados()
{
    // TODO
}

ControladorConsulta::cancelarDiagnosticosConsulta()
{
    // TODO
}

ControladorConsulta::cancelarEdicionConsulta()
{
    // TODO
}

vector<Consulta*> ControladorConsulta::listarConsultasActivas(vector<Consulta,> FechaHora fecha)
{
    // TODO
}

ControladorConsulta::borrarReserva(FechaHora fecha)
{
    // TODO
}

vector<string> ControladorConsulta::obtenerListaCiPacientes(vector<Consulta*> consultas)
{
    // TODO
}

Historial ControladorConsulta::crearHistorial(Usuario paciente, vector<Consulta*> consultas)
{
    // TODO
}

ControladorConsulta::ingresarPacienteMedico(string ciPaciente, string ciMedico)
{
    // TODO
}

ControladorConsulta::registrarConsultaComun(FechaHora fechaReserva, FechaHora fechaConsulta)
{
    // TODO
}

ControladorConsulta::registrarConsultaEmergencia(string motivo, FechaHora fechaConsulta)
{
    // TODO
}
