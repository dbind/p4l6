#include "../include/Usuario.h"

Usuario::Usuario()
{
    // TODO
}

Usuario::~Usuario()
{
    // TODO
}


string Usuario::getCedula()
{
    return this->cedula;
}

string Usuario::getNombre()
{
    return this->nombre;
}

string Usuario::getApellido()
{
    return this->apellido;
}

TipoSexo Usuario::getSexo()
{
    return this->sexo;
}

Fecha Usuario::getFechaNacimiento()
{
    return this->fechaNacimiento;
}

string Usuario::getContrasenya()
{
    return this->contrasenya;
}

bool Usuario::getActivo()
{
    return this->activo;
}

bool Usuario::getHaIniciadoSesion()
{
    return this->haIniciadoSesion;
}

Usuario::setCedula(string cedula)
{
    this->cedula = cedula;
}

Usuario::setNombre(string nombre)
{
    this->nombre = nombre;
}

Usuario::setApellido(string apellido)
{
    this->apellido = apellido;
}

Usuario::setSexo(TipoSexo sexo)
{
    this->sexo = sexo;
}

Usuario::setFechaNacimiento(Fecha fecha)
{
    this->fechaNacimiento = fecha;
}

Usuario::setContraseña(string contrasenya)
{
    this->contrasenya = contrasenya;
}

Usuario::setActivo(bool activo)
{
    this->activo = activo;
}

Usuario::setHaIniciadoSesion(bool yaInicio)
{
    this->haIniciadoSesion = yaInicio;
}


int Usuario::calcularEdad()
{
    // TODO
}

int Usuario::calcularInasistencias()
{
    // TODO
}

vector<Consulta> Usuario::listarConsultas()
{
    // TODO
}

vector<Consulta> Usuario::listarConsultasComunes()
{
    // TODO
}

vector<Consulta> Usuario::getConsultasAtendidas()
{
    // TODO
}

Consulta Usuario::obtenerConsulta()
{
    // TODO
}


static Usuario::esValidaContrasenya(string contrasenya)
{
    // TODO
}
