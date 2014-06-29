using namespace std;

#include <iostream>
#include <string>

#include "ComandosFarmaco.h"
#include "IControladorFarmaco.h"
#include "FabricaControladores.h"

void ComandosFarmaco::altaFarmaco()
{
    string m;
    bool exito = false;

	IControladorFarmaco* cm = FabricaControladores::instancia()->controladorFarmaco();

    do
    {   
        cout << "Ingrese el nombre del medicamento que desea dar de alta (o q para cancelar): " << endl;
        cin >> m;
    
        if (m=="q")
        {
            exito = true;
        }
    
        else
        {
            if (!cm->memberFarmaco(m)) 
            {
				cm->darDeAltaFarmaco(m);
                cout << "El medicamento ha sido agregado correctamente." << endl;
            }
            else
            {
                cout << "El medicamento ingresado ya existe en el sistema." << endl;
            }
        }
    }
    while (!exito);
}
