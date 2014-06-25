#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <iostream>
using namespace std;

#include "ControladorSesion.h"
#include "FabricaControladores.h"

#include "TipoSexo.h"
#include "Fecha.h"
#include "Rol.h"
#include "Usuario.h"


/**
 * Testea la creación de la instancia del controlador
 */
void ControladorSesion::testControlador()
{
	cout << "test";
}


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

ControladorSesion::ControladorSesion()
{
	// Referencia (por practicidad) al Controlador de Usuarios del sistema
	FabricaControladores* Fabrica = FabricaControladores::instancia();
	this->cUsuario = Fabrica->controladorUsuario();
}


/******************************************************************************/
/********************************* P U B L I C ********************************/
/******************************************************************************/


bool ControladorSesion::iniciarSesion()
{
	// Pido al usuario que se identifique (número de cédula)
	Usuario* usuario = this->pedirIdentificacion();

	// Si el usuario no existe, no hay más que hacer acá
	if (usuario == NULL)
	{
		return false;
	}

	// Pido al usuario que verifique que es él (contraseña)
	
	cout << "Usuario encontrado: " << usuario->getNombre();

	// Mantener puntero al usuario activo (sesión activa)
	this->usuario = usuario;

	return true;
}

void ControladorSesion::cerrarSesion()
{
	this->usuario = NULL;
}


/******************************************************************************/
/******************************** P R I V A T E *******************************/
/******************************************************************************/

Usuario* ControladorSesion::pedirIdentificacion()
{
	string ci;

	cout << "Ingrese su CI (hasta 7 números, sin dígito de verificación) ";
	cout << "(o presione Enter para volver atrás):\n";
	cin >> ci;

	// Mientras la cédula ingresada no sea un entero, que vuelva a intentar
	while ((ci != "") && !this->esValidaCi(ci))
	{
		cout << "La cédula ingresada no es válida. Inténtelo nuevamente ";
		cout << "(o presione Enter para volver atrás):\n";
		cin >> ci;
	}

	if (ci == "")
	{
		return NULL;
	}

	Usuario* usuario = this->cUsuario->findUsuario(ci);

	if (usuario == NULL)
	{
		cout << "No hay usuarios con esa cédula de identidad en el sistema.\n";
	}

	return usuario;
}

bool ControladorSesion::pedirAutenticacion(Usuario* usuario)
{
	string pass;

	// Primer pedido (texto explicativo diferenciado)
	if (usuario->esNuevo())
	{
		cout << "Usted ingresa por primera vez al sistema. ";
		cout << "Escriba una contraseña alfanumérica de hasta 10 caracteres ";
		cout << "(o presione Enter para volver atrás):\n";
	}
	else if (usuario->esUn(Rol::master))
	{
		cout << "Ingrese la contraseña maestra, por favor ";
		cout << "(o presione Enter para volver atrás):\n";
	}
	else
	{
		cout << "Ingrese su contraseña, por favor ";
		cout << "(o presione Enter para volver atrás):\n";
	}

	cin >> pass;

	// Validar contraseña, o pedirla nuevamente hasta que ingresa una válida
	while ((pass != "") && (usuario->esNuevo() || !usuario->validarPass(pass)))
	{
		if (!this->esValidoPass(pass))  // Formato incorrecto
		{
			cout << "La contraseña ingresada es inválida. Inténtelo nuevamente ";
			cout << "(o presione Enter para volver atrás):\n";
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
			cout << "La contraseña ingresada no es correcta. Inténtelo nuevamente ";
			cout << "(o presione Enter para volver atrás):\n";
			cin >> pass;
		}
	}

	return (pass != "");
}

bool ControladorSesion::esValidaCi(string ci)
{
	char ci_limpia[ci.length()+1]; // Máx: 9999999
	int ci_numeros;

	istringstream(ci) >> ci_numeros;       // Filtro solo números del input
	sprintf(ci_limpia, "%d", ci_numeros);  // Casteo a string el número solo

	return (ci == ci_limpia && ci.length() <= 7);
}

bool ControladorSesion::esValidoPass(string pass)
{
	return true; // TODO
}