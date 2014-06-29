#ifndef CONTROLADORFARMACO_H
#define	CONTROLADORFARMACO_H

using namespace std;

#include <string>
#include <vector>

#include "IControladorFarmaco.h"


class Farmaco;


class ControladorFarmaco : public IControladorFarmaco
{

public:
        static ControladorFarmaco* instancia();

        Farmaco* darDeAltaFarmaco(string nombre);
        bool memberFarmaco(string nombre);

        vector<Farmaco*> farmacos();

private:
	static ControladorFarmaco* _instancia;
	ControladorFarmaco(){};

};



#endif	/* CONTROLADORMEDICAMENTO_H */

