#ifndef CONSULTA_H
#define CONSULTA_H

using namespace std;

#include <vector>

#include "Fecha.h"


class Diagnostico;
class Usuario;


class Consulta
{
    private:
        FechaHora fecha;
        TipoAsis asistio;

        Usuario* Medico;
        Usuario* Paciente;
        vector<Diagnostico> Diagnosticos;


    public:
        Consulta();
        virtual ~Consulta();

        FechaHora getFecha();
        TipoAsis getAsistio();

        setFecha(FechaHora fecha);
        setAsistio(TipoAsis asis);

public:
	Consulta(){};
	virtual ~Consulta(){};

	Usuario* medico();
	Usuario* paciente();
	Fecha fechaConsulta();

	vector<Diagnostico*> diagnosticos();
	void agregarDiagnostico(Diagnostico*);

protected:
	Usuario* _medico;
	Usuario* _paciente;
	Fecha _consulta;

	vector<Diagnostico*> _diagnosticos;

};

#endif // CO
