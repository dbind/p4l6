#ifndef FARMACO_H
#define FARMACO_H

using namespace std;

#include <string>


class Farmaco
{
    private:
        string nombre;

    public:
        Farmaco(string nombre);
        virtual ~Farmaco(){};

        string getNombre();
};

#endif // FARMACO_H
