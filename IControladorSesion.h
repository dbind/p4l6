#ifndef ICONTROLADORSESION_H
#define	ICONTROLADORSESION_H


class Usuario;
class IControladorUsuario;


class IControladorSesion
{

public:
	virtual ~IControladorSesion(){};

	/**
	 * Pide al usuario identificarse y autenticarse. En caso de �xito (credenciales
	 * correctas) se inicia la sesi�n. En caso contrario se tira una excepci�n.
	 * 
	 * Tira excepci�n int 0 si se cancela el login (q al ingresar CI o Pass)
	 * Tira excepci�n int 1 si se ingresa una c�dula que no est� en el sistema
	 */
	virtual void iniciarSesion()=0;
	virtual void cerrarSesion()=0;

	virtual bool sesionIniciada()=0;

	/**
	 * Devuelve el usuario asociado a la sesi�n activa.
	 * 
	 * Tira excepci�n int 1 si no hay una sesi�n activa.
	 */
	virtual Usuario* usuarioActivo()=0;

	/**
	 * Forzar inicio de sesi�n directo (para tests y debugging)
     */
	virtual void iniciarSesionInterno(Usuario*)=0;

	virtual void reset()=0;
	
protected:
	Usuario* usuario;              // Usuario con sesi�n actualmente activa

};

#endif	/* ICONTROLADORSESION_H */

