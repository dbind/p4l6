#include "Consulta.h"

#include "Diagnostico.h"


TipoConsulta Consulta::tipo()
{
	return _tipo;
}

Usuario* Consulta::medico()
{
	return _medico;
}

Usuario* Consulta::paciente()
{
	return _paciente;
}

Fecha Consulta::fechaConsulta()
{
	return _consulta;
}


vector<Diagnostico*> Consulta::diagnosticos()
{
	return _diagnosticos;
}


void Consulta::agregarDiagnostico(Diagnostico* diagnostico)
{
	_diagnosticos.insert(_diagnosticos.begin(), diagnostico);
}