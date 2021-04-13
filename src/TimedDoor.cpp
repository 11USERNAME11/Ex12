// Copyright 2021 Bogomazov
#include "../include/TimedDoor.h"
#include <ctime>
#include <string>

TimedDoor::TimedDoor(int timeout) {
    iTimeout = timeout;
    opened = false;
    adapter = new DoorTimerAdapter(*this);
}

int TimedDoor::getTime() {
    return iTimeout;
}

bool TimedDoor::isDoorOpened() {
    return opened;
}

void TimedDoor::unlock() {
    adapter->Timeout();
    opened = true;
}

void TimedDoor::lock() {
    opened = false;
}

void TimedDoor::DoorTimeOut() {
    throw std::string("close the door!");
}

void TimedDoor::throwState() {
  if (opened) {
    throw std::string("the door is opened!");
  } else {
    throw std::string("the door is closed!");
  }
}

void DoorTimerAdapter::Timeout() {
    Timer t;
    t.tregister(door.getTime(), this);
    door.DoorTimeOut();
}

void Timer::sleep(int delay) {
    time_t startTime = time(NULL);
    while (time(NULL) - startTime < delay)
        continue;
}

void Timer::tregister(int delay, TimerClient* tmcl) {
    sleep(delay);
}
