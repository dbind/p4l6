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
	${OBJECTDIR}/Comando.o \
	${OBJECTDIR}/ControladorComando.o \
	${OBJECTDIR}/ControladorConsulta.o \
	${OBJECTDIR}/ControladorDiagnostico.o \
	${OBJECTDIR}/ControladorMenu.o \
	${OBJECTDIR}/ControladorSesion.o \
	${OBJECTDIR}/ControladorUsuario.o \
	${OBJECTDIR}/FabricaControladores.o \
	${OBJECTDIR}/Fecha.o \
	${OBJECTDIR}/FechaHora.o \
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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lab6_d.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lab6_d.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lab6_d ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Comando.o: Comando.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Comando.o Comando.cpp

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

${OBJECTDIR}/FabricaControladores.o: FabricaControladores.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FabricaControladores.o FabricaControladores.cpp

${OBJECTDIR}/Fecha.o: Fecha.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Fecha.o Fecha.cpp

${OBJECTDIR}/FechaHora.o: FechaHora.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Werror -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/FechaHora.o FechaHora.cpp

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
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/lab6_d.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
