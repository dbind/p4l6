#ifndef ICONTROLADORFARMACO_H
#define	ICONTROLADORFARMACO_H

using namespace std;

#include <string>
#include <vector>


class Farmaco;


class IControladorFarmaco
{

public: 
        virtual ~IControladorFarmaco(){};

        /**
         * Ingresar f�rmacos
         */
        virtual bool darDeAltaFarmaco(string nombre)=0;
        
        /**
         * Listar todos los f�rmacos que hay en el sistema
         */
        virtual vector<Farmaco*> farmacos()=0;

protected:
        vector<Farmaco*> _farmacos;

};



#endif	/* ICONTROLADORMEDICAMENTO_H */
