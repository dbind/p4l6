#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>

#include "../include/TipoSexo.h"
#include "../include/Fecha.h"
#include "../include/Consulta.h"


class Usuario
{
		
	friend class IControladorUsuario;
		
    private:
        string cedula;
        string nombre;
        string apellido;
        TipoSexo sexo;
        Fecha fechaNacimiento;
        string contrasenya;
        bool activo;
        bool haIniciadoSesion;

    public:
        Usuario();
        virtual ~Usuario();

        string getCedula();
        string getNombre();
        string getApellido();
        TipoSexo getSexo();
        Fecha getFechaNacimiento();
        string getContrasenya();
        bool getActivo();
        bool getHaIniciadoSesion();

        setCedula(string cedula);
        setNombre(string nombre);
        setApellido(string apellido);
        setSexo(TipoSexo sexo);
        setFechaNacimiento(Fecha fecha);
        setContraseña(string contrasenya);
        setActivo(bool activo);
        setHaIniciadoSesion(bool yaInicio);

        int calcularEdad();
        int calcularInasistencias();
        bool esValidaContrasenya(string contrasenya);
        vector<Consulta> listarConsultas();
        vector<Consulta> listarConsultasComunes();
        vector<Consulta> getConsultasAtendidas();
        Consulta obtenerConsulta();
};

#endif // USUARIO_H
