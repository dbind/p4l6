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

bool operator== (const Fecha& f1, const Fecha& f2)
{
    return (f1._dia  == f2._dia)
	    && (f1._mes  == f2._mes)
	    && (f1._anyo == f2._anyo);
}

bool operator!= (const Fecha& f1, const Fecha& f2)
{
    return !(f1 == f2);
}

bool operator<  (const Fecha& f1, const Fecha& f2)
{
    return (f1._anyo < f2._anyo)
	   || ((f1._mes  < f2._mes) && (f1._anyo == f2._anyo))
	   || ((f1._dia  < f2._dia) && (f1._anyo == f2._anyo) && (f1._mes  == f2._mes ));
}

bool operator<= (const Fecha& f1, const Fecha& f2)
{
    return (f1 == f2) || (f1 < f2);
}
 
bool operator>  (const Fecha& f1, const Fecha& f2)
{
    return !(f1 <= f2);
}

bool operator>= (const Fecha& f1, const Fecha& f2)
{
    return !(f1 < f2);
}
