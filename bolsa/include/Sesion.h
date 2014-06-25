#ifndef SESION_H
#define SESION_H

#include <string>
#include <vector>

#include "../include/Usuario.h"
#include "../include/Consulta.h"


class Sesion
{
    private:
        Usuario* usuario;

    public:
        Sesion();
        virtual ~Sesion();

        vector<Consulta> obtenerConsultasMedico();
        string getNombreUsuario();
        string getApellidoUsuario();
        setUsuario(Usuario usuario);
        activarUsuario(Usuario usuario);
};

#endif // SESION_H
