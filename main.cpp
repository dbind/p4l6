#include "FabricaControladores.h"


int main(int argc, char** argv)
{
	FabricaControladores::instancia()->controladorMenu()->iniciar();

	return 0;
}
