// Copyright 2021 Bogomazov
#include <iostream>
#include "../include/TimedDoor.h"

int main() {
  TimedDoor door(10);
  try {
    door.lock();
    door.throwState();
  }
  catch(std::string e) {
    std::cout << e << std::endl;
  }

  return 0;
}
