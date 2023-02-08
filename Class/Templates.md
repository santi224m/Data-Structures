## In-Class Notes Feb 7, 2023

# Templates
Bein Slideshow - 3_Review_Exceptions_Classes_Templates

* templates help us to avoid rewriting the same class for different data types
```
template<class T>  // T can be anything
class MyClass
{
  public:
    void setValue(T v) {
      this->value_ = v;
    }
    T getValue() {
      return this->value_;
    }
   
  private:
    T value_;
    double someOtherValue; // data types that don't need to be changed can be hard coded
};

// main.cpp
int main() {
  MyClass<int> mc1;
  MyClass<double> mc2;
  MyClass<MyOtherCustomClass> mc3;
}
```
* The compiler will compile each **MyClass** with the data type hard coded

```
std::vector<int> v1;

for ( int i = 0; i < v1.size(); ++i) {
  std::cout << v1[i] << std::endl;
}
```
* The above code will give a warning because you are mixing data types
  * i is an **int**, max 2 * 10^9
  * v1.size() returns a **size_t**, max 2 * 10^19
  
```
1011011 == [0,255] (256 combos) unsigned
1 011011 == [0, 127] (128 combos) signed
// the first bit is used to determine whether number is positive or negative
// using a signed type reduces options by half, so c++ uses unsigned type for vectors size

```

# static keyword
* you should avoid global variables
```
int mySummer(const std::vector<int>& v) {  // pass-by-reference for efficiency
  static int counter = 0;
  counter++;
  int sum = 0;
  
  for (size_t i = 0; i < v.size(); ++i) {
    sum += v[i];  
  }
  
  return sum;
}

// main.cpp
int main() {
  std::vector<int> v = {1, 2, 3};
  
  mySummer(v);
}
```
* When you use pass-by-reference and don't have to modify the variable you should pass it in as a constant ```int mySummer(const std::vector<int>& v)```
* When you use a *static* variable, its value stays even after the function is done running

```
class MyClass {
  public:
    const int DEFAULT_SOMETHING = 128764;
  private:
};

// main.cpp
int main() {
  MyClass mc1;
  MyClass mc2;
  MyClass mc3;
}
```
* This code wastes memory because each time you create a MyClass variable, you create a new int variable ```const int DEFAULT_SOMETHING = 128764;```
* If you change it to ```static const int DEFAULT_SOMETHING = 128764;```, then the variable is only created once and shared by all the objects
* You should make variables static if they don't need the functionality of a regular variable
```
class MyClass {
  public:
    static const int DEFAULT_SOMETHING = 128764;
  private:
    int val;
};

// main.cpp
int main() {
  std::cout << "The defualt value is: " << MyClass::DEFAULT_SOMETHING << std::endl;
  
  std::cout << "The val value is: " << MyClass::val << std::endl;  // this would not work
}
```

#### More notes on pointers
```
int *a;
a = new int[1000];

a[40];
a[99];

for (size_t i = 0; i < 1000; ++i) {
  std::cout << a[i] << std::endl;  // prints element's value
  
  std::cout << &a[i] << std::endl; // prints element's memory addresss
}

delete [] a;  // deallocates array from memory
a = nullptr;
```
* Arrays can be faster than vectors, since a vector is a class
* With vectors you don't need to delete it, it is deallocated in its destructor
