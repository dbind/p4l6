#ifndef ISTRATEGYNOTIFICACIONES_H
#define	ISTRATEGYNOTIFICACIONES_H

#include "Consulta.h"


class IStrategyNotificaciones
{

public:
	virtual ~IStrategyNotificaciones(){};

	virtual void notificar(Consulta*)=0;

};

#endif	/* ISTRATEGYNOTIFICACIONES_H */