#ifndef ICONTROLADORSESION_H
#define	ICONTROLADORSESION_H


class Usuario;
class IControladorUsuario;


class IControladorSesion
{
	
protected:
	IControladorUsuario* cUsuario; // Controlador de Usuarios del sistema
	Usuario* usuario;              // Usuario con sesión actualmente activa

public:
	virtual ~IControladorSesion(){};
	virtual void testControlador()=0;

	virtual bool iniciarSesion()=0;

};

#endif	/* ICONTROLADORSESION_H */

