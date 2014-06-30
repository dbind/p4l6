#ifndef ISTRATEGYNOTIFICACIONES_H
#define	ISTRATEGYNOTIFICACIONES_H

using namespace std;

#include <string>
#include <vector>

#include "Consulta.h"


class IStrategyNotificaciones
{

public:
	virtual ~IStrategyNotificaciones(){};

	virtual void notificar(Consulta*)=0;
	virtual vector<string> notificaciones()=0;

protected:
	vector<string> _notificaciones {};

};

#endif	/* ISTRATEGYNOTIFICACIONES_H */