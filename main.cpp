#include "FabricaControladores.h"


int main(int argc, char** argv)
{
	FabricaControladores::instancia()->controladorMenu()->iniciar();

	return 0;
}

//La situaci�n de la tarea al momento, es:
//	Menu funcional y completo, incluyendo chequeos, manejo de errores, etc.
//	Principales controladores completos, con sus interfaces y dem�s
//
//En cuanto a los casos de uso pedidos:
//
//	Diego / Hecho
//		Iniciar sesi�n
//		Cerrar sesi�n
//
//	Diego / En proceso (para viernes 27)
//		Alta/reactivaci�n de usuario
//		Usuarios dados de alta
//		Alta representaci�n de diagn�sticos
//		Listar representaci�n diagn�sticos
//
//	Bruno / En proceso
//		Alta medicamento
//
//
//	Pendiente / Consultas
//		Reserva consulta
//		Registro consulta
//		Devoluci�n de consulta
//		Alta diagn�sticos de una consulta
//
//	Pendiente / Usuarios
//		Obtener historial paciente
//		Notificar m�dicos