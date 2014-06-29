#ifndef FECHAHORA_H
#define FECHAHORA_H


class FechaHora
{

    public:
        FechaHora(int dia, int mes, int anyo, int hora, int minuto);

        int dia();
        int mes();
        int anyo();
        int hora();
        int minuto();

    private:
        int _dia;
        int _mes;
        int _anyo;
        int _hora;
        int _minuto;

};

#endif // FECHAHORA_H
