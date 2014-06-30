using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <bits/stl_vector.h>
#include <sstream>
#include <cstdlib>
#include <cstring>

#include "ComandosConsulta.h"
#include "FabricaControladores.h"
#include "Fecha.h"
#include "ConsultaComun.h"
#include "ConsultaUrgencia.h"

void ComandosConsulta::reservarConsulta()
{
	IControladorUsuario* cu = FabricaControladores::instancia()->controladorUsuario();
	IControladorConsulta* cc = FabricaControladores::instancia()->controladorConsulta();
	IControladorSesion* cs = FabricaControladores::instancia()->controladorSesion();

	vector<Usuario*> vectMedicos;
	vectMedicos = cu->listarMedicos();

	if (vectMedicos.empty())
	{
		cout << "No hay medicos." << endl;
	}
	else
	{    
		cout << "Lista de los medicos:" << endl;
		for(vector<Usuario*>::iterator it = vectMedicos.begin(); it != vectMedicos.end(); ++it)
		{
			Usuario* usuario = *it;
			string nombre, apellido, ci;
			nombre = usuario->getNombre();
			apellido = usuario->getApellido();
			ci = usuario->getCi();
			cout << nombre << " " << apellido << " " << ci << endl;

		}

		string cedula; 
		Usuario* paciente = cs->usuarioActivo();
		Usuario* medico;
		int diaConsulta, mesConsulta, anoConsulta; 
		cout << "Escribe la cedula del medico que va a atender la consulta: " << endl;
		cin >> cedula;

		cout << "Ahora elige la fecha de la consulta:" << endl;
		cout << "Dia: ";
		cin >> diaConsulta;
		cout << "Mes: ";
		cin >> mesConsulta;            
		cout << "Ano: ";
		cin >> anoConsulta;

		Fecha fechaReserva = FabricaControladores::instancia()->controladorSistema()->getFechaDelSistema();
		Fecha fechaConsulta =  Fecha(diaConsulta, mesConsulta, anoConsulta);
		medico = cu->findUsuario(cedula);
		
		Reserva* reserva = new Reserva(medico, paciente, fechaConsulta, fechaReserva);
		cc->altaReserva(reserva);
		
		cout << "La consulta fue reservada con exito!" << endl;
	}
}

void ComandosConsulta::cancelarReserva()
{
    IControladorConsulta* cc = FabricaControladores::instancia()->controladorConsulta();
    IControladorUsuario* cu = FabricaControladores::instancia()->controladorUsuario();
	Usuario* userActivo = FabricaControladores::instancia()->controladorSesion()->usuarioActivo();
    vector<Reserva*> reservas = cc->reservas();
    vector<Reserva*> reservasUsuario {};

	int contador = 1;
	cout << "Lista de las reservas:" << endl;

	for (vector<Reserva*>::iterator it = reservas.begin(); it != reservas.end(); ++it)
	{
		Reserva* reserva = *it;
		Usuario* paciente;
		Usuario* medico;
		Fecha fechaConsulta, fechaReserva;
		string nombrePaciente, apellidoPaciente, nombreMedico, apellidoMedico, ciPaciente, ciMedico;

		paciente = reserva->paciente();
		medico = reserva->medico();
		fechaConsulta = reserva->fechaConsulta();
		fechaReserva = reserva->fechaReserva();
		ciPaciente = paciente->getCi();
		nombreMedico = medico->getNombre();
		apellidoMedico = medico->getApellido();
		ciMedico = medico->getCi();

		if (ciPaciente == userActivo->getCi())
		{	
			cout << contador << "- ";
			cout << "Medico: " << nombreMedico << " " << apellidoMedico << endl;
			cout << "Fecha de consulta: " << fechaConsulta << endl;
			cout << "Fecha de reserva: " << fechaReserva <<  endl;
			contador++;

			reservasUsuario.push_back(reserva);
		}
	}

	if (reservasUsuario.size() == 0)
	{
		cout << "No se encontraron reservas activas" << endl;
	}
	else
	{
		cout << "Escriba el número correspondiente a la consulta a devolver (q para volver atrás)" << endl;
		string s;
		cin >> s;

		if (s == "q")
		{
			return;
		}

		char *cstr = new char[s.length() + 1];
		strcpy(cstr, s.c_str());
		int i = atoi(cstr);
		delete [] cstr;

		if (i > 0 && i <= reservasUsuario.size())
		{
			cc->removeReserva(reservasUsuario.at(i-1));
			cout << "La reserva de la consulta fue cancelada con exito!" << endl;
		}
		else
		{
			cout << "No existe una reserva con ese índice" << endl;
		}
	}
}

void ComandosConsulta::registrarConsulta()
{
    IControladorUsuario* cu = FabricaControladores::instancia()->controladorUsuario();
    IControladorConsulta* cc = FabricaControladores::instancia()->controladorConsulta();
    
    string ciMedico, ciPaciente, tipoConsulta, motivo;
    int diaReserva, diaConsulta, mesReserva, mesConsulta, anoReserva, anoConsulta;
    
    cout << "Ingresa la cedula del medico de la consulta: ";
    cin >> ciMedico;
    cout << endl << "Ingresa la cedula del paciente de la consulta: ";
    cin >> ciPaciente;
    
    Usuario* medico = cu->findUsuario(ciMedico);
    Usuario* paciente = cu->findUsuario(ciPaciente);
    
    cout << "Ingresa el tipo de consulta a registrar (comun o emergencia): " << endl;
    cin >> tipoConsulta;
    
    if (tipoConsulta == "comun")
    {
        cout << "Ingresa el dia de la reserva: " << endl;
        cin >> diaReserva;
        cout << "Ingresa el mes de la reserva: " << endl;
        cin >> mesReserva;
        cout << "Ingresa el ano de la reserva: " << endl;
        cin >> anoReserva;
         
        cout << "Ingresa el dia de la consulta: " << endl;
        cin >> diaConsulta;
        cout << "Ingresa el mes de la consulta: " << endl;
        cin >> mesConsulta;
        cout << "Ingresa el ano de la consulta: " << endl;
        cin >> anoConsulta;
        
        Fecha fechaConsulta = Fecha(diaConsulta, mesConsulta, anoConsulta);
        Fecha fechaReserva = Fecha(diaReserva, mesReserva, anoReserva);
        
		vector<Reserva*> reservasFecha = cc->listarReservasDia(fechaReserva);
		
		bool exito = false;
		
		for(vector<Reserva*>::iterator it = reservasFecha.begin(); it != reservasFecha.end(); ++it)
		{
			Reserva* reserva = *it;
			if ((reserva->medico()->getCi() == ciMedico) && (reserva->paciente()->getCi()==ciPaciente))
			{
				ConsultaComun* comun = new ConsultaComun(medico, paciente, fechaConsulta, fechaReserva);
				cc->consultas().push_back(comun);// Creo la consulta. 
				reserva->asistir();
				exito = true;
			}
		}
		
        if (exito)
			cout << "La consulta comun fue registrada con exito." << endl;
		else
			cout << "No existen reservas con los datos proporcionados." << endl;
		
    }
    
    else if (tipoConsulta == "emergencia")
    {
        cout << "Ingresa el dia de la consulta: " << endl;
        cin >> diaConsulta;
        cout << "Ingresa el mes de la consulta: " << endl;
        cin >> mesConsulta;
        cout << "Ingresa el ano de la consulta: " << endl;
        cin >> anoConsulta;
        
        cout << "Ingresa el motivo de la emergencia: ";
        cin >> motivo;
        
        Fecha fechaConsulta = Fecha(diaConsulta, mesConsulta, anoConsulta);
        
        ConsultaUrgencia* emergencia = new ConsultaUrgencia(medico, paciente, fechaConsulta, motivo);
        cc->consultas().push_back(emergencia);
        
        cout << "La consulta de emergencia fue registrada con exito." << endl;
    }
    
    else {cout << "Tipo de consulta invalido." << endl;}

}

void ComandosConsulta::altaDiagnosticosConsulta()
{
	
}
