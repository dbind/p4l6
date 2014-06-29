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
	static void reservarConsulta();

	/**
	 * Caso de uso Devoluci�n de Reserva
     */
	static void cancelarReserva();

	/**
	 * Caso de uso Registro Consulta
     */
	static void registrarConsulta();

	/**
	 * Caso de uso Alta Diagn�sticos de Consulta
     */
	static void altaDiagnosticosConsulta();

};

#endif	/* COMANDOSCONSULTA_H */
