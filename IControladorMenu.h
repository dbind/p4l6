#ifndef ICONTROLADORMENU_H
#define	ICONTROLADORMENU_H

using namespace std;

#include <vector>


class FabricaControladores;
class IControladorUsuario;
class IControladorSesion;
class Usuario;
class Comando;


class IControladorMenu
{

public:
	virtual ~IControladorMenu(){};

	virtual void iniciar()=0;
	virtual void ejecutar(Comando)=0;
	
protected:
	// Referencias a los principales Controladores
	IControladorUsuario* cUsuario;  // Controlador de Usuarios
	IControladorSesion*  cSesion;   // Controlador de Usuarios

	virtual void menuDeOpciones()=0;
	virtual void imprimirMenu(vector<Comando>)=0;

};

#endif	/* ICONTROLADORMENU_H */