#ifndef DISPLAY_H
#define DISPLAY_H

class Display{
public:
  Display();
  ~Display();

private:
  bool initGlew();
  bool initGlfw();
};

#endif
