#include <main.hpp>

#include <Display.hpp>

#include <cstdio>

int main(int argc, char const *argv[]) {
  fprintf(stdout, "%s\n", "Hello world !!");

  Display display;
  display.loop();

  return 0;
}
