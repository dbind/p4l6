#ifndef FECHA_H
#define FECHA_H


class Fecha
{

public:
	Fecha(); // Fecha vacía, indeterminada
	Fecha(int dia, int mes, int anyo);

	int dia();
	int mes();
	int anyo();

private:
	int _dia;
	int _mes;
	int _anyo;

};

#endif // FECHA_H
