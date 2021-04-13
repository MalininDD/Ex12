// Copyright 2021 MalininDmitry

#include <iostream>
#include "TimedDoor.h"

int main() {
    TimedDoor door;
    DoorTimeAdapter doorAdapter(&door);
    try {
        door.OpentheDoor(&doorAdapter);
        door.throwState();
    } catch(std::string message) {
        std::cout << message << std::endl;
    }
    return 0;
}
