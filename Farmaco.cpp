#include "Farmaco.h"

using namespace std;


Farmaco::Farmaco(string nombre)
{
    this->nombre = nombre;
}


string Farmaco::getNombre()
{
    return this->nombre;
}

