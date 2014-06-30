using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <bits/stl_vector.h>

#include "ComandosConsulta.h"
#include "FabricaControladores.h"
#include "Fecha.h"




void ComandosConsulta::reservarConsulta()
{
    
        IControladorUsuario* cu = FabricaControladores::instancia()->controladorUsuario();
        IControladorConsulta* cc = FabricaControladores::instancia()->controladorConsulta();
        IControladorSesion* cs = FabricaControladores::instancia()->controladorSesion();
        
        vector<Usuario*> vectMedicos;
        vectMedicos = cu->listarMedicos();
    
        if (vectMedicos.empty())  {cout << "No hay medicos." << endl;}
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
            int diaReserva, mesReserva, anoReserva;
            cout << "Escribe la cedula del medico que va a atender la consulta" << endl;
            cout << "Cedula:" << endl;
            cin >> cedula ;
                        
            cout << "Ahora elige la fecha y hora de la consulta" << endl;
            cout << "Dia :"<< endl;
            cin >> diaConsulta ;
            cout << "Mes :"<< endl;
            cin >> mesConsulta ;            
            cout << "Ano :" << endl;
            cin >> anoConsulta ;
                        
            cout << "Ahora elige la fecha y hora de la consulta" << endl;
            cout << "Dia :" << endl;
            cin >> diaReserva ;
            cout << "Mes :" << endl;
            cin >> mesReserva ;            
            cout << "Ano :" << endl;
            cin >> anoReserva ;
            
            
            Fecha fechaConsulta =  Fecha(diaConsulta, mesConsulta, anoConsulta);
            Fecha fechaReserva =  Fecha(diaReserva, mesReserva, anoReserva);
            medico = cu->findUsuario(cedula);
            
            
            Reserva* reserva = new Reserva(medico, paciente,fechaConsulta, fechaReserva);
            cc->getReservas().push_back(reserva);
          
           cout << "La consulta fue reservada con exito!";
        }
        
}

void ComandosConsulta::cancelarReserva()
{
    IControladorConsulta* cc = FabricaControladores::instancia()->controladorConsulta();
    IControladorUsuario* cu = FabricaControladores::instancia()->controladorUsuario();
    vector<Reserva*> reservas = cc->getReservas();
    
    if (reservas.empty()) {cout << "No hay reservas." << endl;}
    else
    {
       cout << "Lista de las reservas" << endl;
        for(vector<Reserva*>::iterator it = reservas.begin(); it != reservas.end(); ++it)
            {
                    Reserva* reserva = *it;
                    Usuario* paciente;
                    Usuario* medico;
                    Fecha fechaConsulta, fechaReserva;
                    string nombrePaciente, apellidoPaciente, nombreMedico, apellidoMedico, ciPaciente, ciMedico ;
                    int diaConsulta, mesConsulta, anoConsulta;
                    int diaReserva, mesReserva, anoReserva;
                    
                    paciente = reserva->paciente();
                    medico = reserva->medico();
                    fechaConsulta = reserva->fechaConsulta();
                    fechaReserva = reserva->fechaReserva();
                    
                    nombrePaciente = paciente->getNombre();
                    apellidoPaciente = paciente->getApellido();
                    ciPaciente = paciente->getCi();
                    nombreMedico = medico->getNombre();
                    apellidoMedico = medico->getApellido();
                    ciMedico = medico->getCi();
                    
                    diaConsulta = fechaConsulta.dia();
                    mesConsulta = fechaConsulta.mes();
                    anoConsulta = fechaConsulta.anyo();
                    
                    
                    diaReserva = fechaReserva.dia();
                    mesReserva = fechaReserva.mes();
                    anoReserva = fechaReserva.anyo();
                    
                    
                    cout <<"Paciente :" << nombrePaciente << " " << apellidoPaciente << ", Medico :" << nombreMedico << " " << apellidoMedico << ", Fecha de consulta :" << diaConsulta << "/" << mesConsulta << "/" << anoConsulta <<  ", Fecha de reserva :" << diaReserva << "/" << mesReserva << "/" << anoReserva <<  endl;
                
            }
       
        cout << "Elige la consulta a devolver:" << endl;
        Usuario* paciente;
        Usuario* medico;
        string ciPaciente, ciMedico ;
        int diaConsulta, mesConsulta, anoConsulta;
        int diaReserva, mesReserva, anoReserva;
        
        cout << "Cedula del paciente :" ;
        cin >> ciPaciente ;
        
        cout << "Cedula del medico :" ;
        cin >> ciMedico ;
        
        
        cout << "Dia de la consulta :" ;
        cin >> diaConsulta ;
        cout << "Mes de la consulta :" ;
        cin >> mesConsulta ;
        cout << "Ano de la consulta :" ;
        cin >> anoConsulta ;
        
        
        cout << "Dia de la reserva :" ;
        cin >> diaReserva ;
        cout << "Mes de la reserva :" ;
        cin >> mesReserva ;
        cout << "Ano de la reserva :" ;
        cin >> anoReserva ;
        

        Fecha fechaConsulta = Fecha(diaConsulta, mesConsulta, anoConsulta);
        Fecha fechaReserva = Fecha(diaReserva, mesReserva, anoReserva);
        medico = cu->findUsuario(ciMedico);
        paciente = cu->findUsuario(ciPaciente);
        
//        cc->removeReserva(medico, paciente, fechaConsulta, fechaReserva);
//        reserva::~Reserva();
    }
    
    cout << "La consulta fue devuelta con exito!";
}
void ComandosConsulta::registrarConsulta()
{
	
}

void ComandosConsulta::altaDiagnosticosConsulta()
{
	
}
