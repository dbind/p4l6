using namespace std;

#include <iostream>

#include "Fecha.h"


Fecha::Fecha()
{
	_dia  = 1;
	_mes  = 1;
	_anyo = 2014;
}

Fecha::Fecha(int dia, int mes, int anyo)
{
	_dia  = dia;
	_mes  = mes;
	_anyo = anyo;
}

int Fecha::dia()  const { return _dia;  }
int Fecha::mes()  const { return _mes;  }
int Fecha::anyo() const { return _anyo; }


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
