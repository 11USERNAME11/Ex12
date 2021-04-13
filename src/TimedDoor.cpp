// Copyright 2021 Bogomazov
#include "../include/TimedDoor.h"

bool TimedDoor::isDoorOpened() {
    return opened;
}

int TimedDoor::getITimeout() {
    return iTimeout;
}

void DoorTimerAdapter::Timeout() {
    Timer t = Timer();
    t.tregister(door.getITimeout(), this);
}

void TimedDoor::unlock() {
    adapter->Timeout();
    opened = true;
}

TimedDoor::TimedDoor(int time) {
    iTimeout = time;
}
