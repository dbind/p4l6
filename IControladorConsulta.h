#ifndef ICONTROLADORCONSULTA_H
#define	ICONTROLADORCONSULTA_H

using namespace std;

#include <vector>
#include <string>
#include "Reserva.h"

//#include "Consulta.h"
//#include "ConsultaAsistida.h"
//#include "Diagnostico.h"
//#include "Fecha.h"
//#include "FechaHora.h"
//#include "Usuario.h"
//#include "Historial.h"


class IControladorConsulta
{

public:
	virtual ~IControladorConsulta(){};

//	vector<Consulta*> getConsultas();
//	vector<Diagnostico*> getDiagnosticos();
//	vector<ConsultaAsistida> getConsultasAsistidas();
//	Consulta getConsultaSeleccionada();
//	setConsultas(vector<Consulta*> consultas);
//	setDiagnosticos(vector<Diagnostico*> diagnosticos);
//	setConsultasAsistidas(vector<ConsultaAsistida> consultasAsistidas);
//	setConsultaSeleccionada(Consulta consultaSeleccionada);
//
//	vector<string> listarCiPacientesConsultasPorFecha(Fecha dia);
//	seleccionarConsulta(string ci);
//	aceptarDiagnostico();
//	guardarDiagnosticosAceptados();
//	cancelarDiagnosticosConsulta();
//	cancelarEdicionConsulta();
//	vector<Consulta*> listarConsultasActivas(vector<Consulta,> FechaHora fecha);
//	borrarReserva(FechaHora fecha);
//	vector<string> obtenerListaCiPacientes(vector<Consulta*> consultas);
//	Historial crearHistorial(Usuario paciente, vector<Consulta*> consultas);
//	ingresarPacienteMedico(string ciPaciente, string ciMedico);
//	registrarConsultaComun(FechaHora fechaReserva, FechaHora fechaConsulta);
//	registrarConsultaEmergencia(string motivo, FechaHora fechaConsulta);

protected:
//	vector<Consulta*> consultas;
//	vector<Diagnostico*> diagnosticos;
//	vector<ConsultaAsistida> consultasAsistidas;
//	Consulta consultaSeleccionada;
        vector<Reserva*> reservas;

};

#endif	/* ICONTROLADORCONSULTA_H */