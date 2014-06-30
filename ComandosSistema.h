#ifndef COMANDOSSISTEMA_H
#define	COMANDOSSISTEMA_H


/**
 * Manejador de Comandos relacionados con  (en la capa de la Vista)
 */
class ComandosSistema
{

public:
	/**
	 * Caso de uso Modificar fecha del Sistema
     */
	static void setTime();

	/**
	 * Caso de uso Consultar fecha del sistema
     */
	static void getTime();

	/**
	 * Caso de uso Cargar datos de prueba
     */
	static void loadTestData();

	/**
	 * Debug
     */
	static void listarReservas();
	static void listarConsultas();
	static void listarUsuarios();
	static void listarFarmacos();
	static void listarCategorias();
	static void listarRepresentaciones();

};

#endif	/* COMANDOSSISTEMA_H */
