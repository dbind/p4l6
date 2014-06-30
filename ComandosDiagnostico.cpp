#include <vector>
#include <string> 
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>

#include "ComandosDiagnostico.h"
#include "FabricaControladores.h"
#include "ControladorDiagnostico.h"
#include "Categoria.h"

using namespace std;

void ComandosDiagnostico::altaRepresentacion()
{
	IControladorDiagnostico* cd = FabricaControladores::instancia()->controladorDiagnostico();
	char letra;
	string etiqCat;
	string codDiag;
	string etiqDiag;
	string s;
	
	cout << "Elija la categoria correspondiente (o presione q para salir): " << endl;
	listarCategorias();
	cout << "Si la categoria que desea no se encuentra en la lista presione n para"
			" agregar una (o presione q para salir): " << endl;
	cin >> s;
	
	if (s=="q")
		return;
	
	if (s=="n")
	{
		cout << "Ingrese la letra de la categoría que desea agregar (o presione q para salir):" << endl;
		cin >> letra;
		if (letra==('q'))
			return;
		
		cout << "Ingrese la etiqueta de la categoría (o presione q para salir):" << endl;
		cin >> etiqCat;
		
		if (etiqCat=="q")
			return;
				
		Categoria cat = cd->agregarCategoria(letra, etiqCat);
		
		do
		{
			cout << "Ingrese un número de dos cifras correspondiente al codigo"
					" del diagnóstico (o presione q para salir):" << endl;
			cin >> codDiag;
			
			if(codDiag=="q")
				return;
			
			cout << "Ingrese la descripcion del diagnostico (o presione q para salir):" << endl;
			cin >> etiqDiag;
						
			if(etiqDiag=="q")
				return;
			
			cd->altaRepresentacion(cat, codDiag, etiqDiag);
		}
		while (true);
	}
	else
	{
		vector<Categoria> categorias = cd->categorias();
		int i;
		char *cstr = new char[s.length() + 1];
		strcpy(cstr, s.c_str());
		i = atoi(cstr);
		delete [] cstr;
		Categoria cat = categorias.at(i-1);
		do
		{
			cout << "Ingrese un número de dos cifras correspondiente al codigo"
					"del diagnóstico (o presione q para salir):" << endl;
			cin >> codDiag;
			
			if(codDiag=="q")
				return;
			
			cout << "Ingrese la descripcion del diagnostico (o presione q para salir):" << endl;
			cin >> etiqDiag;
						
			if(etiqDiag=="q")
				return;
			
			cd->altaRepresentacion(cat, codDiag, etiqDiag);
		}
		while (true);						
	}		
}

void ComandosDiagnostico::listarCategorias()
{
	vector<Categoria> categorias = FabricaControladores::instancia()->controladorDiagnostico()
	                                                                ->categorias();
	vector<Categoria>::iterator it;
	Categoria categoria;
	
	int i = 1;

    for (it=categorias.begin(); it != categorias.end(); ++it)
    {
		stringstream ss;
		string s;
		categoria = *it;
		ss << categoria.codigo();
		ss >> s;
		
		cout << i << "- " << s << " " << categoria.etiqueta() << endl;
		ss.str(string());
		i++;
    }
}

void ComandosDiagnostico::listarRepresentaciones()
{
	
}
		
