#include "../include/Sesion.h"

Sesion::Sesion()
{
    // TODO
}

Sesion::~Sesion()
{
    // TODO
}


vector<Consulta> Sesion::obtenerConsultasMedico()
{
    // TODO
}

string Sesion::getNombreUsuario()
{
    return this->usuario->getNombre();
}

string Sesion::getApellidoUsuario()
{
    return this->usuario->getApellido();
}

Sesion::setUsuario(Usuario usuario)
{
    this->usuario = usuario;
}

Sesion::activarUsuario(Usuario usuario)
{
    this->usuario->setActivo(true);
}
