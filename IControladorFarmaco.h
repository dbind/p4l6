/* 
 * File:   IControladorMedicamento.h
 * Author: bruno
 *
 * Created on 25 de junio de 2014, 03:12 PM
 */

#ifndef ICONTROLADORFARMACO_H
#define	ICONTROLADORFARMACO_H

#include <string>

class IControladorFarmaco
{

public: 
        virtual ~IControladorFarmaco(){};
        virtual bool darDeAltaFarmaco(std::string nombre)=0;
    
};



#endif	/* ICONTROLADORMEDICAMENTO_H */

