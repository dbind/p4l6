#include "FabricaControladores.h"


int main(int argc, char** argv)
{
	FabricaControladores::instancia()->controladorMenu()->iniciar();

	return 0;
}

//La situación de la tarea al momento, es:
//	Menu funcional y completo, incluyendo chequeos, manejo de errores, etc.
//	Principales controladores completos, con sus interfaces y demás
//
//En cuanto a los casos de uso pedidos:
//
//	Diego / Hecho
//		Iniciar sesión
//		Cerrar sesión
//
//	Diego / En proceso (para viernes 27)
//		Alta/reactivación de usuario
//		Usuarios dados de alta
//		Alta representación de diagnósticos
//		Listar representación diagnósticos
//
//	Bruno / En proceso
//		Alta medicamento
//
//
//	Pendiente / Consultas
//		Reserva consulta
//		Registro consulta
//		Devolución de consulta
//		Alta diagnósticos de una consulta
//
//	Pendiente / Usuarios
//		Obtener historial paciente
//		Notificar médicos