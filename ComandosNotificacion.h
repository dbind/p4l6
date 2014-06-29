#ifndef COMANDOSNOTIFICACION_H
#define	COMANDOSNOTIFICACION_H


/**
 * Manejador de Comandos relacionados con  (en la capa de la Vista)
 */
class ComandosNotificacion
{

public:
	/**
	 * Caso de uso Subscribirse a Notificaciones del Paciente
     */
	static void seguirPaciente();

	/**
	 * Caso de uso Notificar Médicos
     */
	static void notificarMedicos();

};

#endif	/* COMANDOSNOTIFICACION_H */
