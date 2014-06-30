#ifndef COMANDOSDIAGNOSTICO_H
#define	COMANDOSDIAGNOSTICO_H


/**
 * Manejador de Comandos relacionados con  (en la capa de la Vista)
 */
class ComandosDiagnostico
{

public:
	/**
	 * Caso de uso Alta Representación de Diagnóstico
     */
	static void altaRepresentacion();
//        static void agregarCategoria();
        static void listarCategorias();

	/**
	 * Caso de uso Listar Representaciones de Diagnósticos
     */
	static void listarRepresentaciones();

};

#endif	/* COMANDOSDIAGNOSTICO_H */
