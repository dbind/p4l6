using namespace std;

#include <sstream>
#include <string>
#include <vector>

#include "ControladorDiagnostico.h"

#include "Diagnostico.h"
#include "FabricaControladores.h"


/**
 * Instanciación de singleton
 */
ControladorDiagnostico* ControladorDiagnostico::_instancia = 0;

ControladorDiagnostico* ControladorDiagnostico::instancia()
{
	if (_instancia == 0)
	{
		_instancia = new ControladorDiagnostico();
	}
	
	return _instancia;
}

Categoria ControladorDiagnostico::agregarCategoria(char codigo, string etiqueta)
{
	Categoria categoria;

	vector<Categoria>::iterator it = _categorias.begin();

    for (; it != _categorias.end() && (*it).codigo() < codigo ; ++it) {}

	if ((it != _categorias.end()) && ((*it).codigo() == codigo))
	{
		categoria = *it;
	}
	else
	{
		categoria = Categoria(codigo, etiqueta);
		_categorias.insert(it, categoria);
	}

	return categoria;
}

Representacion ControladorDiagnostico::altaRepresentacion(Categoria categoria, string codigo, string etiqueta)
{
	stringstream ss;
	ss << categoria.codigo() << codigo;
	codigo = ss.str();

	vector<Representacion>::iterator it = _representaciones.begin();

    for (; it != _representaciones.end() && (*it).codigo() < codigo ; ++it) {}

	if (it != _representaciones.end() && ((*it).codigo() == codigo))
	{
		throw;
	}

	Representacion representacion = Representacion(categoria, codigo, etiqueta);
	_representaciones.insert(it, representacion);

	return representacion;
}

Diagnostico* ControladorDiagnostico::altaDiagnostico(Consulta* consulta, Representacion representacion,
                                                     string descripcion)
{
	Diagnostico* diagnostico = new Diagnostico(representacion, descripcion);
	consulta->agregarDiagnostico(diagnostico);

	// Notificar al paciente de la consulta que se le hizo diagnóstico
	// (para que éste notifique a sus médicos suscriptores)
	consulta->paciente()->notificarSujeto(consulta);

	return diagnostico;
}

TratamientoFarmacologico* ControladorDiagnostico::agregarTratamientoFarmacologico(Diagnostico* diagnostico,
                                                                                  vector<Farmaco*> farmacos,
                                                                                  string descripcion)
{
	TratamientoFarmacologico* tratamiento = new TratamientoFarmacologico(farmacos, descripcion);
	diagnostico->agregarTratamientoFarmacologico(tratamiento);

	return tratamiento;
}

TratamientoQuirurgico* ControladorDiagnostico::agregarTratamientoQuirurgico(Diagnostico* diagnostico,
                                                                            Usuario* medico, Fecha fecha,
                                                                            string descripcion)
{
	TratamientoQuirurgico* tratamiento = new TratamientoQuirurgico(medico, fecha, descripcion);
	diagnostico->agregarTratamientoQuirurgico(tratamiento);

	return tratamiento;
}
	

vector<Categoria> ControladorDiagnostico::categorias()
{
	return _categorias;
}

vector<Representacion> ControladorDiagnostico::representaciones()
{
	return _representaciones;
}


void ControladorDiagnostico::reset()
{
	_categorias = vector<Categoria> {};
	_representaciones = vector<Representacion> {};
}
