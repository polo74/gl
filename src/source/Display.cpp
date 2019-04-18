#include <Display.hpp>

#include <cstdio>

//////////////// Public ////////////////

Display::Display(){
  if(initGlfw() && initGlew() && initGlfwInput()){
    fprintf(stdout, "%s\n", "Initialization of OpenGL : OK");
  }
}

Display::~Display(){
  if (finishGLew() && finishGlfw()) {
    fprintf(stdout, "%s\n", "Destruction of OpenGL : OK");
  }
}

void Display::loop(){
  do{
    glfwSwapBuffers(window);
    glfwPollEvents();
  }while(glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS);
}

//////////////// Private ////////////////

bool Display::initGlfw(){
  int res = true;
  if(!glfwInit()){
    fprintf(stderr, "%s\n", "Failed to initialise GLFW");
    res = false;
  }else{
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(1024, 768, "Test", NULL, NULL);

    if (window == NULL) {
      fprintf(stderr, "%s\n", "Erreur while initialising the GLFW window");
      glfwTerminate();
    }else{
      glfwMakeContextCurrent(window);
      fprintf(stdout, "%s\n", "Initialisation of GLFW : OK");
    }
  }
  return res;
}

bool Display::initGlfwInput(){
  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
}

bool Display::initGlew(){
  int res = true;
  glewExperimental = true;
  if(glewInit() != GLEW_OK){
    fprintf(stderr, "%s\n", "Failed to initialise GLEW");
    res = false;
  }else{
    fprintf(stdout, "%s\n", "Initialisation of GLEW : OK");
  }
  return res;
}

bool Display::finishGLew(){
  return true;
}

bool Display::finishGlfw(){
  glfwTerminate();
  return true;
}
