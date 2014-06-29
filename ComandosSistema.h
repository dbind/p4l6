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
	static void set_time();

	/**
	 * Caso de uso Consultar fecha del sistema
     */
	static void get_time();

	/**
	 * Caso de uso Cargar datos de prueba
     */
	static void load_test_data();

};

#endif	/* COMANDOSSISTEMA_H */
