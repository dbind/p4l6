#ifndef ICONTROLADORSESION_H
#define	ICONTROLADORSESION_H


class Usuario;
class IControladorUsuario;


class IControladorSesion
{

public:
	virtual ~IControladorSesion(){};
	virtual void testControlador()=0;

	virtual bool iniciarSesion()=0;
	virtual void cerrarSesion()=0;
	
protected:
	IControladorUsuario* cUsuario; // Controlador de Usuarios del sistema
	Usuario* usuario;              // Usuario con sesión actualmente activa

};

#endif	/* ICONTROLADORSESION_H */

