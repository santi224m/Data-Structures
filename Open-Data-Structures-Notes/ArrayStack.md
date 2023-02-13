# ArrayStack: Fast Stack Operations Using an Array

* An ArrayStack implements the list interface using an array ```a```
* the element with index ```i``` is stored at ```a[i]```
* ```a``` is usually larger than the elements it is storing, so we use ```n``` to keep track of the amount of elements in the array
* Elements are stored in ```a[0]...a[n-1]```
* ```a.length``` is always greater than or equal to ```n```

```cpp
Array<T> a;
int n;  // keeps track of amount of elements in array
int size() {
  return n;
}
```

## The Basics

* Accessing and modifying the elements of the array is easy
* We simply change the value of ```a[i]```
* We should do some bounds-checking before applying any changes

```cpp
// get function
T get(int i) {
  return a[i];
}
// set function
T set(int i, T x) {
  T y = a[i];  // we want to return current value of a[i]
  a[i] = x;
  return y;
}
```

* For the ```add(i,x)``` function, we have to check that the array has enough space for the new element
  * check if ```n``` is equal to the array length
  * If the array is full, we must use the ```resize()``` function to increase its capacity
* After making sure that there is enough space in the array for the element, we have to shift all the elements from ```a[i]...a[n-1]``` to the right by one position, set ```a[i]``` equal to the new element, and increase ```n``` by 1

```cpp
void add(int i, T x) {
  if (n + 1 > a.length) resize();
  for (int j = n; j > i; j--) {  // shift elements to the right
    a[j] = a[j - 1];
  }
  a[i] = x;
  n++;
}
```
* The cost of running the above operation is proportional to the amount of elements we have to shift
  * We are not taking into consideration the potential cost of running the ```resize()``` function
* This operation has a running time of **O(n-i)**
* For the ```remove(i)``` function, we shift the elements ```a[i+1]...a[n-1]``` one position to the left, overwriting the element that we are removing
* We have to decrease the value of ```n``` by 1
* We also check if our value of ```n``` is a lot smaller than the length of the array, and if it is we run the ```resize()``` function to shrink the array
* Finally, we return the value of the element we removed
```cpp
T remove(int i) {
  T x = a[i];  // we will return the value of the element we remove
  for (int j = i; j < n - 1; ++j) {  // shift elements 1 position to the left
    a[j] = a[j + 1];
  }
  n--;
  if (a.length >= 3 * n) resize();  // resize if elements stored is a lot smaller
                                    // than array length
  return x;
}
```
* The cost of running this operation is the same as running the ```add(i, x)``` operation
  * The running time is proportional to the amount of elements we shift
  * The running time is **O(n-i)**
  
## Growing and Shrinking

* Here is what the ```resize()``` function does
  * It allocates a new array ```b``` with a size of ```2n```
  * It copies the first ```n``` elements in ```a``` to ```b```, which is all the elements
  * It sets ```a``` equal to ```b```
* After running the ```resize()``` function on ```a```, its size is ```2n```

```cpp
void resize() {
  array<T> b(std::max(2 * n, 1));
  for (int i = 0; i < n; ++i) {
    b[i] = a[i];
  }
  a = b;
}
```

* The cost of running the above operation is **O(n)**
* We analyze the cost of ```resize()``` using *amortized analysis*
  * This means that we don't calculate the cost of ```resize()``` every time that the ```add(i,x)``` and ```remove(i)``` functions are called, instead we calculate the total cost of ```resize()``` over a sequence of ```m``` calls to ```add(i,x)``` and ```remove(i)```
  * We do this because ```resize()``` isn't called everytime the ```add(i,x)``` and ```remove(i)``` functions are called
  
## Summary
* An **ArrayStack** implements the **List** interface
* Ignoring the cost of ```resize()```:
  * ```get(i)``` and ```set(i,x)``` run in **O(1)**
  * ```add(i,x)``` and ```remove(i)``` run in **O(1+n-i)**
* Beginning with an empty ArrayStack and and performing a sequence of ```m``` ```add(i,x)``` and ```remove(i)``` operations results in a running time of **O(m)** for all calls to ```resize()```
* The ArrayStack is an efficient way to implement a Stack
* We can implement ```push(x)``` as ```add(n,x)```
* We can implement ```pop()``` as ```remove(n-1)```
* Both these functions will run in **O(1)** amortized time

# FastArrayStack: An Optimized ArrayStack

* Arrays shift elements everytime we run the ```add(i,x)``` and ```remove(i)``` functions, and copy elements every time we run the ```resize()``` function
* Many programming languages have efficient functions for doing these operations
  * It is more efficient to use these functions than it is to use for loops
  * In c++ there is the ```std::copy(a0,a1,b)``` algorithm
* The ```resize()``` function optimized to use ```std::copy(a0,a1,b)```:
  * Here the ```std::copy(a+0, a+n, b+0)``` function copies all the elements ```a[0]...a[n]``` to ```b``` starting at ```b[0]```
```cpp
void resize() {
  array<T> b(std::max(2 * n, 1));
  std::copy(a+0, a+n, b+0);
  a = b;
}
```
* The ```add(i,x)``` function optimized to use ```std::copy_backward(a0, a1, a2)```:
  * Here ```std::copy_backward(a+i, a+n, a+n+1)``` copys ```a[i]...a[n]``` to ```a[i+1]...a[n+1]```, effectively shifting the elements one position to the right
```cpp
void add(int i, T x) {
  if (n + 1 > a.length) resize();
  std::copy_backward(a+i, a+n, a+n+1);
  a[i] = x;
  n++;
}
```
* These funtions are highly optimized and using them is more efficient than using a for loop
* Using these function doesn't change the running times, but it's still a good optimization
