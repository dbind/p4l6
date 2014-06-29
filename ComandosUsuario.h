#ifndef COMANDOSUSUARIO_H
#define	COMANDOSUSUARIO_H


class Usuario;


/**
 * Manejador de Comandos relacionados con usuarios (en la capa de la Vista)
 */
class ComandosUsuario
{

public:
	/**
	 * Caso de uso Alta/Reactivación de Usuario
        */
	static void altaReactivacionUsuario();
	
	/**
	 * Caso de uso Usuarios Dados de Alta o Reactivados
         */
	static void listarAltasReactivaciones();
	
	/**
	 * Caso de uso Usuarios Obtener Historial Paciente
         */
	static void verHistorial();

private:

};

#endif	/* COMANDOSUSUARIO_H */
