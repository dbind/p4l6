#ifndef COMANDOSCONSULTA_H
#define	COMANDOSCONSULTA_H


/**
 * Manejador de Comandos relacionados con  (en la capa de la Vista)
 */
class ComandosConsulta
{

public:

	/**
	 * Caso de uso Reserva Consulta
     */
	static void reserva_consulta();

	/**
	 * Caso de uso Devolución de Reserva
     */
	static void devolucion_reserva();

	/**
	 * Caso de uso Registro Consulta
     */
	static void registro_consulta();

	/**
	 * Caso de uso Alta Diagnósticos de Consulta
     */
	static void alta_diagnosticos();

};

#endif	/* COMANDOSCONSULTA_H */
