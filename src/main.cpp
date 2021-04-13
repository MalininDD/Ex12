// Copyright 2021 MalininDmitry

#include <iostream>
#include "TimedDoor.h"

int main() {
    TimedDoor door(1);
    try {
        door.unlock();
        door.throwState();
    } catch(std::string message) {
        std::cout << message << std::endl;
    }
    return 0;
}
