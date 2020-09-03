project("SpaceForce2D")

link_libraries(Framework2D)

include_directories(
			"${GLFW_SOURCE_DIR}/deps"
			"${Framework2D_SOURCE_DIR}/")
			
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

# list the header files
set(HEADER_FILES)

# list the source files
set(SOURCE_FILES
	main.cpp
)

add_executable(SpaceForce2D WIN32 ${HEADER_FILES} ${SOURCE_FILES})

set_target_properties(SpaceForce2D ${CONSOLE_BINARIES} PROPERTIES FOLDER "GAMES")

# Tell MSVC to use main instead of WinMain for Windows subsystem executables
set_target_properties(SpaceForce2D PROPERTIES LINK_FLAGS "/ENTRY:mainCRTStartup")