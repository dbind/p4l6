#ifndef STRATEGYNOTIFICACIONES_H
#define	STRATEGYNOTIFICACIONES_H

using namespace std;

#include <string>
#include <vector>

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
	vector<string> notificaciones();

};

#endif	/* STRATEGYNOTIFICACIONES_H */

