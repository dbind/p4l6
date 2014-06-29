using namespace std;

#include <iostream>
#include <vector>
#include <string>

#include "ComandosConsulta.h"
#include "FabricaControladores.h"


void ComandosConsulta::reservarConsulta()
{
        vector<Usuario*> vectMedicos;
        vectMedicos = FabricaControladores::instancia()->controladorUsuario()::listarMedicos();
    
        if (vectMedicos.empty()) {cout << "No hay medicos." << endl;}
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
            Usuario* medico, paciente;
            int diaConsulta, mesConsulta, anoConsulta, horaConsulta, minutoConsulta; 
            int diaReserva, mesReserva, anoReserva, horaReserva, minutoReserva;
            cout << "Escribe la cedula del medico que va a atender la consulta" << endl;
            cout << "Cedula:";
            cin >> cedula >> endl;
                        
            cout << "Ahora elige la fecha y hora de la consulta" << endl;
            cout << "Dia :";
            cin >> diaConsulta >> endl;
            cout << "Mes :";
            cin >> mesConsulta >> endl;            
            cout << "Ano :";
            cin >> anoConsulta >> endl;
            cout << "Hora :";
            cin >> horaConsulta >> endl;            
            cout << "Minuto :";
            cin >> minutoConsulta >> endl;
            
            cout << "Ahora elige la fecha y hora de la consulta" << endl;
            cout << "Dia :";
            cin >> diaReserva >> endl;
            cout << "Mes :";
            cin >> mesReserva >> endl;            
            cout << "Ano :";
            cin >> anoReserva >> endl;
            cout << "Hora :";
            cin >> horaReserva >> endl;            
            cout << "Minuto :";
            cin >> minutoReserva >> endl;
            
            FechaHora fechaConsulta = new FechaHora(diaConsulta, mesConsulta, anoConsulta, horaConsulta, minutoConsulta);
            FechaHora fechaReserva = new FechaHora(diaReserva, mesReserva, anoReserva, horaReserva, minutoReserva);
            medico = FabricaControladores::instancia()->controladorUsuario()::findUsuario(cedula);
            paciente = FabricaControladores::instancia()->controladorSesion()::usuarioActivo();
            
            Reserva reserva = new Reserva(fechaConsulta, fechaReserva, medico, paciente);
            FabricaControladores::instancia()->controladorConsulta()::getReservas().push_back(reserva);
          
            cout << "La consuta fue reservada con exito!"
        }
        
}

void ComandosConsulta::cancelarReserva()
{
	
}

void ComandosConsulta::registrarConsulta()
{
	
}

void ComandosConsulta::altaDiagnosticosConsulta()
{
	
}
