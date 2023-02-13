# ArrayQueue: An Array-Based Queue

* In this section we will implement a FIFO queue
  * Elements are removed from the queue in the same order they are added
  * We use the ```remove()``` and ```add(x)``` operations
* An ArrayStack does not make for a good implementation of a FIFO queue
  * If we did use an ArrayStack, we would have to set ```i = 0``` for ```add(i,x)``` and ```remove(i)``` each time we would need to add or remove an element
  * An Array Stack would have a running time proportional to ```n```
* An ArrayQueue uses *modular arithmetic*
* Modular arithmetic is useful for simulating an infinite array because ```i % a.length``` is always in the range ```0,...,a.length-1```
* The reason that we need to simulate an infinite array is the following:
  * If we had an infinite array, implementing the ArrayStack would be much easier and we would implement it as follows:
  * The queue elements would be stored like this: ```a[j], a[j + 1],...,a[j + n - 1]```
    * Here, ```a``` is an infinite array
    * ```j``` is an index that keeps track of the next element to remove
    * ```n``` counts the number of elements in the queue
    * Everytime there is an element added to the stack, it would be assigned the index after the last element that was added. No index would ever be reused
    * When we have to remove an element, we would remove ```a[j]``` and then increment ```j``` by 1 so that the next element can be removed when we need it to be
* There is no such thing as an infinite array, so we have to use modular arithmetic to implement the ArrayStack in this way
* Using modular arithmetic, we would store the elements in the queue like this:
  ```
  a[j % a.length], a[(j + 1) % a.length],...,a[(j + n - 1) % a.length]
  ```
* This treats the array like a circular array, where indices that are larger than the length of the array are wrapped around to the beginning of the array
* We need to be careful that the amount of elements stored in the array do not exceed the length of the array
```cpp
Array<T> a;
int j;  // index of next element to remove
int n;  // tracks number of elements in the queue
```
