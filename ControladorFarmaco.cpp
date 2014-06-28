using namespace std;

#include <string>
#include <vector>

#include "ControladorFarmaco.h"

#include "Farmaco.h"


ControladorFarmaco* ControladorFarmaco::_instancia = 0;

ControladorFarmaco* ControladorFarmaco::instancia()
{
    if (_instancia == 0)
	{
		_instancia = new ControladorFarmaco();
	}

	return _instancia;
}


vector<Farmaco*> ControladorFarmaco::farmacos()
{
	return this->_farmacos;
}


bool ControladorFarmaco::darDeAltaFarmaco(string nombre)
{
    if (!this->memberFarmaco(nombre))
    {
        Farmaco* farmaco = new Farmaco(nombre);
        this->_farmacos.insert(this->_farmacos.begin(), farmaco);

		return true;
    }

	return false;
}

bool ControladorFarmaco::memberFarmaco(string nombre)
{
	vector<Farmaco*>::iterator it;

    for (it=this->_farmacos.begin(); it != this->_farmacos.end(); ++it)
    {
		Farmaco* farmaco = *it;

        if (farmaco->getNombre() == nombre)
        {
            return true;
        }
    }

    return false;
}