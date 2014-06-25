#ifndef CONTROLADORMENU_H
#define	CONTROLADORMENU_H

#include "IControladorMenu.h"


class ControladorMenu : public IControladorMenu
{

public:
	static ControladorMenu* instancia();
	
	void testControlador();

	void iniciar();

private:
	static ControladorMenu* _instancia;
	ControladorMenu();
	~ControladorMenu(){};

	void login();
	void logout();

	void menuDeOpciones();

};

#endif	/* CONTROLADORMENU_H */

