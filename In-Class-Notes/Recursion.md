## In-Class Notes Mar 2, 2023

# Recursion

* **Recursive Function** - Function that calls itself
  * Base Cae - Function does not call itself; Returns something
  * Recursive Case - Function calls itself
  
  ```cpp
  int myPower(int number, int power) {
    // Base Case
    if (power == 0) {
      return 1;
    }
    
    // Recursive Case
    return 2 * myPower(number, power - 1);
  }
  ```
