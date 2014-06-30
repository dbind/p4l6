using namespace std;

#include <string>
#include <vector>

#include "ControladorDiagnostico.h"

#include "Diagnostico.h"


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

	vector<Categoria>::iterator it;

    for (it=_categorias.begin(); it != _categorias.end(); ++it)
    {
		categoria = *it;

		if (categoria.codigo() == codigo)
		{
			return categoria;
		}
    }

	categoria = Categoria(codigo, etiqueta);
	_categorias.insert(_categorias.begin(), categoria);

	return categoria;
}

Representacion ControladorDiagnostico::altaRepresentacion(Categoria categoria, string codigo, string etiqueta)
{
	Representacion representacion;

	vector<Representacion>::iterator it;

    for (it=_representaciones.begin(); it != _representaciones.end(); ++it)
    {
		representacion = *it;

		if ((representacion.codigo() == codigo)
		&& (representacion.categoria().codigo() == categoria.codigo()))
		{
			return representacion;
		}
    }

	representacion = Representacion(categoria, codigo, etiqueta);
	_representaciones.insert(_representaciones.begin(), representacion);

	return representacion;
}

Diagnostico* ControladorDiagnostico::altaDiagnostico(Consulta* consulta, Representacion representacion,
                                                     string descripcion)
{
	consulta->agregarDiagnostico(new Diagnostico(representacion, descripcion));
}

TratamientoFarmacologico* ControladorDiagnostico::agregarTratamientoFarmacologico(Diagnostico* diagnostico,
                                                                                  Farmaco* farmaco,
                                                                                  string descripcion)
{
	TratamientoFarmacologico* tratamiento = new TratamientoFarmacologico(farmaco, descripcion);
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

