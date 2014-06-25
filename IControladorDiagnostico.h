#ifndef ICONTROLADORDIAGNOSTICO_H
#define	ICONTROLADORDIAGNOSTICO_H


class IControladorDiagnostico
{

public:
	virtual ~IControladorDiagnostico(){};
	virtual void testControlador()=0;

};

#endif	/* ICONTROLADORDIAGNOSTICO_H */

