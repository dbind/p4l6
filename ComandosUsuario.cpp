using namespace std;


#include <iostream>
#include <vector>

#include "ComandosUsuario.h"
#include "Usuario.h"
#include "FabricaControladores.h"
#include "Fecha.h"


void ComandosUsuario::altaReactivacionUsuario()
{
	IControladorUsuario* cUsuario = FabricaControladores::instancia()->controladorUsuario()->instancia();
	
	do
		
	{
	
		string ci;
		cout << "Ingrese la Cedula de Identidad del Usuario (o presione q para salir): " << endl;
		cin >> ci;

		if (ci=="q")
			return;

		if (cUsuario->findUsuario(ci) != NULL)
		{
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
					cout << "El usuario ha sido reactivado" << endl;
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
				roles.push_back(Rol::admin);
			}
			else if (r2 == "m")
			{
				roles.push_back(Rol::medico);
			}
			else if (r2 != "n") // socio por defecto
			{
				roles.push_back(Rol::socio);
			}

			Usuario* newUser = cUsuario->altaUsuario(ci, nombre, apellido, genero, fechaNac, roles); // POR AHORA SOLO PUEDE INGRESAR UN ROL.

			if (newUser != NULL)
				cout << "El usuario fue dado de alta con exito" << endl;
			else
				cout << "Ocurrió un error imprevisto" << endl;
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
	// TODO
}
