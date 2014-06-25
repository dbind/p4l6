#include "../include/Consulta.h"

Consulta::Consulta()
{
    // TODO
}

Consulta::~Consulta()
{
    // TODO
}


Fecha Consulta::getFecha()
{
    return this->fecha;
}

TipoAsis Consulta::getAsistio()
{
    return this->asistio;
}


Consulta::setFecha(Fecha fecha)
{
    this->fecha = fecha;
}

Consulta::setAsistio(TipoAsis asistio)
{
    this->asistio = asistio;
}


string Consulta::getCiPaciente()
{
    return this->Paciente->getCi();
}

string Consulta::getCiMedico()
{
    return this->Medico->getCi();
}

vector<Diagnostico> Consulta::getDiagnosticos()
{
    return this->Diagnosticos;
}

Consulta::agregarDiagnosticos(vector<Diagnostico> ldiag)
{
    // TODO
}

ConsultaAsistida Consulta::getConsultaAsistio()
{
    // TODO
}

DiagnosticoTratamiento Consulta::crearDiagnosticoTratamiento(DataDiagnostico dataDiag,
                                                             vector<DataTratamiento> dataTs)
{
    // TODO
}
