#include <iostream>
#include "Animal.h"
#include "factory.h"
#include <memory>

using namespace std;

int main(int argc, char* argv[]) {
    cout << "Type your animal type:" << endl;
    string type;
    cin >> type;

    shared_ptr<Animal> animal = createAnimal(type);
    if (animal) {
        animal->animalSound();
    } else {
        cout << "INVALID TYPE!" << endl;
    }

    /*
    IO* io = factoryCreate("???");

    // Complicate Algorithm
    int a = 5;
    io->send_data(a);

    // Complicate Algorithm

    int b = io->recv_data();

    // Complicate Algorithm
    */

    return 0;
}

