using namespace std;

#include <exception>
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
	return _farmacos;
}


/**
 * Precondición: no existe el medicamento en el sistema
 */
Farmaco* ControladorFarmaco::darDeAltaFarmaco(string nombre)
{
    if (this->memberFarmaco(nombre))
    {
		throw;
	}

	Farmaco* farmaco = new Farmaco(nombre);
	_farmacos.insert(_farmacos.begin(), farmaco);

	return farmaco;
}

bool ControladorFarmaco::memberFarmaco(string nombre)
{
	vector<Farmaco*>::iterator it;

    for (it=_farmacos.begin(); it != _farmacos.end(); ++it)
    {
		Farmaco* farmaco = *it;

        if (farmaco->getNombre() == nombre)
        {
            return true;
        }
    }

    return false;
}