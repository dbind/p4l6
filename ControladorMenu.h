#ifndef CONTROLADORMENU_H
#define	CONTROLADORMENU_H

#include "IControladorMenu.h"


class Comando;


class ControladorMenu : public IControladorMenu
{

public:
	static ControladorMenu* instancia();

	void iniciar();
	void ejecutar(Comando);

private:
	static ControladorMenu* _instancia;
	ControladorMenu();
	~ControladorMenu(){};

	void login();
	void logout();

	void menuDeOpciones();
	bool esValidaOpcion(string opcion, int max);

};

#endif	/* CONTROLADORMENU_H */

