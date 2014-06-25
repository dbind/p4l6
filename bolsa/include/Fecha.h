#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    private:
        int dia;
        int mes;
        int anyo;

    public:
        Fecha(int dia, int mes, int anyo);

        int getDia() { return dia; }
        int getMes() { return mes; }
        int getAnyo() { return anyo; }
};

#endif // FECHA_H
