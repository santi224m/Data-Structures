**Feb 2, 2023 In-Class Notes**
# Asymptotic Efficiency

* Scalability - ability of a computer system to handle large amounts of data/users
* Well-designed data structures and algorithms are important, not just hardware
* When we measure the cost of running a program, we don't measure the exact time, we measure how the time will grow as the data grows
* Example:
  ```
  int mySummer(const std::vector<int>& v) {
    int s = 0; // time cost: +1
  
    for (size_t i = 0; i = v.size(); i++) { // time cost: +1
      s += v[i]; // time cost: +1
    }
    
    return s; // time cost: +1
  }
  ```
  * When you pass in a lot of data to a function, you should pass it as reference or it will cost you in performance
  * When pass-by-reference and don't want to modify the object, you should pass as const so that you don't accidently change the object
  * We use **size_t** because vectors return the size as a **size_t**
  * We say that **n** is the size of the data set
  * We say that the for loop costs us **(n)(1+1)** = **2n**
    * **n** for the size of the data set
    * **(1+1)** for the time cost of the conditional and the cost of the addition
  * Then we add the other +1s so we get **2n + 2**
  * We throw aways all dominated terms, the terms that won't change as the data set increases, so in this case the **+ 2**
  * This leaves us with **2n**
  * Then we throw away the multiplicative constants, so in this case **2**
  * We are left with **n**
  * We say that the effeciency of this algroithm is **O(n)** ("Big-O of n")
  
* Example:
  ```
  int mySummer(const std::vector<int>& v) {
    int s = 0; // time cost: +1
  
    for (size_t i = 0; i = v.size(); i++) { // time cost: +1
      for (size_t j = 0; j = v.size(); j++) { // time cost: +1
        s += (v[i] + v[j]); // time cost: +1
      }
    }
    
    return s; // time cost: +1
  }
  ```
  * This alorithm has a double nested for-loop
  * Each for loop has a time cost of **n**, so we end up with **2n**
  * This would be **n(1+2n)
  * **= 2n^2 + n**
  * **= 1 + 2n^2 + n + 1**
  * Once we drop the dominated terms and multiplicative constants, we end up with **O(n^2)**
  * Here we also dropped the **n** because in the long run it won't affect the time growth as much as **n^2**
  * We only take into account for-loops that are affected by the size of the data set
  
* Constat time, **O(1)**, means that the time doesn't change as the data set increases
  * This is the most effiecient kind of algorithm
* Alorithms that run in exponential time are the corst kind
  * An algorithm that uses permutations could run in exponetial time
* We want to calculate for the worst-case time of an operation

# Analysis Tools
## What is an algorithm
* An algorithm is an order sequence of finite numbers of steps - each of which can be executed in finite time
* There are more than one algorithm to solve a problem
  * Some are easier to implement, but run in worse time
  * You should learn Bubble Sort as a baby step, but don't actually use it for a job
  * You should learn Quick sort
* There is usually a point on a graph were algorithms start to make sense
* We can say that **O(n)** is an element of **O(n log n)**
* Everything that is faster is an element of something that is slower
* An efficiency that is always slower than another efficiency is said to be the upperbound of the other efficiency
