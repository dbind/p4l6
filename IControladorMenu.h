#ifndef ICONTROLADORMENU_H
#define	ICONTROLADORMENU_H

using namespace std;

#include <vector>


class IControladorSesion;
class Comando;


class IControladorMenu
{

public:
	virtual ~IControladorMenu(){};

	virtual void iniciar()=0;
	virtual void ejecutar(Comando)=0;
	
protected:
	// Referencias a los principales Controladores
	IControladorSesion*  cSesion;   // Controlador de Usuarios

	virtual void menuDeOpciones()=0;
	virtual void imprimirMenu(vector<Comando>)=0;

};

#endif	/* ICONTROLADORMENU_H */