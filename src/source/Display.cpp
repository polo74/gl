#include <Display.hpp>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <cstdio>

//////////////// Public ////////////////

Display::Display(){
  fprintf(stdout, "%s\n", "Initialisation of OpenGL : ");
  if(!initGlfw()){

  }else if (!initGlew()) {
    /* code */
  }else{
    fprintf(stdout, "%s\n", "Initialisation of OpenGL : OK");
  }
}

Display::~Display(){
  fprintf(stdout, "%s\n", "Destruction of OpenGL");
}

//////////////// Private ////////////////

bool Display::initGlfw(){
  int res = true;
  if(!glfwInit()){
    fprintf(stderr, "%s\n", "Failed to initialise GLFW");
    res = false;
  }else{
    fprintf(stdout, "%s\n", "Initialisation of GLFW : OK");
  }
  return res;
}

bool Display::initGlew(){
  int res = true;
  if(glewInit() != GLEW_OK){
    fprintf(stderr, "%s\n", "Failed to initialise GLEW");
    res = false;
  }else{
    fprintf(stdout, "%s\n", "Initialisation of GLEW : OK");
  }
  return res;
}
