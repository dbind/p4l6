#include "Fecha.h"


Fecha::Fecha()
{
	this->_dia  = 0;
	this->_mes  = 0;
	this->_anyo = 0;
}

Fecha::Fecha(int dia, int mes, int anyo)
{
	this->_dia  = dia;
	this->_mes  = mes;
	this->_anyo = anyo;
}

int Fecha::dia()  { return this->_dia;  }
int Fecha::mes()  { return this->_mes;  }
int Fecha::anyo() { return this->_anyo; }
