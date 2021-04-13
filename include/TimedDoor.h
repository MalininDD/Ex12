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
    DoorTimeAdapter * doorAdapter;
    void calcTime();
};

class TimedDoor {
 public:
    int time = 0;
    DoorTimeAdapter * Adapter;
    bool open = false;
    void DoorTimeOut();
    explicit TimedDoor(int time);
    void lock();
    void unlock();
    void throwState();
};


#endif  // INCLUDE_TIMEDOOR_H_
