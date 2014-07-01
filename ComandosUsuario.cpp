using namespace std;


#include <iostream>
#include <vector>

#include "ComandosUsuario.h"
#include "Usuario.h"
#include "FabricaControladores.h"
#include "Fecha.h"
#include "Tratamiento.h"
#include "TratamientoFarmacologico.h"
#include "TratamientoQuirurgico.h"


void ComandosUsuario::altaReactivacionUsuario()
{
	IControladorUsuario* cUsuario = FabricaControladores::instancia()->controladorUsuario()->instancia();
	bool exito;
	Usuario* newUser;
	
	do
		
	{
		exito = true;
		string ci;
		cout << "Ingrese la Cedula de Identidad del Usuario (o presione q para salir): " << endl;
		cin >> ci;

		if (ci=="q")
			return;

		if (cUsuario->findUsuario(ci) != NULL)
		{
			cout << "El usuario ya existe en el sistema. " << endl;
			Usuario* usuario = cUsuario->findUsuario(ci);
			cout << "Nombre: "   << usuario->getNombre() << endl;
			cout << "Apellido: " << usuario->getApellido() << endl;
			if (usuario->getGenero() == Genero::femenino)
				cout << "Sexo: Femenino" << endl;
			else
			{
				if (usuario->getGenero() == Genero::indeterminado)
					cout << "Sexo: Indeterminado" << endl;
				else
					cout << "Sexo: Masculino" << endl;
			}		

			cout << "Edad: " << usuario->edad() << endl;
			
			vector<Rol> roles;
			for (vector<Rol>::iterator it = usuario->roles().begin(); it != usuario->roles().end(); ++it)
			{
				Rol rol = *it;
			if (rol == Rol::admin)
				cout << "Rol: Admin" << endl;

			if (rol == Rol::medico)
				cout << "Rol: Medico" << endl;

			if (rol == Rol::socio)
				cout << "Rol: Socio" << endl;

			if (rol == Rol::master)
				cout << "Rol: Master" << endl;			
			}
			
			if (usuario->estaActivo())
				cout << "Estado: Activo" << endl;
//				roles.insert(roles.begin(), rol);	
			else
			{
				cout << "Estado: Inactivo" << endl;
				cout << "¿Desea reactivar el usuario? (y/n)?" << endl;
				string reactivar;
				cin >> reactivar;
				if (reactivar=="y")
				{
					usuario->activar();
					cout << "El usuario ha sido reactivado." << endl;
				}
			}	
		}
		else
		{
			string nombre;
			string apellido;
			Fecha fechaNac;
			string gen;
			string r1, r2;
			Genero genero;
			Roles roles {};

			cout << "Ingrese el nombre del Usuario: " << endl;
			cin >> nombre;

			cout << "Ingrese el apellido del Usuario: " << endl;
			cin >> apellido;

			cout << "Ingrese el sexo (M/f): " << endl;
			cin >> gen;

			if (gen=="f")
				genero = Genero::femenino;
			else
				genero = Genero::masculino;

			int dia, mes, anyo;

			cout << "Ingrese el dia del nacimiento: " << endl;
			cin >> dia;
			cout << "Ingrese el mes del nacimiento: " << endl;
			cin >> mes;
			cout << "Ingrese el anyo del nacimiento: " << endl;
			cin >> anyo;

			fechaNac = Fecha(dia, mes, anyo);

			cout << "Ingrese el primer rol [a(dmin), m(edico), s(ocio)]: " << endl;
			cin >> r1;

			cout << "Ingrese el segundo rol (n para omitir): " << endl;
			cin >> r2;
			
			if (r1 == "a")
			{
				roles.push_back(Rol::admin);
			}
			else if (r1 == "m")
			{
				roles.push_back(Rol::medico);
			}
			else // socio por defecto
			{
				roles.push_back(Rol::socio);
			}
			
			if (r2 == "a")
			{
				if (r1 == "m")
				{
					cout << "Error, el usuario no puede ser medico y administrativo a la vez." << endl;
					exito = false;
				}
				else
					roles.push_back(Rol::admin);
			}
			else if (r2 == "m")
			{	if (r1 == "a")
				{
					cout << "Error, el usuario no puede ser medico y administrativo a la vez." << endl;
					exito = false;
				}
				else
					roles.push_back(Rol::medico);
			}
			else if (r2 != "n") // socio por defecto
			{
				roles.push_back(Rol::socio);
			}
			
			if (exito)
			{
				newUser = cUsuario->altaUsuario(ci, nombre, apellido, genero, fechaNac, roles);
				cout << "El usuario fue dado de alta con exito." << endl;
			}
			else
				cout << "Ocurrió un error imprevisto." << endl;
		}
	}
	while (true);
}

void ComandosUsuario::listarAltasReactivaciones()
{
	Usuario* userActivo = FabricaControladores::instancia()->controladorSesion()->usuarioActivo();
	
	vector<Usuario*> dadosDeAlta = userActivo->dadosDeAlta();
	vector<Usuario*> reactivados = userActivo->reactivados();
	
	vector<Usuario*>::iterator it;
	
    for (it=dadosDeAlta.begin(); it != dadosDeAlta.end(); ++it)
    {
		Usuario* usuario = *it;
		cout << "--------------------------------------------------------------------" << endl;
		cout << "Fecha del Alta: " << usuario->fechaAlta() << endl;
		
		cout << "Tipo de Operación: Alta" << endl;

        cout << "Nombre: "   << usuario->getNombre() << endl;
		cout << "Apellido: " << usuario->getApellido() << endl;
		cout << "Cedula: " << usuario->getCi() << endl;
		cout << "Edad: " << usuario->edad() << endl;
		
		if (usuario->estaActivo())
			cout << "Estado: Activo" << endl;
		else
			cout << "Estado: Inactivo" << endl;
				
    }
	
	vector<Usuario*>::iterator it1;
	
    for (it1=reactivados.begin(); it1 != reactivados.end(); ++it1)
    {
		Usuario* usuario = *it1;
		
		cout << "Fecha del Alta: " << usuario->fechaReactivacion() << endl;
		
		cout << "Tipo de Operación: Reactivación" << endl;

        cout << "Nombre: "   << usuario->getNombre() << endl;
		cout << "Apellido: " << usuario->getApellido() << endl;
		cout << "Cedula: " << usuario->getCi() << endl;
		cout << "Edad: " << usuario->edad() << endl;
		
		if (usuario->estaActivo())
			cout << "Estado: Activo" << endl;
		else
			cout << "Estado: Inactivo" << endl;
    }

}

void ComandosUsuario::verHistorial()
{
	string ci;
	cout << "Ingrese la Cedula de Identidad del Usuario (o presione q para salir): " << endl;
	cin >> ci;
	
	
	IControladorUsuario* cUsuario = FabricaControladores::instancia()->controladorUsuario()->instancia();
	
	if (ci=="q")
		return;
	
	if (cUsuario->findUsuario(ci) != NULL)
	{
		Usuario* usuario = cUsuario->findUsuario(ci);
		cout << "Nombre: "   << usuario->getNombre() << endl;
		cout << "Apellido: " << usuario->getApellido() << endl;
		cout << "Fecha de nacimiento: " << usuario->getFechaNac() <<endl;
		
		vector<Consulta*> consultas = usuario->consultas();
		for(vector<Consulta*>::iterator it = consultas.begin(); it != consultas.end(); ++it)
		{
			cout << "-------------------------------------------------------------------------------" << endl;
			Consulta* consulta = *it;
			cout << "Fecha de la consulta: " << consulta->fechaConsulta() << endl;
			if (consulta->tipo() == TipoConsulta::comun)
				cout << "Tipo de la consulta: Comun" << endl;
			else
				cout << "Tipo de la consulta: Emergencia" << endl;
			cout << "Nombre y apellido del medico: " << consulta->medico()->getNombre() 
				 << " " << consulta->medico()->getApellido() << endl;
			// REPRESENTACIONES ESTANDARIZADAS Y TRATAMIENTOS.
			vector<Diagnostico*> diagnosticos = consulta->diagnosticos();
			for(vector<Diagnostico*>::iterator it1 = diagnosticos.begin(); it1 != diagnosticos.end(); ++it1)
			{
				Diagnostico* diagnostico = *it1;
				cout << "Representacion estandarizada de diagnostico: " << diagnostico->representacion().codigo() <<
						" " << diagnostico->representacion().etiqueta() << endl;
				cout << "Descripcion del diagnostico: " << diagnostico->descripcion() << endl;
				
				//TRATAMIENTOS FARMACOLOGICOS.
				vector<TratamientoFarmacologico*> tratamientosFar = diagnostico->tratamientosFarmacologicos();
				for(vector<TratamientoFarmacologico*>::iterator it2 = tratamientosFar.begin(); it2 != tratamientosFar.end(); it2++)
				{
					TratamientoFarmacologico* tratamientoFar = *it2;
					cout << "Descripcion del tratamiento: " << tratamientoFar->descripcion() << endl;
					//FARMACOS ASIGNADOS. 
					vector<Farmaco*> farmacos = tratamientoFar->farmacos();
					cout << "Farmacos asignados: " << endl;
					for(vector<Farmaco*>::iterator it3 = farmacos.begin(); it3 != farmacos.end(); ++it3)
					{
						Farmaco* farmaco = *it3;
						cout << farmaco->getNombre() << endl;
					}					
				}
				//TRATAMIENTOS QUIRURGICOS.
				vector<TratamientoQuirurgico*> tratamientosQuir = diagnostico->tratamientosQuirurgicos();
				for(vector<TratamientoQuirurgico*>::iterator it4 = tratamientosQuir.begin(); it4 != tratamientosQuir.end(); ++it4)
				{
					TratamientoQuirurgico* tratamientoQuir = *it4;
					cout << "Descripcion del tratamiento: " << tratamientoQuir->descripcion() << endl;
				}			
			}			
		}
	}
	else
		cout << "El usuario no se enuentra en el sistema." << endl;
}
