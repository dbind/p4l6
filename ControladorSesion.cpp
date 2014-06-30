using namespace std;

#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "ControladorSesion.h"
#include "FabricaControladores.h"

#include "Genero.h"
#include "Fecha.h"
#include "Rol.h"
#include "Usuario.h"


/**
 * Instanciación de singleton
 */
ControladorSesion* ControladorSesion::_instancia = 0;

ControladorSesion* ControladorSesion::instancia()
{
	if (_instancia == 0)
	{
		_instancia = new ControladorSesion();
	}
	
	return _instancia;
}


/******************************************************************************/
/********************************* P U B L I C ********************************/
/******************************************************************************/

void ControladorSesion::iniciarSesion()
{
	while (!this->sesionIniciada())
	{
		// Pido al usuario que se identifique (número de cédula)
		Usuario* usuario = this->pedirIdentificacion();

		// Pido al usuario que verifique que es él (contraseña)
		// Si falla tira una excepción, que forwardeamos implícitamente
		if ((usuario != NULL) && this->autenticar(usuario))
		{
			// Logueo exitoso: mantener puntero al usuario identificado (sesión activa)
			this->usuario = usuario;
		}
	}
}

void ControladorSesion::cerrarSesion()
{
	this->usuario = NULL;
}

bool ControladorSesion::sesionIniciada()
{
	return this->usuario != NULL;
}

Usuario* ControladorSesion::usuarioActivo()
{
	if (!this->sesionIniciada())
	{
		throw 1;
	}

	return this->usuario;
}

void ControladorSesion::iniciarSesionInterno(Usuario* usuario)
{
	this->usuario = usuario;
}


/******************************************************************************/
/******************************** P R I V A T E *******************************/
/******************************************************************************/

/**
 * Pide al usuario identificarse con su cédula de identidad.
 * 
 * · <<q>> para volver atrás
 * · MASTER_CI (ver en ControladorUsuario) para ingresar como admin por defecto
 * · otras cédulas para usuarios regulares
 * 
 * El proceso se repite hasta ingresar una cédula válida o cancelar
 * 
 * Tira excepción int 0 si cancela (q)
 * Tira excepción int 1 si no existe en el sistema un usuario con esa CI
 */
Usuario* ControladorSesion::pedirIdentificacion()
{
	string ci;

	cout << "Ingrese su CI (hasta 8 números, sin dígito de verificación) ";
	cout << "(o escriba q para salir):\n";
	cin >> ci;

	// Mientras la cédula ingresada no sea un entero, que vuelva a intentar
	while ((ci != "q") && !this->esValidaCi(ci))
	{
		cout << "La cédula ingresada no es válida. Inténtelo nuevamente:\n";
		cin >> ci;
	}

	// El usuario desea cancelar (i.e. volver a empezar)
	if (ci == "q")
	{
		throw 0;
	}

	Usuario* usuario = FabricaControladores::instancia()->controladorUsuario()
	                                                    ->findUsuario(ci);

	// El usuario no está registrado en el sistema
	if (usuario == NULL)
	{
		cout << "No hay usuarios con esa CI en el sistema.\n";
	}

	return usuario;
}

/**
 * Pide al usuario autenticarse con su contraseña.
 * 
 * · <<q>> para volver atrás
 * · MASTER_PASS (ver en ControladorUsuario) si es el admin por defecto
 * 
 * El proceso se repite hasta ingresar la contraseña correcta o cancelar
 * 
 * Tira excepción int 0 si cancela (q)
 */
bool ControladorSesion::autenticar(Usuario* usuario)
{
	string pass;

	// Primer pedido (texto explicativo diferenciado)
	if (usuario->esNuevo())
	{
		cout << "Usted ingresa por primera vez al sistema. ";
		cout << "Escriba una contraseña alfanumérica de entre 3 y 10 caracteres ";
		cout << "(o escriba q para volver atrás):\n";
	}
	else if (usuario->esUn(Rol::master))
	{
		cout << "Ingrese la contraseña maestra, por favor ";
		cout << "(o escriba q para volver atrás):\n";
	}
	else
	{
		cout << "Ingrese su contraseña, por favor ";
		cout << "(o escriba q para volver atrás):\n";
	}

	cin >> pass;

	// Validar contraseña, o pedirla nuevamente hasta que ingresa una válida
	while ((pass != "q") && (usuario->esNuevo() || !usuario->validarPass(pass)))
	{
		if (!this->esValidoPass(pass))  // Formato incorrecto
		{
			cout << "La contraseña ingresada es inválida. Inténtelo nuevamente:\n";
			cin >> pass;
		}
		else if (usuario->esNuevo())    // Primera vez: actualizar y activar
		{
			cout << "Bienvenido! Su nueva contraseña ha sido guardada.\n";
			usuario->cambiarPass(pass); // Guardar nueva pass
			usuario->activar();         // Activar la cuenta
		}
		else // pass != usuario->pass   // La contraseña ingresada no coincide
		{
			cout << "La contraseña ingresada no es correcta. Inténtelo nuevamente:\n";
			cin >> pass;
		}
	}

	// 2 formas de llegar hasta acá: o presionó q o la contraseña fue aceptada
	return (pass != "q");
}

bool ControladorSesion::esValidaCi(string ci)
{
	char ci_limpia[ci.length()+1];
	int ci_numeros;

	istringstream(ci) >> ci_numeros;       // Filtro solo números del input
	sprintf(ci_limpia, "%d", ci_numeros);  // Casteo a string el número solo

	return (ci == ci_limpia && ci.length() <= 8); // Máx: 9999999
}

bool ControladorSesion::esValidoPass(string pass)
{
	return ((pass.size() >= 3) && (pass.size() <= 10));
}


void ControladorSesion::reset()
{
	this->cerrarSesion();
}
