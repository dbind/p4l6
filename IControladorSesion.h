#ifndef ICONTROLADORSESION_H
#define	ICONTROLADORSESION_H


class Usuario;
class IControladorUsuario;


class IControladorSesion
{

public:
	virtual ~IControladorSesion(){};

	/**
	 * Pide al usuario identificarse y autenticarse. En caso de éxito (credenciales
	 * correctas) se inicia la sesión. En caso contrario se tira una excepción.
	 * 
	 * Tira excepción int 0 si se cancela el login (q al ingresar CI o Pass)
	 * Tira excepción int 1 si se ingresa una cédula que no esté en el sistema
	 */
	virtual void iniciarSesion()=0;
	virtual void cerrarSesion()=0;

	virtual bool sesionIniciada()=0;

	/**
	 * Devuelve el usuario asociado a la sesión activa.
	 * 
	 * Tira excepción int 1 si no hay una sesión activa.
	 */
	virtual Usuario* usuarioActivo()=0;
	
protected:
	IControladorUsuario* cUsuario; // Controlador de Usuarios del sistema
	Usuario* usuario;              // Usuario con sesión actualmente activa

};

#endif	/* ICONTROLADORSESION_H */

