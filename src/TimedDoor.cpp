// Copyright 2021 MalininDmitry
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "TimedDoor.h"
using std::this_thread::sleep_for;
using namespace std::chrono_literals;

void TimedDoor::throwState() {
    if (open) {
        throw std::string{"the door is opened!"};
    } else {
        throw std::string{"the door is closed!"};
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
    this->calcTime();
}

void Timer::calcTime() {
    sleep_for(std::chrono::seconds(timeOpen));
    if (this->doorAdapter->door->open)
        this->doorAdapter->Timeout();
}

TimedDoor::TimedDoor() {
    
}

void TimedDoor::DoorTimeOut() {
    throw std::string("close the door!");
}

void TimedDoor::OpentheDoor(DoorTimeAdapter * dr) {
    this->open = true;
    Timer tm(dr);
}
void TimedDoor::ClosetheDoor() {
    this->open = false;
}
