#ifndef ICONTROLADORSISTEMA_H
#define	ICONTROLADORSISTEMA_H

#include "Fecha.h"


class IControladorSistema
{

public:
	virtual ~IControladorSistema(){};

	virtual Fecha getFechaDelSistema()=0;
	virtual void setFechaDelSistema(Fecha)=0;

	virtual void reset()=0;

protected:
	Fecha _fecha;

};

#endif	/* ICONTROLADORSISTEMA_H */
