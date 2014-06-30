#ifndef FECHA_H
#define FECHA_H

using namespace std;

#include <iostream>


class Fecha
{

public:
	Fecha(); // Fecha vacía, indeterminada
	Fecha(int dia, int mes, int anyo);

    friend ostream& operator<<(ostream& os, const Fecha& fecha);

	friend bool operator== (const Fecha&, const Fecha&);
	friend bool operator!= (const Fecha&, const Fecha&);
 
    friend bool operator<  (const Fecha&, const Fecha&);
    friend bool operator<= (const Fecha&, const Fecha&);

    friend bool operator>  (const Fecha&, const Fecha&);
    friend bool operator>= (const Fecha&, const Fecha&);

private:
	int _dia, _mes, _anyo;
};

#endif // FECHA_H
