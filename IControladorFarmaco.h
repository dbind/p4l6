#ifndef ICONTROLADORFARMACO_H
#define	ICONTROLADORFARMACO_H

using namespace std;

#include <string>
#include <vector>


#include "Farmaco.h"


class IControladorFarmaco
{

public: 
	virtual ~IControladorFarmaco(){};

	/**
	 * Ingresar fármacos
	 */
	virtual Farmaco* darDeAltaFarmaco(string nombre)=0;

	/**
	 * Verificar si el medicamento ya existe
	 */
	virtual bool memberFarmaco(string nombre)=0;

	/**
	 * Listar todos los fármacos que hay en el sistema
	 */
	virtual vector<Farmaco*> farmacos()=0;

	virtual void reset()=0;

protected:
	vector<Farmaco*> _farmacos;

};



#endif	/* ICONTROLADORMEDICAMENTO_H */

