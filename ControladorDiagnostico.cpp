using namespace std;

#include <string>
#include <vector>

#include "ControladorDiagnostico.h"


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
