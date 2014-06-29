#include <iostream>
#include <string>

#include "ComandosFarmaco.h"
#include "IControladorFarmaco.h"
#include "FabricaControladores.h"

using namespace std;

void ComandosFarmaco::altaMedicamento()
{
    string m;
    bool exito;
        
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
            IControladorFarmaco* cm = FabricaControladores::instancia()->controladorFarmaco();
            exito = cm->darDeAltaFarmaco(m);
    
            if (exito) 
            {
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
