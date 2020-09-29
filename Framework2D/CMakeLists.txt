project("Framework2D")

link_libraries(glfw)

include_directories("${GLFW_SOURCE_DIR}/deps")

add_definitions(-D_CRT_SECURE_NO_WARNINGS)

# list the header files
set(HEADER_FILES
	Engine.h
	Application.h
	Window.h
	Keyboard.h
	TimeStep.h
	GeomtreyFactory.h
	TextureFactory.h
	Rectangle.h
	Texture2D.h
	Camera2D.h
	ShaderProgram.h
	SpriteRenderer.h
)

# list the source files
set(SOURCE_FILES
	Engine.cpp
	Application.cpp
	Window.cpp
	Keyboard.cpp
	GeomtreyFactory.cpp
	TextureFactory.cpp
	Rectangle.cpp
	Texture2D.cpp
	Camera2D.cpp
	ShaderProgram.cpp
	SpriteRenderer.cpp
)

set(GLAD_GL "${GLFW_SOURCE_DIR}/deps/glad/gl.h"
            "${GLFW_SOURCE_DIR}/deps/glad_gl.c")
			
add_library(Framework2D ${HEADER_FILES} ${SOURCE_FILES} ${GLAD_GL})

set_target_properties(Framework2D ${CONSOLE_BINARIES} PROPERTIES FOLDER "Framework2D")