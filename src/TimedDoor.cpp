// Copyright 2021 MalininDmitry
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <string>
#include "TimedDoor.h"
using std::this_thread::sleep_for;
using namespace std::chrono_literals;

void TimedDoor::throwState() {
    if (open) {
        throw std::string("the door is opened!");
    } else {
        throw std::string("the door is closed!");
    }
}

DoorTimeAdapter::DoorTimeAdapter(TimedDoor * door) {
    this->door = door;
}

void DoorTimeAdapter::Timeout() {
    this->door->DoorTimeOut();
}

Timer::Timer(DoorTimeAdapter * doorAdapter) {
    this->doorAdapter = doorAdapter;
}

void Timer::calcTime() {
    sleep_for(std::chrono::seconds(this->doorAdapter->door->time));
    if (this->doorAdapter->door->open)
        this->doorAdapter->Timeout();
}

TimedDoor::TimedDoor(int time) {
    this->time = time;
    this->Adapter = new DoorTimeAdapter(this);
}

void TimedDoor::DoorTimeOut() {
    if (open)
        throw std::string("close the door!");
}

void TimedDoor::lock() {
    this->open = false;
}
void TimedDoor::unlock() {
    this->open = true;
    Timer tm(Adapter);
    tm.calcTime();
}
