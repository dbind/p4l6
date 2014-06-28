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

        bool darDeAltaFarmaco(string nombre);
        vector<Farmaco*> farmacos();

private:
	static ControladorFarmaco* _instancia;
	ControladorFarmaco(){};

        bool memberFarmaco(string nombre);

};



#endif	/* CONTROLADORMEDICAMENTO_H */

