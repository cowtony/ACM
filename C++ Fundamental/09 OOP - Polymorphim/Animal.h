#pragma once

#include <iostream>

class Animal {
public:
    virtual void animalSound() const = 0;
    // virtual void animalWalk(int minute) = 0;
private:
    int weight;
    int distance = 0;
};


/*
class IO {
public:
    // ??? describe how to use
    void send_data(int data) = 0;
    int recv_data() = 0;
};


class NetIO: public IO {
    NetIO() {
        // create network socket

    }

};

class KafkaMQ : public IO {

};


class AWS_KinesisIO : public IO {
    void send_data(int data) {
    }
    int recv_data() {

    }
};
*/

class Shape {
public:
    virtual double getCircumesfence() = 0;
    virtual double getArea() = 0;
};





