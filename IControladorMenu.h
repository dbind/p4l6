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
	virtual void testControlador()=0;

	virtual void iniciar()=0;
	
protected:
	// Referencias a los principales Controladores
	FabricaControladores* Fabrica;   // Fábrica central de Controladores
	IControladorUsuario*  cUsuario;  // Controlador de Usuarios
	IControladorSesion*   cSesion;   // Controlador de Usuarios

	virtual void menuDeOpciones()=0;

};

#endif	/* ICONTROLADORMENU_H */