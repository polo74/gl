
################ Glfw ################
# Settings

ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.2.1)

################ ... ################
# Setings

set(OPENGL_LIBRARY
	${OPENGL_LIBRARY}
	-lGL -lGLU -lXrandr -lXext -lX11 -lrt
	${CMAKE_DL_LIBS}
	${GLFW_LIBRARIES}
)

### Glew ###

set(GLEW_SOURCE
	glew-2.1.0/src/glew.c
)

add_library(glew STATIC
	${GLEW_SOURCE}
	${GLEW_INCLUDE}
)

target_link_libraries(glew
	${OPENGL_LIBRARY}
	${EXTRA_LIBS}
)

################ Glm ################

ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/glm-0.9.9.5/glm)
