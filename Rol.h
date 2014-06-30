#ifndef ROL_H
#define	ROL_H

using namespace std;

#include <iostream>
#include <string>
#include <vector>


enum class Rol {master, admin, medico, socio};


// Shortcut por practicidad
typedef vector<Rol> Roles;


inline ostream& operator<<(ostream& os, const Rol& rol)
{
	     if (rol == Rol::master) os << "master";
	else if (rol == Rol::admin ) os << "admin";
	else if (rol == Rol::medico) os << "medico";
	else if (rol == Rol::socio ) os << "socio";

    return os;
}


#endif	/* ROL_H */

