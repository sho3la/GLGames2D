project("SpaceForce2D")

link_libraries(Framework2D)

include_directories(
			"${GLFW_SOURCE_DIR}/deps"
			"${Framework2D_SOURCE_DIR}/")
			
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

if (WIN32)
    set(ICON SpaceForce2D.rc)
endif()

# list the header files
set(HEADER_FILES
	Game.h
	State.h
	IntroState.h
	GameState.h
	Player.h
	Background.h
	Gun.h
	Enemy.h
)

# list the source files
set(SOURCE_FILES
	main.cpp
	Game.cpp
	IntroState.cpp
	GameState.cpp
	Player.cpp
	Background.cpp
	Gun.cpp
	Enemy.cpp
)

add_executable(SpaceForce2D WIN32 ${HEADER_FILES} ${SOURCE_FILES} ${ICON})

set_target_properties(SpaceForce2D ${CONSOLE_BINARIES} PROPERTIES FOLDER "GAMES")

# Tell MSVC to use main instead of WinMain for Windows subsystem executables
set_target_properties(SpaceForce2D PROPERTIES LINK_FLAGS "/ENTRY:mainCRTStartup")

# copy resources folder to exe folder
add_custom_command(
    TARGET SpaceForce2D POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/res
	$<TARGET_FILE_DIR:SpaceForce2D>/res
)

# copy resources folder to .sln folder
add_custom_command(
    TARGET SpaceForce2D POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/res 
	${CMAKE_CURRENT_BINARY_DIR}/res
)