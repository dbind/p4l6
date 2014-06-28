#include "Farmaco.h"

using namespace std;

Farmaco::Farmaco(string nombre)
{
    this->nombre = nombre;
}

//Farmaco::~Farmaco()
//{
//    // TODO
//}


string Farmaco::getNombre()
{
    return this->nombre;
}

void Farmaco::setNombre(string nombre)
{
    this->nombre = nombre;
}

