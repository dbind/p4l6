using namespace std;

#include <sstream>
#include <iostream>
#include <vector>
#include <string>

#include "ComandosSistema.h"

#include "FabricaControladores.h"
#include "Usuario.h"
#include "Representacion.h"
#include "Diagnostico.h"
#include "Consulta.h"
#include "ConsultaComun.h"
#include "ConsultaUrgencia.h"
#include "Farmaco.h"
#include "Tratamiento.h"
#include "TratamientoFarmacologico.h"
#include "TratamientoQuirurgico.h"

#include "Categoria.h"
#include "Genero.h"
#include "Rol.h"



void ComandosSistema::setTime()
{
	string s_dia, s_mes, s_anyo;
	int i_dia, i_mes, i_anyo;

	cout << "Ingrese el día:" << endl;
	cin >> s_dia;
	istringstream(s_dia) >> i_dia;

	cout << "Ingrese el mes:" << endl;
	cin >> s_mes;
	istringstream(s_mes) >> i_mes;

	cout << "Ingrese el anyo:" << endl;
	cin >> s_anyo;
	istringstream(s_anyo) >> i_anyo;

	Fecha fecha = Fecha(i_dia, i_mes, i_anyo);
	FabricaControladores::instancia()->controladorSistema()->setFechaDelSistema(fecha);
}

void ComandosSistema::getTime()
{
	cout << "La fecha actual es: "
	     << FabricaControladores::instancia()->controladorSistema()->getFechaDelSistema()
	     << endl;
}

void ComandosSistema::loadTestData()
{
	FabricaControladores* Fabrica = FabricaControladores::instancia();
	
	IControladorSesion*      cSesion      = Fabrica->controladorSesion();
	IControladorUsuario*     cUsuario     = Fabrica->controladorUsuario();
	IControladorConsulta*    cConsulta    = Fabrica->controladorConsulta();
	IControladorFarmaco*     cFarmaco     = Fabrica->controladorFarmaco();
	IControladorDiagnostico* cDiagnostico = Fabrica->controladorDiagnostico();
	IControladorSistema*     cSistema     = Fabrica->controladorSistema();

	cSistema    ->reset();
	cUsuario    ->reset();
	cConsulta   ->reset();
	cFarmaco    ->reset();
	cDiagnostico->reset();

	// Usuarios
	Genero M = Genero::masculino;
	Genero F = Genero::femenino;

	// Los casos de uso deben aparecer como ejecutados por James Peer
	Usuario* uLogueado = cSesion->usuarioActivo();

	Usuario* JA = cUsuario->altaUsuario("34567645", "James" , "Peer"    , M, Fecha(28, 12, 1988), Roles{Rol::socio});
	cSesion->iniciarSesionInterno(JA);

	Usuario* TM = cUsuario->altaUsuario("34562345", "Tifany", "McKensey", F, Fecha( 1,  1, 1990), Roles{Rol::socio});
	Usuario* DP = cUsuario->altaUsuario("12345435", "Diego" , "Perez"   , M, Fecha( 3,  3, 1980), Roles{Rol::socio});
	Usuario* JM = cUsuario->altaUsuario("65436667", "Juan"  , "Montoya" , M, Fecha( 7,  4, 1970), Roles{Rol::socio, Rol::medico});
	Usuario* DC = cUsuario->altaUsuario("43521343", "Debora", "Corral"  , F, Fecha(13,  7, 1993), Roles{Rol::medico});
	Usuario* AL = cUsuario->altaUsuario("98056743", "Ana"   , "Lopez"   , F, Fecha(24,  9, 1981), Roles{Rol::medico});

	cSesion->iniciarSesionInterno(uLogueado); // Restaurar sesión previa


	// Consultas
	Consulta* C1 = new ConsultaComun(JM, TM, Fecha(23, 6, 2014), Fecha(21, 6, 2014));
	Consulta* C2 = new ConsultaComun(DC, TM, Fecha(22, 6, 2014), Fecha(22, 5, 2014));
	Consulta* C3 = new ConsultaComun(DC, JM, Fecha(16, 3, 2014), Fecha(15, 3, 2014));
	Consulta* C4 = new ConsultaComun(AL, DP, Fecha( 1, 3, 2014), Fecha(28, 2, 2014));
	Consulta* U1 = new ConsultaUrgencia(JM, TM, Fecha(23, 5, 2014), "Fiebre alta");
	Consulta* U2 = new ConsultaUrgencia(DC, JM, Fecha(24, 5, 2014), "Asma");
	Consulta* U3 = new ConsultaUrgencia(AL, JM, Fecha( 3, 3, 2014), "Mareos");

	cConsulta->altaConsulta(C1);
	cConsulta->altaConsulta(C2);
	cConsulta->altaConsulta(C3);
	cConsulta->altaConsulta(C4);
	cConsulta->altaConsulta(U1);
	cConsulta->altaConsulta(U2);
	cConsulta->altaConsulta(U3);


	// Categorías (Código, Etiqueta)
	Categoria X1 = cDiagnostico->agregarCategoria('A', "Afecciones pulmonares");
	Categoria X2 = cDiagnostico->agregarCategoria('B', "Aparato Digestivo");


	// Representaciones (Categoría, Código, Descripción)
	Representacion R1 = cDiagnostico->altaRepresentacion(X1, "01", "Asma");
	Representacion R2 = cDiagnostico->altaRepresentacion(X1, "02", "Congestión");
	Representacion R3 = cDiagnostico->altaRepresentacion(X2, "01", "Nauseas");
	

	// Diagnósticos (Consulta, Representación, Descripción)
	Diagnostico* D1 = cDiagnostico->altaDiagnostico(C1, R2, "Desc 1");
	Diagnostico* D2 = cDiagnostico->altaDiagnostico(C1, R3, "Desc 2");
	Diagnostico* D3 = cDiagnostico->altaDiagnostico(C3, R2, "Desc 3");
	Diagnostico* D4 = cDiagnostico->altaDiagnostico(U1, R3, "Desc 4");
	Diagnostico* D5 = cDiagnostico->altaDiagnostico(U2, R1, "Desc 5");
	Diagnostico* D6 = cDiagnostico->altaDiagnostico(U2, R2, "Desc 6");


	// Fármacos (Nombre)
	Farmaco* M1 = cFarmaco->darDeAltaFarmaco("M1");
	Farmaco* M2 = cFarmaco->darDeAltaFarmaco("M2");
	Farmaco* M3 = cFarmaco->darDeAltaFarmaco("M3");


	// Tratamientos (Diagnóstico, Fármaco, Descripción)
	TratamientoFarmacologico* F1 = cDiagnostico->agregarTratamientoFarmacologico(D1, M1, "Desc 1");
	TratamientoFarmacologico* F2 = cDiagnostico->agregarTratamientoFarmacologico(D1, M2, "Desc 2");
	TratamientoFarmacologico* F3 = cDiagnostico->agregarTratamientoFarmacologico(D1, M3, "Desc 3");
	TratamientoFarmacologico* F4 = cDiagnostico->agregarTratamientoFarmacologico(D4, M1, "Desc 4");
	TratamientoFarmacologico* F5 = cDiagnostico->agregarTratamientoFarmacologico(D5, M2, "Desc 5");
	TratamientoFarmacologico* F6 = cDiagnostico->agregarTratamientoFarmacologico(D6, M3, "Desc 6");

	TratamientoQuirurgico* Q1 = cDiagnostico->agregarTratamientoQuirurgico(D2, JM, Fecha(25, 7, 2014), "Desc 11");
	TratamientoQuirurgico* Q2 = cDiagnostico->agregarTratamientoQuirurgico(D3, DC, Fecha( 1, 2, 2015), "Desc 22");


	// Suscripciones
	cUsuario->suscribir(JM, TM, Fecha(22, 3, 2013));
	cUsuario->suscribir(JM, TM, Fecha(25, 6, 2014));
}


void ComandosSistema::listarReservas()
{
	vector<Reserva*> l = FabricaControladores::instancia()->controladorConsulta()->reservas();
	vector<Reserva*>::iterator it = l.begin();
	
	Fecha fecha = FabricaControladores::instancia()->controladorSistema()->getFechaDelSistema();

	for (; it != l.end(); ++it)
	{
		string asistencia = ((*it)->fechaConsulta() < fecha)
			? ((*it)->asistio() ? "Si" : "No")
			: "No corresponde (reserva pendiente)";

		cout << "Médico: " << (*it)->medico()->getNombre() << " " << (*it)->medico()->getApellido() << endl
		     << "Paciente: " << (*it)->paciente()->getNombre() << " " << (*it)->paciente()->getApellido() << endl
		     << "Fecha Reserva: " << (*it)->fechaReserva() << endl
		     << "Fecha Consulta: " << (*it)->fechaConsulta() << endl
		     << "Asistió: " << asistencia << endl << endl;
	}
}

void ComandosSistema::listarConsultas()
{
	vector<Consulta*> l = FabricaControladores::instancia()->controladorConsulta()->consultas();
	vector<Consulta*>::iterator it = l.begin();

	Fecha fecha = FabricaControladores::instancia()->controladorSistema()->getFechaDelSistema();

	for (; it != l.end(); ++it)
	{
		string tipo = ((*it)->tipo() == TipoConsulta::comun) ? "Comun" : "Urgencia";
			
		cout << "Médico: " << (*it)->medico()->getNombre() << " " << (*it)->medico()->getApellido() << endl
		     << "Paciente: " << (*it)->paciente()->getNombre() << " " << (*it)->paciente()->getApellido() << endl
		     << "Fecha Consulta: " << (*it)->fechaConsulta() << endl
		     << "Tipo de Consulta: " << tipo << endl;

		if ((*it)->tipo() == TipoConsulta::comun)
		{
			ConsultaComun* comun = (ConsultaComun*)*it;

			string asistencia = (comun->fechaConsulta() < fecha)
				? (comun->reserva()->asistio() ? "Si" : "No")
				: "No corresponde (reserva pendiente)";

			cout << "Fecha Reserva: " << comun->reserva()->fechaReserva() << endl
			     << "Asistió: " << asistencia << endl << endl;

		}
		else
		{
			ConsultaUrgencia* urgente = (ConsultaUrgencia*)*it;

			cout << "Descripción: " << urgente->descripcion() << endl << endl;
		}
	}	
}

void ComandosSistema::listarUsuarios()
{
	vector<Usuario*> l = FabricaControladores::instancia()->controladorUsuario()->usuarios();
	vector<Usuario*>::iterator it = l.begin();

	for (; it != l.end(); ++it)
	{
		Usuario* item = *it;
		cout << item->getNombre() << " " << item->getApellido()
		     << ", " << item->edad() << " años"
		     << " (CI " << item->getCi() << ")" << endl;

		cout << "Rol(es):";

		for (Roles::iterator itr = item->roles().begin(); itr != item->roles().end(); ++itr)
		{
			cout << " " << *itr;
		}

		cout << endl << endl;
	}
}

void ComandosSistema::listarFarmacos()
{
	vector<Farmaco*> l = FabricaControladores::instancia()->controladorFarmaco()->farmacos();
	vector<Farmaco*>::iterator it = l.begin();

	for (; it != l.end(); ++it)
	{
		cout << (*it)->getNombre() << endl;
	}
}

void ComandosSistema::listarCategorias()
{
	vector<Categoria> l = FabricaControladores::instancia()->controladorDiagnostico()->categorias();
	vector<Categoria>::iterator it = l.begin();

	for (; it != l.end(); ++it)
	{
		cout << (*it).codigo() << " (" << (*it).etiqueta() << ")" << endl;
	}
}

void ComandosSistema::listarRepresentaciones()
{
	vector<Representacion> l = FabricaControladores::instancia()->controladorDiagnostico()->representaciones();
	vector<Representacion>::iterator it = l.begin();

	for (; it != l.end(); ++it)
	{
		cout << "[" << (*it).categoria().codigo() << "] "
		     << (*it).codigo() << " (" << (*it).etiqueta() << ")" << endl;
	}
}
