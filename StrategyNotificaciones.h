#ifndef STRATEGYNOTIFICACIONES_H
#define	STRATEGYNOTIFICACIONES_H

#include "IStrategyNotificaciones.h"

#include "Consulta.h"


/**
 * Realiza IStrategyNotificaciones
 */
class StrategyNotificaciones : public IStrategyNotificaciones
{

public:
	StrategyNotificaciones(){};

	void notificar(Consulta*);

};

#endif	/* STRATEGYNOTIFICACIONES_H */

