#ifndef CONTROLADORCOMANDO_H
#define	CONTROLADORCOMANDO_H

using namespace std;

#include <vector>

#include "IControladorComando.h"

#include "Rol.h"


class Comando;


/**
 * Singleton ControladorComando
 */
class ControladorComando : public IControladorComando
{

public:
	static ControladorComando* instancia();
	
	/**
	 * Retorna un vector de comandos habilitados para los roles especificados
        */
	vector<Comando> comandos(Roles);
	
	/**
	 * Deriva el comando especificado a qui�n le corresponda atenderlo
        */
	void ejecutar(Comando);

	void reset();

private:
	static ControladorComando* _instancia;
	ControladorComando();

	void registrarComandos();
	void agregar(string codigo, string nombre, Roles);

};

#endif	/* CONTROLADORCOMANDO_H */
