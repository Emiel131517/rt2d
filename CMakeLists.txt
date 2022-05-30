# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (rt2d)

# delete CMakeCache.txt from the build directory when you edit these options
####################################################################
OPTION(MAKE_JUMPY "Make Jumpy game application" ON)

OPTION(USE_RS232 "Use RS232 library" OFF)
OPTION(MAKE_SERIAL "Make serial application" OFF)

OPTION(USE_OPENAL "Use OpenAL library" OFF)
OPTION(MAKE_AUDIOSTART "Make OpenAL/RT2D audiostart" OFF)
OPTION(MAKE_OPENAL_TONEGEN "Make OpenAL Tone Generator" OFF)

OPTION(USE_BOX2D "Use Box2D" OFF)
OPTION(MAKE_BOX2DSTART "Make Box2D/RT2D box2dstart" OFF)
####################################################################

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like 'build')" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()


if(UNIX)
	#set(CMAKE_CXX_FLAGS "-Wall -std=c++0x -pedantic -O2 -g -pg")
	#set(CMAKE_CXX_FLAGS "-Wall -Wstrict-aliasing -std=c++0x -O2")

	set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -O2")

	# valgrind --leak-check=full ./demo
	# ./demo # creates cmon.out
	# gprof demo gmon.out > analysis.txt
	#set(CMAKE_CXX_FLAGS "-Wall -pg -std=c++11")
endif(UNIX)


if(WIN32)
	# suppress pedantic warnings
	add_definitions( "/W1 /D_CRT_SECURE_NO_WARNINGS /wd4514 /nologo" )
endif(WIN32)


# Compile external dependencies
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

add_subdirectory (external)

include_directories(
	${CMAKE_SOURCE_DIR}/external/glfw-3.3/include/GLFW
	${CMAKE_SOURCE_DIR}/external/glm-0.9.9.2
	${CMAKE_SOURCE_DIR}/external/glew-1.9.0/include
	${CMAKE_SOURCE_DIR}/external
	${CMAKE_SOURCE_DIR}/rt2d
	${CMAKE_SOURCE_DIR}/.
)

link_directories(
	${CMAKE_SOURCE_DIR}/external/glfw-3.3/src
	${CMAKE_SOURCE_DIR}/external/glew-1.9.0
	${CMAKE_SOURCE_DIR}/external
	${CMAKE_SOURCE_DIR}/rt2d
)

set(ALL_GRAPHICS_LIBS
	${OPENGL_LIBRARY}
	rt2d
	glfw
	GLEW_190
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

####################################################################
# librt2d.a                                                        #
####################################################################
add_library(rt2d
	rt2d/camera.cpp
	rt2d/camera.h
	rt2d/canvas.cpp
	rt2d/canvas.h
	rt2d/color.h
	rt2d/core.cpp
	rt2d/core.h
	rt2d/entity.cpp
	rt2d/entity.h
	rt2d/input.cpp
	rt2d/input.h
	rt2d/line.cpp
	rt2d/line.h
	rt2d/mesh.cpp
	rt2d/mesh.h
	rt2d/noise.cpp
	rt2d/noise.h
	rt2d/pointx.h
	rt2d/renderer.cpp
	rt2d/renderer.h
	rt2d/resourcemanager.cpp
	rt2d/resourcemanager.h
	rt2d/rt2dconfig.h
	rt2d/scene.cpp
	rt2d/scene.h
	rt2d/shader.cpp
	rt2d/shader.h
	rt2d/sprite.cpp
	rt2d/sprite.h
	rt2d/text.cpp
	rt2d/text.h
	rt2d/texture.cpp
	rt2d/texture.h
	rt2d/timer.cpp
	rt2d/timer.h
	rt2d/util.c
	rt2d/util.h
	rt2d/vectorx.h
)
file(
	COPY ${CMAKE_SOURCE_DIR}/rt2d/shaders
	DESTINATION ${CMAKE_BINARY_DIR}
)
file(
	COPY ${CMAKE_SOURCE_DIR}/rt2d/fonts
	DESTINATION ${CMAKE_BINARY_DIR}
)
####################################################################
# Jumpy                                                            #
####################################################################
IF(MAKE_JUMPY)
	add_executable(Jumpy
		projects/Jumpy/Main.cpp
		projects/Jumpy/Player.cpp
		projects/Jumpy/Player.h
		projects/Jumpy/MainScene.cpp
		projects/Jumpy/MainScene.h
		projects/Jumpy/Platform.cpp
		projects/Jumpy/Platform.h
		projects/Jumpy/Background.cpp
		projects/Jumpy/Background.h
		projects/Jumpy/GameEntity.h
		projects/Jumpy/GameEntity.cpp
		projects/Jumpy/Collider.h
		projects/Jumpy/PlayerData.h
		projects/Jumpy/PlayerData.cpp
		projects/Jumpy/HudContainer.h
		projects/Jumpy/HudContainer.cpp
		projects/Jumpy/DeathBall.h
		projects/Jumpy/DeathBall.cpp
		projects/Jumpy/LayerEntity.h
		projects/Jumpy/LayerEntity.cpp
		projects/Jumpy/JumpBar.h
		projects/Jumpy/JumpBar.cpp
	)
	target_link_libraries(Jumpy
		${ALL_GRAPHICS_LIBS}
	)
	# Copy assets to the build directory
	file(
		COPY projects/Jumpy/assets
		DESTINATION ${CMAKE_BINARY_DIR}
	)
ENDIF()

####################################################################
