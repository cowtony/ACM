Compile time Polymorphim:
```C++
// Base class
class Animal {
  public:
    void animalSound() {
      cout << "The animal makes a sound \n";
    }
};

// Derived class
class Pig : public Animal {
  public:
    void animalSound() {
      cout << "The pig says: wee wee \n";
    }
};

// Derived class
class Dog : public Animal {
  public:
    void animalSound() {
      cout << "The dog says: bow wow \n";
    }
};

int main() {
  Animal myAnimal;
  Pig myPig;
  Dog myDog;

  myAnimal.animalSound();
  myPig.animalSound();
  myDog.animalSound();
  return 0;
}
```


- Compile time polymorphim
- Run time polymorphim

# Assignment
Implement the following classes and write a main function to test:
```C++
class Shape {
public:
    double getCircumference() const = 0;
    double getArea() const = 0;
    void enlargeSize(double factor) = 0;
};

class Circle : public Shape {
// Your implementation
};

class Rectangle : public Shape {
// Your implementation
};

class Square : public Rectangle {
// Your implementation
};
```