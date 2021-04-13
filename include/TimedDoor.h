// Copyright 2021 MalininDmitry

#ifndef INCLUDE_TIMEDOOR_H_
#define INCLUDE_TIMEDOOR_H_

class TimedDoor;

class DoorTimeAdapter {
public:
    TimedDoor * door = nullptr;
    explicit DoorTimeAdapter(TimedDoor * door);
    void Timeout();
};

class Timer {
 public:
    explicit Timer(DoorTimeAdapter * doorAdapter);
    DoorTimeAdapter * doorAdapter = nullptr;
    void calcTime();
};

class TimedDoor {
 public:
    bool open = false;
    void DoorTimeOut();
    explicit TimedDoor();
    void OpentheDoor(DoorTimeAdapter * dr);
    void ClosetheDoor();
    void throwState();
};


const size_t timeOpen = 5;

#endif  // INCLUDE_TIMEDOOR_H_
