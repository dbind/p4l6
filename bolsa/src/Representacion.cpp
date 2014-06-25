#include "../include/Representacion.h"

Representacion::Representacion()
{
    // TODO
}

Representacion::~Representacion()
{
    // TODO
}


char getCategoria()
{
    return this->categoria;
}

string getPatologia()
{
    return this->patologia;
}

string getEtiqueta()
{
    return this->etiqueta;
}

string getEtiquetaCategoria()
{
    return this->etiquetaCategoria;
}

setCategoria(char categoria)
{
    this->categoria = categoria;
}

setPatologia(string patologia)
{
    this->patologia = patologia;
}

setEtiqueta(string etiqueta)
{
    this->etiqueta = etiqueta;
}

setEtiquetaCategoria(string etiquetaCategoria)
{
    this->etiquetaCategoria = etiquetaCategoria;
}


string obtenerCodigoRepresentacion()
{
    // TODO
}
