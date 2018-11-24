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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/AppArcana.o \
	${OBJECTDIR}/src/CEntGUIMenuChangeColorGauge.o \
	${OBJECTDIR}/src/CtxCity.o \
	${OBJECTDIR}/src/CtxDungeon.o \
	${OBJECTDIR}/src/CtxLogoDakiisoft.o \
	${OBJECTDIR}/src/CtxLogoHal.o \
	${OBJECTDIR}/src/CtxNewChapter.o \
	${OBJECTDIR}/src/CtxOvermap.o \
	${OBJECTDIR}/src/CtxPrologue.o \
	${OBJECTDIR}/src/CtxShop.o \
	${OBJECTDIR}/src/CtxStory.o \
	${OBJECTDIR}/src/CtxTitle.o \
	${OBJECTDIR}/src/MngArcanaRPG.o \
	${OBJECTDIR}/src/MngGUIArcana.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/arcana

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/arcana: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/arcana ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/AppArcana.o: src/AppArcana.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/AppArcana.o src/AppArcana.cpp

${OBJECTDIR}/src/CEntGUIMenuChangeColorGauge.o: src/CEntGUIMenuChangeColorGauge.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CEntGUIMenuChangeColorGauge.o src/CEntGUIMenuChangeColorGauge.cpp

${OBJECTDIR}/src/CtxCity.o: src/CtxCity.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CtxCity.o src/CtxCity.cpp

${OBJECTDIR}/src/CtxDungeon.o: src/CtxDungeon.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CtxDungeon.o src/CtxDungeon.cpp

${OBJECTDIR}/src/CtxLogoDakiisoft.o: src/CtxLogoDakiisoft.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CtxLogoDakiisoft.o src/CtxLogoDakiisoft.cpp

${OBJECTDIR}/src/CtxLogoHal.o: src/CtxLogoHal.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CtxLogoHal.o src/CtxLogoHal.cpp

${OBJECTDIR}/src/CtxNewChapter.o: src/CtxNewChapter.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CtxNewChapter.o src/CtxNewChapter.cpp

${OBJECTDIR}/src/CtxOvermap.o: src/CtxOvermap.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CtxOvermap.o src/CtxOvermap.cpp

${OBJECTDIR}/src/CtxPrologue.o: src/CtxPrologue.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CtxPrologue.o src/CtxPrologue.cpp

${OBJECTDIR}/src/CtxShop.o: src/CtxShop.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CtxShop.o src/CtxShop.cpp

${OBJECTDIR}/src/CtxStory.o: src/CtxStory.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CtxStory.o src/CtxStory.cpp

${OBJECTDIR}/src/CtxTitle.o: src/CtxTitle.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/CtxTitle.o src/CtxTitle.cpp

${OBJECTDIR}/src/MngArcanaRPG.o: src/MngArcanaRPG.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/MngArcanaRPG.o src/MngArcanaRPG.cpp

${OBJECTDIR}/src/MngGUIArcana.o: src/MngGUIArcana.cpp
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/MngGUIArcana.o src/MngGUIArcana.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
