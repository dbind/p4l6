/* 
 * File:   ControladorMedicamento.h
 * Author: bruno
 *
 * Created on 25 de junio de 2014, 03:28 PM
 */

#ifndef CONTROLADORFARMACO_H
#define	CONTROLADORFARMACO_H

#include <string>
#include <vector>

#include "IControladorFarmaco.h"

using namespace std;

class Farmaco;

class ControladorFarmaco : public IControladorFarmaco
{
    
public:
        static ControladorFarmaco* instancia();
        bool darDeAltaFarmaco(string nombre); // public o private? 
        vector<Farmaco*> farmacos; // protected?? 
       
private:
	static ControladorFarmaco* _instancia;
	ControladorFarmaco();     
	~ControladorFarmaco(){};
        
        bool memberFarmaco(string nombre);
           
};



#endif	/* CONTROLADORMEDICAMENTO_H */

