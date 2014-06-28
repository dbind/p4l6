#ifndef CONTROLADORMENU_H
#define	CONTROLADORMENU_H

using namespace std;

#include <string>

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
	void imprimirMenu(vector<Comando>);

	void interpretarOpcion(string opcion, vector<Comando>);
	bool esValidaOpcion(string opcion, int max);

};

#endif	/* CONTROLADORMENU_H */

