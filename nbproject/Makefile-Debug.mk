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
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=gfortran.exe
AS=as.exe

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
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/graphic/Image.o \
	${OBJECTDIR}/src/Particle.o \
	${OBJECTDIR}/src/controls/Joysticks.o \
	${OBJECTDIR}/src/controls/ControlsManager.o \
	${OBJECTDIR}/src/controls/JoystickHatButton.o \
	${OBJECTDIR}/src/graphic/TileMap.o \
	${OBJECTDIR}/src/graphic/Sprite.o \
	${OBJECTDIR}/src/controls/JoystickAxisButton.o \
	${OBJECTDIR}/src/graphic/Tileset.o \
	${OBJECTDIR}/src/controls/Button.o \
	${OBJECTDIR}/src/util/VecteurNorme.o \
	${OBJECTDIR}/src/graphic/Text.o \
	${OBJECTDIR}/src/ParticleType.o \
	${OBJECTDIR}/src/controls/MouseButton.o \
	${OBJECTDIR}/src/controls/JoystickAxis.o \
	${OBJECTDIR}/src/controls/KeyboardKey.o \
	${OBJECTDIR}/src/util/Vecteur.o \
	${OBJECTDIR}/src/controls/Controls.o \
	${OBJECTDIR}/src/controls/JoystickButton.o \
	${OBJECTDIR}/src/ParticleEngine.o \
	${OBJECTDIR}/src/util/GLutils.o \
	${OBJECTDIR}/src/controls/Axis.o \
	${OBJECTDIR}/src/Bonom.o \
	${OBJECTDIR}/src/ObjectsManager.o \
	${OBJECTDIR}/src/graphic/Background.o \
	${OBJECTDIR}/src/graphic/Screen.o \
	${OBJECTDIR}/src/graphic/Draw.o \
	${OBJECTDIR}/src/AppContext.o \
	${OBJECTDIR}/src/controls/JoystickHatAxis.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-Wextra -Weffc++ -std=c++0x
CXXFLAGS=-Wextra -Weffc++ -std=c++0x

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-L/C/libs/SDL-1.2.9/lib -L/C/libs/FTGL/lib -L/C/MinGW/lib -lmingw32 -lSDL -lSDLmain -lSDL.dll -lSDL_image -lftgl.dll -lglew32 /C/MinGW/lib/libglu32.a -lopengl32

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gwift.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gwift.exe: /C/MinGW/lib/libglu32.a

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gwift.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gwift ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/graphic/Image.o: src/graphic/Image.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphic/Image.o src/graphic/Image.cpp

${OBJECTDIR}/src/Particle.o: src/Particle.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Particle.o src/Particle.cpp

${OBJECTDIR}/src/controls/Joysticks.o: src/controls/Joysticks.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/controls
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/controls/Joysticks.o src/controls/Joysticks.cpp

${OBJECTDIR}/src/controls/ControlsManager.o: src/controls/ControlsManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/controls
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/controls/ControlsManager.o src/controls/ControlsManager.cpp

${OBJECTDIR}/src/controls/JoystickHatButton.o: src/controls/JoystickHatButton.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/controls
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/controls/JoystickHatButton.o src/controls/JoystickHatButton.cpp

${OBJECTDIR}/src/graphic/TileMap.o: src/graphic/TileMap.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphic/TileMap.o src/graphic/TileMap.cpp

${OBJECTDIR}/src/graphic/Sprite.o: src/graphic/Sprite.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphic/Sprite.o src/graphic/Sprite.cpp

${OBJECTDIR}/src/controls/JoystickAxisButton.o: src/controls/JoystickAxisButton.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/controls
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/controls/JoystickAxisButton.o src/controls/JoystickAxisButton.cpp

${OBJECTDIR}/src/graphic/Tileset.o: src/graphic/Tileset.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphic/Tileset.o src/graphic/Tileset.cpp

${OBJECTDIR}/src/controls/Button.o: src/controls/Button.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/controls
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/controls/Button.o src/controls/Button.cpp

${OBJECTDIR}/src/util/VecteurNorme.o: src/util/VecteurNorme.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/util
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/util/VecteurNorme.o src/util/VecteurNorme.cpp

${OBJECTDIR}/src/graphic/Text.o: src/graphic/Text.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphic/Text.o src/graphic/Text.cpp

${OBJECTDIR}/src/ParticleType.o: src/ParticleType.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/ParticleType.o src/ParticleType.cpp

${OBJECTDIR}/src/controls/MouseButton.o: src/controls/MouseButton.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/controls
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/controls/MouseButton.o src/controls/MouseButton.cpp

${OBJECTDIR}/src/controls/JoystickAxis.o: src/controls/JoystickAxis.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/controls
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/controls/JoystickAxis.o src/controls/JoystickAxis.cpp

${OBJECTDIR}/src/controls/KeyboardKey.o: src/controls/KeyboardKey.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/controls
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/controls/KeyboardKey.o src/controls/KeyboardKey.cpp

${OBJECTDIR}/src/util/Vecteur.o: src/util/Vecteur.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/util
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/util/Vecteur.o src/util/Vecteur.cpp

${OBJECTDIR}/src/controls/Controls.o: src/controls/Controls.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/controls
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/controls/Controls.o src/controls/Controls.cpp

${OBJECTDIR}/src/controls/JoystickButton.o: src/controls/JoystickButton.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/controls
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/controls/JoystickButton.o src/controls/JoystickButton.cpp

${OBJECTDIR}/src/ParticleEngine.o: src/ParticleEngine.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/ParticleEngine.o src/ParticleEngine.cpp

${OBJECTDIR}/src/util/GLutils.o: src/util/GLutils.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/util
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/util/GLutils.o src/util/GLutils.cpp

${OBJECTDIR}/src/controls/Axis.o: src/controls/Axis.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/controls
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/controls/Axis.o src/controls/Axis.cpp

${OBJECTDIR}/src/Bonom.o: src/Bonom.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/Bonom.o src/Bonom.cpp

${OBJECTDIR}/src/ObjectsManager.o: src/ObjectsManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/ObjectsManager.o src/ObjectsManager.cpp

${OBJECTDIR}/src/graphic/Background.o: src/graphic/Background.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphic/Background.o src/graphic/Background.cpp

${OBJECTDIR}/src/graphic/Screen.o: src/graphic/Screen.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphic/Screen.o src/graphic/Screen.cpp

${OBJECTDIR}/src/graphic/Draw.o: src/graphic/Draw.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/graphic
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/graphic/Draw.o src/graphic/Draw.cpp

${OBJECTDIR}/src/AppContext.o: src/AppContext.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/AppContext.o src/AppContext.cpp

${OBJECTDIR}/src/controls/JoystickHatAxis.o: src/controls/JoystickHatAxis.cpp 
	${MKDIR} -p ${OBJECTDIR}/src/controls
	${RM} $@.d
	$(COMPILE.cc) -g -Wall -Iinclude -I/C/libs/SDL-1.2.9/include -I/C/libs/FTGL/include -I/C/Program\ Files\ \(x86\)/GnuWin32/include -MMD -MP -MF $@.d -o ${OBJECTDIR}/src/controls/JoystickHatAxis.o src/controls/JoystickHatAxis.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/gwift.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
