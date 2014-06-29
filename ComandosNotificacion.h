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
	static void suscribirse_paciente();

	/**
	 * Caso de uso Notificar Médicos
     */
	static void notificar_medicos();

};

#endif	/* COMANDOSNOTIFICACION_H */
