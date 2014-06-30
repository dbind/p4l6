#ifndef ICONTROLADORSISTEMA_H
#define	ICONTROLADORSISTEMA_H

#include "Fecha.h"


class IControladorSistema
{

public:
	virtual ~IControladorSistema(){};

private:
	Fecha _actual;

};

#endif	/* ICONTROLADORSISTEMA_H */
