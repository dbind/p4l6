#include "FechaHora.h"


FechaHora::FechaHora(int dia, int mes, int anyo, int hora=0, int minuto=0)
{
	this->_dia    = dia;
	this->_mes    = mes;
	this->_anyo   = anyo;
    this->_hora   = hora;
    this->_minuto = minuto;
}

int FechaHora::dia()    { return this->_dia;    }
int FechaHora::mes()    { return this->_mes;    }
int FechaHora::anyo()   { return this->_anyo;   }
int FechaHora::hora()   { return this->_hora;   }
int FechaHora::minuto() { return this->_minuto; }
