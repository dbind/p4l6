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
 * Instanciaci�n de singleton
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
		// Pido al usuario que se identifique (n�mero de c�dula)
		Usuario* usuario = this->pedirIdentificacion();

		// Pido al usuario que verifique que es �l (contrase�a)
		// Si falla tira una excepci�n, que forwardeamos impl�citamente
		if ((usuario != NULL) && this->autenticar(usuario))
		{
			// Logueo exitoso: mantener puntero al usuario identificado (sesi�n activa)
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
 * Pide al usuario identificarse con su c�dula de identidad.
 * 
 * � <<q>> para volver atr�s
 * � MASTER_CI (ver en ControladorUsuario) para ingresar como admin por defecto
 * � otras c�dulas para usuarios regulares
 * 
 * El proceso se repite hasta ingresar una c�dula v�lida o cancelar
 * 
 * Tira excepci�n int 0 si cancela (q)
 * Tira excepci�n int 1 si no existe en el sistema un usuario con esa CI
 */
Usuario* ControladorSesion::pedirIdentificacion()
{
	string ci;

	cout << "Ingrese su CI (hasta 8 n�meros, sin d�gito de verificaci�n) ";
	cout << "(o escriba q para salir):\n";
	cin >> ci;

	// Mientras la c�dula ingresada no sea un entero, que vuelva a intentar
	while ((ci != "q") && !this->esValidaCi(ci))
	{
		cout << "La c�dula ingresada no es v�lida. Int�ntelo nuevamente:\n";
		cin >> ci;
	}

	// El usuario desea cancelar (i.e. volver a empezar)
	if (ci == "q")
	{
		throw 0;
	}

	Usuario* usuario = FabricaControladores::instancia()->controladorUsuario()
	                                                    ->findUsuario(ci);

	// El usuario no est� registrado en el sistema
	if (usuario == NULL)
	{
		cout << "No hay usuarios con esa CI en el sistema.\n";
	}

	return usuario;
}

/**
 * Pide al usuario autenticarse con su contrase�a.
 * 
 * � <<q>> para volver atr�s
 * � MASTER_PASS (ver en ControladorUsuario) si es el admin por defecto
 * 
 * El proceso se repite hasta ingresar la contrase�a correcta o cancelar
 * 
 * Tira excepci�n int 0 si cancela (q)
 */
bool ControladorSesion::autenticar(Usuario* usuario)
{
	string pass;

	// Primer pedido (texto explicativo diferenciado)
	if (usuario->esNuevo())
	{
		cout << "Usted ingresa por primera vez al sistema. ";
		cout << "Escriba una contrase�a alfanum�rica de entre 3 y 10 caracteres ";
		cout << "(o escriba q para volver atr�s):\n";
	}
	else if (usuario->esUn(Rol::master))
	{
		cout << "Ingrese la contrase�a maestra, por favor ";
		cout << "(o escriba q para volver atr�s):\n";
	}
	else
	{
		cout << "Ingrese su contrase�a, por favor ";
		cout << "(o escriba q para volver atr�s):\n";
	}

	cin >> pass;

	// Validar contrase�a, o pedirla nuevamente hasta que ingresa una v�lida
	while ((pass != "q") && (usuario->esNuevo() || !usuario->validarPass(pass)))
	{
		if (!this->esValidoPass(pass))  // Formato incorrecto
		{
			cout << "La contrase�a ingresada es inv�lida. Int�ntelo nuevamente:\n";
			cin >> pass;
		}
		else if (usuario->esNuevo())    // Primera vez: actualizar y activar
		{
			cout << "Bienvenido! Su nueva contrase�a ha sido guardada.\n";
			usuario->cambiarPass(pass); // Guardar nueva pass
			usuario->activar();         // Activar la cuenta
		}
		else // pass != usuario->pass   // La contrase�a ingresada no coincide
		{
			cout << "La contrase�a ingresada no es correcta. Int�ntelo nuevamente:\n";
			cin >> pass;
		}
	}

	// 2 formas de llegar hasta ac�: o presion� q o la contrase�a fue aceptada
	return (pass != "q");
}

bool ControladorSesion::esValidaCi(string ci)
{
	char ci_limpia[ci.length()+1];
	int ci_numeros;

	istringstream(ci) >> ci_numeros;       // Filtro solo n�meros del input
	sprintf(ci_limpia, "%d", ci_numeros);  // Casteo a string el n�mero solo

	return (ci == ci_limpia && ci.length() <= 8); // M�x: 9999999
}

bool ControladorSesion::esValidoPass(string pass)
{
	return ((pass.size() >= 3) && (pass.size() <= 10));
}


void ControladorSesion::reset()
{
	this->cerrarSesion();
}
