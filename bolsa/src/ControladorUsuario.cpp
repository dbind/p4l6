#include "../include/ControladorUsuario.h"


ControladorUsuario* ControladorUsuario::instancia(string ci)
{
    if (this->_instancia == 0)
        this->_instancia = new ControladorUsuarioo;

    return this->_instancia;
}


vector<Usuario*> ControladorUsuario::getUsuarios()
{
    return this->usuarios;
}

Sesion ControladorUsuario::getSesion()
{
    return this->sesion;
}

ControladorUsuario::setUsuarios(vector<Usuario*> usuarios)
{
    this->usuarios = usuarios;
}

ControladorUsuario::setSesion(Sesion sesion)
{
    this->sesion = sesion;
}


EstadoUsuario ControladorUsuario::estadoIniciarSesion(string ci)
{
    // TODO
}

bool ControladorUsuario::existeUsuario(string ci)
{
    // TODO
}

bool ControladorUsuario::estaActivoUsuario(string ci)
{
    // TODO
}

ControladorUsuario::reactivarUsuario(string ci)
{
    // TODO
}

ControladorUsuario::altaUsuario(string ci, string nombre, string apellido, TipoSexo sexo, Fecha fecNac, vector<Rol> roles)
{
    // TODO
}

vector<Consulta*> ControladorUsuario::listarReservasActivas(string ci)
{
    // TODO
}

ControladorUsuario::darDeBajaReserva(FechaHora fecha)
{
    // TODO
}

vector<string> ControladorUsuario::listarConsultas(Fecha dia)
{
    // TODO
}

Usuario ControladorUsuario::obtenerUsuario(string ci)
{
    // TODO
}

Historial ControladorUsuario::obtenerHistorialPaciente(string ci)
{
    // TODO
}

string ControladorUsuario::obtenerNombreUsuario(string ci)
{
    // TODO
}

string ControladorUsuario::obtenerApellidoUsuario(string ci)
{
    // TODO
}

ControladorUsuario::vincularPacienteConsulta(Usuario usuario, Consulta consulta)
{
    // TODO
}

ControladorUsuario::vincularMedicoConsulta(Usuario medico, Consulta consulta)
{
    // TODO
}
