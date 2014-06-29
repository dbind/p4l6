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

};

#endif	/* COMANDOSSISTEMA_H */
