#ifndef TRATAMIENTO_H
#define TRATAMIENTO_H

using namespace std;

#include <string>


class Tratamiento
{

    public:
        Tratamiento(){};
        virtual ~Tratamiento(){};

		string descripcion();

    protected:
        string _descripcion;

};

#endif // TRATAMIENTO_H
