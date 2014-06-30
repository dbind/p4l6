#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Categoria.o \
	${OBJECTDIR}/Comando.o \
	${OBJECTDIR}/ComandosConsulta.o \
	${OBJECTDIR}/ComandosDiagnostico.o \
	${OBJECTDIR}/ComandosFarmaco.o \
	${OBJECTDIR}/ComandosNotificacion.o \
	${OBJECTDIR}/ComandosSistema.o \
	${OBJECTDIR}/ComandosUsuario.o \
	${OBJECTDIR}/ControladorComando.o \
	${OBJECTDIR}/ControladorConsulta.o \
	${OBJECTDIR}/ControladorDiagnostico.o \
	${OBJECTDIR}/ControladorFarmaco.o \
	${OBJECTDIR}/ControladorMenu.o \
	${OBJECTDIR}/ControladorSesion.o \
	${OBJECTDIR}/ControladorUsuario.o \
	${OBJECTDIR}/Diagnostico.o \
	${OBJECTDIR}/FabricaControladores.o \
	${OBJECTDIR}/Farmaco.o \
	${OBJECTDIR}/Fecha.o \
	${OBJECTDIR}/FechaHora.o \
	${OBJECTDIR}/Representacion.o \
	${OBJECTDIR}/Tratamiento.o \
	${OBJECTDIR}/TratamientoFarmacologico.o \
	${OBJECTDIR}/TratamientoQuirurgico.o \
	${OBJECTDIR}/Usuario.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lab6.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lab6.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lab6 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Categoria.o: Categoria.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Categoria.o Categoria.cpp

${OBJECTDIR}/Comando.o: Comando.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Comando.o Comando.cpp

${OBJECTDIR}/ComandosConsulta.o: ComandosConsulta.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ComandosConsulta.o ComandosConsulta.cpp

${OBJECTDIR}/ComandosDiagnostico.o: ComandosDiagnostico.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ComandosDiagnostico.o ComandosDiagnostico.cpp

${OBJECTDIR}/ComandosFarmaco.o: ComandosFarmaco.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ComandosFarmaco.o ComandosFarmaco.cpp

${OBJECTDIR}/ComandosNotificacion.o: ComandosNotificacion.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ComandosNotificacion.o ComandosNotificacion.cpp

${OBJECTDIR}/ComandosSistema.o: ComandosSistema.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ComandosSistema.o ComandosSistema.cpp

${OBJECTDIR}/ComandosUsuario.o: ComandosUsuario.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ComandosUsuario.o ComandosUsuario.cpp

${OBJECTDIR}/ControladorComando.o: ControladorComando.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ControladorComando.o ControladorComando.cpp

${OBJECTDIR}/ControladorConsulta.o: ControladorConsulta.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ControladorConsulta.o ControladorConsulta.cpp

${OBJECTDIR}/ControladorDiagnostico.o: ControladorDiagnostico.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ControladorDiagnostico.o ControladorDiagnostico.cpp

${OBJECTDIR}/ControladorFarmaco.o: ControladorFarmaco.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ControladorFarmaco.o ControladorFarmaco.cpp

${OBJECTDIR}/ControladorMenu.o: ControladorMenu.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ControladorMenu.o ControladorMenu.cpp

${OBJECTDIR}/ControladorSesion.o: ControladorSesion.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ControladorSesion.o ControladorSesion.cpp

${OBJECTDIR}/ControladorUsuario.o: ControladorUsuario.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/ControladorUsuario.o ControladorUsuario.cpp

${OBJECTDIR}/Diagnostico.o: Diagnostico.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Diagnostico.o Diagnostico.cpp

${OBJECTDIR}/FabricaControladores.o: FabricaControladores.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FabricaControladores.o FabricaControladores.cpp

${OBJECTDIR}/Farmaco.o: Farmaco.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Farmaco.o Farmaco.cpp

${OBJECTDIR}/Fecha.o: Fecha.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Fecha.o Fecha.cpp

${OBJECTDIR}/FechaHora.o: FechaHora.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FechaHora.o FechaHora.cpp

${OBJECTDIR}/Representacion.o: Representacion.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Representacion.o Representacion.cpp

${OBJECTDIR}/Tratamiento.o: Tratamiento.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Tratamiento.o Tratamiento.cpp

${OBJECTDIR}/TratamientoFarmacologico.o: TratamientoFarmacologico.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TratamientoFarmacologico.o TratamientoFarmacologico.cpp

${OBJECTDIR}/TratamientoQuirurgico.o: TratamientoQuirurgico.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TratamientoQuirurgico.o TratamientoQuirurgico.cpp

${OBJECTDIR}/Usuario.o: Usuario.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Usuario.o Usuario.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lab6.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
