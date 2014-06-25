#ifndef FARMACO_H
#define FARMACO_H

#include <string>


class Farmaco
{
    private:
        string nombre;

    public:
        Farmaco();
        virtual ~Farmaco();

        string getNombre();
        setNombre(string nombre);
};

#endif // FARMACO_H
