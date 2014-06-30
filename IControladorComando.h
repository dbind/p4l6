#ifndef ICONTROLADORCOMANDO_H
#define	ICONTROLADORCOMANDO_H

using namespace std;

#include <vector>

#include "Rol.h"


class Comando;


class IControladorComando
{

public:
	virtual ~IControladorComando(){};
	
	/**
	 * Retorna un vector de comandos habilitados para los roles especificados
	 */
	virtual vector<Comando> comandos(vector<Rol>)=0;

	/**
	 * Deriva el comando especificado a quién le corresponda atenderlo
	 */
	virtual void ejecutar(Comando)=0;
	
protected:
	vector<Comando> _comandos;

};

#endif	/* ICONTROLADORCOMANDO_H */