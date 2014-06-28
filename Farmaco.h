#ifndef FARMACO_H
#define FARMACO_H

#include <string>

using namespace std;


class Farmaco
{
    private:
        string nombre;

    public:
        Farmaco(string nombre);
        virtual ~Farmaco(){};

        string getNombre();
        void setNombre(string nombre);
};

#endif // FARMACO_H
