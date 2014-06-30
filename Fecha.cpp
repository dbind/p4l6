using namespace std;

#include <iostream>

#include "Fecha.h"


Fecha::Fecha()
{
	_dia  = 0;
	_mes  = 0;
	_anyo = 0;
}

Fecha::Fecha(int dia, int mes, int anyo)
{
	_dia  = dia;
	_mes  = mes;
	_anyo = anyo;
}


ostream& operator<<(ostream& os, const Fecha& fecha)
{
    os << fecha._dia << '/' << fecha._mes << '/' << fecha._anyo;
    return os;
}
