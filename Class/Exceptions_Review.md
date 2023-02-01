# Exceptions Review

* Exceptions are used to catch errors.
* You should throw an exception when there is an error

# Classes

* When you make a class, make everything private except if it must be public
* it's best to have one file for the interface and one for the implementation - this can reduce compile time in large programs
* you can use this-> notation to interact with member variables
* You should design a copy constructor and copy operator so that you know what is going on under the hood.
* Not designing the copy constructor could result in the following problems:
  * Pointers get copied, so if you change one object, it changes the other
  * Could lead to memory leaks
* You can implement a comparison operator by defining the operator== operator
* Avoid duplicating uneccesary code
  
  ```
  // Bullet.hpp
  class Bullet {
    public:
      Bullet();
      ~Bullet(); // Destructor
      void setVelocity(double x, double y, double z);
      const Bullet& operator=(const Bullet& other);
      bool operator==(const Bullet& other);
      // When you implemnt this code, just return the opposite of operator!=
      bool operator!=(const Bullet& other);
    private:
      double x_, y_, z_;
      const Bullet& copyOther(const Bullet& other);
  };
  
  // Bullet.cpp
  Bullet::Bullet() {
    this->setVelocity(0.0, 0.0, 0.0);
  Bullet(double x, doube y, double z) {
  this->setVelocity(x, y, z);
  void Bullet::setVelocity(double x, double y, double z) {
    this->x_ = x;
    this->y_ = y;
    this->z_ = z;
  }
  
  // main.cpp
  int main() {
    Bullet b1;
    Bullet b2(3.3, 4.4, 5.5);
    b1 = b2;
  }
  
# Pointers

* Pointers point to a an address in memory

int a = 5;
int* p;

p = &a;

cout << a; // 5
cout << (*p); // 5
cout << p; // memory location

a++ // sets a to 6
(*p)++; // sets a to 7
```

* You should use paranthesis when dereferencing a pointer like in the code below
* You have to use the delete keyword to deallocate pointers to avoid memory leaks

```
int * a;

a = new int;

cout << a; // mem loc
cout << (*a); // some number

delete a;
a = nullptr; // helps debug if you try to use a once it has been deallocated

cout << (*a); // error: a was deallocated
```
