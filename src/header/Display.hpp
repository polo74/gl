#ifndef DISPLAY_H
#define DISPLAY_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Display{
public:
  Display();
  ~Display();

  void loop();

private:
  bool initGlew();
  bool initGlfw();
  bool initGlfwInput();

  bool finishGLew();
  bool finishGlfw();

  GLFWwindow * window;
};

#endif
