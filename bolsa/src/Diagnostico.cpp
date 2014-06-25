#include "../include/Diagnostico.h"

Diagnostico::Diagnostico()
{
    // TODO
}

Diagnostico::~Diagnostico()
{
    // TODO
}


string Diagnostico::getDescripcion()
{
    return this->descripcion;
}

vector<Tratamiento*> Diagnostico::getTratamientos()
{
    return this->tratamientos;
}

vector<DataTratamiento> Diagnostico::getDataTratamientos()
{
    return this->dataTratamientos;
}

Diagnostico::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}

Diagnostico::setTratamientos(vector<Tratamiento*> lista)
{
    this->tratamientos = lista;
}

Diagnostico::setDataTratamientos(vector<DataTratamiento> lista)
{
    this->dataTratamientos = lista;
}


char Diagnostico::getCategoria()
{
    // TODO
}

string Diagnostico::getEtiqueta()
{
    // TODO
}

vector<Tratamiento> Diagnostico::getTratamientos()
{
    // TODO
}

vector<TratamientoQuirurgico> Diagnostico::getTratamientosQuirurgicos()
{
    // TODO
}

vector<Farmaco> Diagnostico::getFarmacos()
{
    // TODO
}

Diagnostico::agregarTratamiento(Tratamiento tratamiento)
{
    // TODO
}

DataDiagnostico Diagnostico::obtenerDataDiagnostico()
{
    // TODO
}
