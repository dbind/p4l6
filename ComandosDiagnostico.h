#ifndef COMANDOSDIAGNOSTICO_H
#define	COMANDOSDIAGNOSTICO_H


/**
 * Manejador de Comandos relacionados con  (en la capa de la Vista)
 */
class ComandosDiagnostico
{

public:
	/**
	 * Caso de uso Alta Representaci�n de Diagn�stico
     */
	static void altaRepresentacion();
//        static void agregarCategoria();
        static void listarCategorias();

	/**
	 * Caso de uso Listar Representaciones de Diagn�sticos
     */
	static void listarRepresentaciones();

};

#endif	/* COMANDOSDIAGNOSTICO_H */
