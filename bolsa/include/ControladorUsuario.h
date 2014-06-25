#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include <vector>
#include <string>

#include "../interfaces/Singleton.h"

#include "../includes/Usuario.h"
#include "../includes/Diagnostico.h"
#include "../includes/EstadoUsuario.h"
#include "../includes/Sesion.h"
#include "../includes/Consulta.h"
#include "../includes/TipoSexo.h"
#include "../includes/Historial.h"
#include "../includes/Rol.h"
#include "../includes/Fecha.h"
#include "../includes/FechaHora.h"


class ControladorUsuario : public Singleton
{
    private:
        ControladorUsuario() = 0;
        static ControladorUsuario* _instancia;

        vector<Usuario*> usuarios;
        Sesion sesion;

    public:
        static ControladorUsuario* instancia();

        vector<Usuario*> getUsuarios();
        Sesion getSesion();
        void setUsuarios(vector<Usuario*> usuarios);
        void setSesion(Sesion sesion);

        EstadoUsuario estadoIniciarSesion(string ci);
        bool existeUsuario(string ci);
        bool estaActivoUsuario(string ci);
        void reactivarUsuario(string ci);
        void altaUsuario(string ci, string nombre, string apellido, TipoSexo sexo, Fecha fecNac, vector<Rol> roles);
        vector<Consulta*> listarReservasActivas(string ci);
        void darDeBajaReserva(FechaHora fecha);
        vector<string> listarConsultas(Fecha dia);
        Usuario obtenerUsuario(string ci);
        Historial obtenerHistorialPaciente(string ci);
        string obtenerNombreUsuario(string ci);
        string obtenerApellidoUsuario(string ci);
        void vincularPacienteConsulta(Usuario usuario, Consulta consulta);
        void vincularMedicoConsulta(Usuario medico, Consulta consulta);
};

#endif // CONTROLADORUSUARIO_H
