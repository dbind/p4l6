#ifndef ICONTROLADORMENU_H
#define	ICONTROLADORMENU_H


class Usuario;
class FabricaControladores;
class IControladorUsuario;
class IControladorSesion;


class IControladorMenu
{

public:
	virtual ~IControladorMenu(){};

	virtual void iniciar()=0;
	
protected:
	// Referencias a los principales Controladores
	IControladorUsuario* cUsuario;  // Controlador de Usuarios
	IControladorSesion*  cSesion;   // Controlador de Usuarios

	virtual void menuDeOpciones()=0;

};

#endif	/* ICONTROLADORMENU_H */