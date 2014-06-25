#include "../include/ControladorDiagnostico.h"


ControladorDiagnostico* ControladorDiagnostico::instancia()
{
    if (this->_instancia == 0)
        this->_instancia = new ControladorDiagnostico;

    return this->_instancia;
}

vector<Representacion> ControladorDiagnostico::getRepresentaciones()
{
    return this->representaciones;
}

Representacion ControladorDiagnostico::getRepresentacionSeleccionada()
{
    return this->representacionSeleccionada;
}

Diagnostico ControladorDiagnostico::getDiagnostico()
{
    return this->diagnostico;
}

Tratamiento ControladorDiagnostico::getTratamiento()
{
    return this->tratamiento;
}

vector<Farmaco> ControladorDiagnostico::getFarmacos()
{
    return this->farmacos;
}

ControladorDiagnostico::setRepresentaciones(vector<Representacion> representaciones)
{
    this->representaciones = representaciones;
}

ControladorDiagnostico::setRepresentacionSeleccionada(Representacion representacionSeleccionada)
{
    this->representacionSeleccionada = representacionSeleccionada;
}

ControladorDiagnostico::setDiagnostico(Diagnostico diagnostico)
{
    this->diagnostico = diagnostico;
}

ControladorDiagnostico::setTratamiento(Tratamiento tratamiento)
{
    this->tratamiento = tratamiento;
}

ControladorDiagnostico::setFarmacos(vector<Farmaco> farmacos)
{
    this->farmacos = farmacos;
}


vector<char> ControladorDiagnostico::listarCategoriasRepresentacion()
{
    // TODO
}

vector<Representacion> ControladorDiagnostico::listarRepresentacionesPorCategoria(char categoria)
{
    // TODO
}

ControladorDiagnostico::elegirRepresentacion(string patologia)
{
    // TODO
}

Diagnostico ControladorDiagnostico::crearDiagnostico()
{
    // TODO
}

ControladorDiagnostico::agregarDescripcion(string descripcion)
{
    // TODO
}

ControladorDiagnostico::definirTratamiento(TipoTratamiento tipo, string descripcion)
{
    // TODO
}

ControladorDiagnostico::agregarDataTratamientoQuirurgico(FechaHora fecha, string ciMedico)
{
    // TODO
}

ControladorDiagnostico::agregarFarmaco(string nombreFarmaco)
{
    // TODO
}

ControladorDiagnostico::aceptarTratamiento()
{
    // TODO
}

ControladorDiagnostico::aceptarDiagnostico()
{
    // TODO
}

ControladorDiagnostico::cancelarDiagnostico()
{
    // TODO
}

ControladorDiagnostico::cancelarTratamiento()
{
    // TODO
}

ControladorDiagnostico::aceptarDiagnosticos()
{
    // TODO
}

ControladorDiagnostico::Diagnostico obtenerDiagnosticoRecordado()
{
    // TODO
}

ControladorDiagnostico::vaciarDiagnosticoRecordado()
{
    // TODO
}
